/*
* Project AmbientLight
* Description:
* Author: Lutz Linke
* Date: 2018/02/14
*/
#include <Arduino.h>

// **************************************************
// *** Compiler Flags
// **************************************************
// --- DEBUG ----------------------------------------
//#define ENABLE_SERIAL_DEBUG
//#define DEBUG_LOOP
// --- Demo --------- -------------------------------
#define PLAY_DEMO true
// --- FX/Colors ------------------------------------
//#define ENABLE_RANDOM_COL
//#define DO_NOT_START_FX_ON_INIT

// **************************************************

// **************************************************
// *** Includes
// **************************************************
#include "SerialDebug.h"
//#include <ArduinoSTL.h>
#include <vector>
#include <map>
#include <string.h>

#include "FastLedInclude.h"
#include "ColorPalettes.h"
#include "NeoGroup.cpp"

#include <ESP8266WiFi.h>	  //ESP8266 Core WiFi Library (you most likely already have this in your sketch)
#include <DNSServer.h>		  //Local DNS Server used for redirecting all requests to the configuration portal
#include <ESP8266WebServer.h> //Local WebServer used to serve the configuration portal
#include <WiFiManager.h>	  //https://github.com/tzapu/WiFiManager WiFi Configuration Magic
#include <ESP8266mDNS.h>

// **************************************************
// *** Blynk
// **************************************************
#define BLYNK_PRINT Serial
#define BLYNK_MAX_SENDBYTES 1024 // Default is 128
#include <BlynkSimpleEsp8266.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "eb5f226404904fefb522f6c3b5f60fa2";

// **************************************************
// *** Variable and Constamts  Declarations
// **************************************************
const String wifiApName = "AmbiLightESP";
const String wifiDnsName = "AmbiLightESP";
const int ConfigureAPTimeout = 300;

volatile uint8_t globalBrightness = 128;

const std::vector<int> groupSizes = {PIXEL_COUNT};
volatile int activeGrpNr = 0;

// Static size
struct CRGB leds[PIXEL_COUNT];
// Dynamic size:
//struct CRGB *leds = NULL;
bool ledsInitialized = false;
bool ledsStarted = false;
// 1: Wave, 2: Dynamic Wave, 3: Noise, 4: Confetti, 5: Fade, 6: Comet, 7: Orbit, 8: Fill
const uint8_t fxNrWave = 1;
const uint8_t fxNrDynamicWave = 2;
const uint8_t fxNrNoise = 3;
const uint8_t fxNrConfetti = 4;
const uint8_t fxNrFade = 5;
const uint8_t fxNrComet = 6;
const uint8_t fxNrOrbit = 7;
const uint8_t fxNrFill = 8;
const int maxFxNr = 7;
const int defaultFxNr = fxNrWave;
std::vector<int> currFxNr;
int maxColNr = 1;			// will be dynamically assigned once palettes are generated
const int defaultColNr = 2; // "Analogous"
std::vector<int> currColNr;
const int defaultFps = 50; //25;
std::vector<int> currFps;
const int defaultGlitter = 0; //32;
std::vector<int> currGlitter;
uint8_t currentHue = HUE_AQUA;
uint8_t currentSat = 255;

//std::vector<NeoGroup *> neoGroups;
std::vector<NeoGroup> neoGroups;

// **************************************************
// *** Helper methods
// **************************************************
#pragma region Helper Methods
void registerMDns()
{

	if (!MDNS.begin(wifiDnsName.c_str()))
	{
		DEBUG_PRINTLN("mDNS: Error setting up MDNS responder!");
	}
	else
	{
		DEBUG_PRINTLN("mDNS: responder started");
	}
}

bool InitWifi(bool useWifiCfgTimeout = true, bool forceReconnect = false)
{
	DEBUG_PRINTLN("WIFI ------------------------------------------------------");

	DEBUG_PRINTLN("WiFi: setting host name to '" + wifiDnsName + "'...");
	WiFi.hostname(wifiDnsName.c_str());

	if (!forceReconnect && WiFi.status() == WL_CONNECTED)
	{
		registerMDns();
		DEBUG_PRINTLN("WiFi: device '" + WiFi.hostname() + "' already connected...");
		return true; // Is already connected...
	}

	if (ledsInitialized)
	{
		FastLED.clear(true);
		fill_solid(leds, PIXEL_COUNT, CRGB::Blue);
		FastLED.show();
	}
	delay(2500);
	//WiFiManager
	WiFiManager wifiManager;
	if (forceReconnect)
	{
		wifiManager.resetSettings();
	}
	//wifiManager.setAPStaticIPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));
	//fetches ssid and pass from eeprom and tries to connect
	//if it does not connect it starts an access point with the specified name
	//here  "AutoConnectAP" and goes into a blocking loop awaiting configuration
	DEBUG_PRINTLN("WiFi Manager trying to connect...");
	if (useWifiCfgTimeout)
	{
		DEBUG_PRINTLN("You have " + String(ConfigureAPTimeout) + " seconds for configuration if required.");
		wifiManager.setConfigPortalTimeout(ConfigureAPTimeout);
	}
	bool connected = wifiManager.autoConnect(wifiApName.c_str());
	//or use this for auto generated name ESP + ChipID
	//wifiManager.autoConnect();
	//if you get here you have connected to the WiFi

	registerMDns();

	if (ledsInitialized)
	{
		fill_solid(leds, PIXEL_COUNT, connected ? CRGB::Green : CRGB::Red);
		FastLED.show();
	}
	if (connected)
	{
		DEBUG_PRINTLN("Wifi is connected for device '" + WiFi.hostname() + "'...yay!!!");
	}
	else
	{
		DEBUG_PRINTLN("!!! WIFI NOT CONNECTED !!!");
	}
	delay(5000);

	return connected;
}

// [FastLED Helper methods]
int initStrip(bool doStart = false, bool playDemo = true)
{
	if (ledsInitialized)
	{
		return doStart ? startStrip() : PIXEL_COUNT;
	}

	DEBUG_PRINTLN("LEDStrip --------------------------------------------------");
	/*	
	DEBUG_PRINTLN("Allocating memory for LED strip data.");
	leds = (struct CRGB *)malloc(PIXEL_COUNT * sizeof(struct CRGB));
	*/
	DEBUG_PRINTLN("Assigning LEDs to FastLED.");
	FastLED.addLeds<PIXEL_TYPE, PIXEL_PIN>(leds, PIXEL_COUNT);
	//FastLED.setMaxPowerInVoltsAndMilliamps(5,3000);
	FastLED.setBrightness(globalBrightness);
	FastLED.setDither(0);
	FastLED.clear(true);
	FastLED.show();

	ledsInitialized = true;

	if (playDemo)
	{
		DEBUG_PRINT("Playing demo effect...");
		CRGBPalette16 colorPalette = NeoGroup::GenerateRGBPalette(ColorPalettes.find("Regenbogen")->second);
		for (int dot = 0; dot < 256; dot++)
		{
			// Comet effect :-)
			fadeToBlackBy(leds, PIXEL_COUNT, 8);
			int variant = (PIXEL_COUNT / 16);
			int pos = ease8InOutQuad(dot) + random(0 - variant, 0 + variant);
			pos = (pos * PIXEL_COUNT) / 256;
			pos = constrain(pos, 0, PIXEL_COUNT);
			//DEBUG_PRINT("Setting pixel #");
			//DEBUG_PRINTLN(pos);
			int bright = random(64, 255);

			/*
			CRGB color = CHSV(random8(), 255, 255);
			nblend(leds[pos], color, 128);
			*/
			uint8_t colpos = dot + random8(16) - 8;
			nblend(leds[pos], ColorFromPalette(colorPalette, colpos, bright), 128);

			FastLED.show();
			delay(10);
			DEBUG_PRINT(".");
		}
		DEBUG_PRINTLN("DONE");

		DEBUG_PRINTLN("Fading away demo effect.");
		for (int fade = 0; fade < 20; fade++)
		{
			fadeToBlackBy(leds, PIXEL_COUNT, 20);
			FastLED.show();
			delay(50);
		}
		DEBUG_PRINTLN("Clearing LEDs.");
		FastLED.clear(true);
		FastLED.show();
	}

	InitWifi();

	neoGroups.clear();
	// DEBUG_PRINTLN("Adding special groups.");
	// // Group 0: all LEDs
	// addGroup("All LEDs' group", 0, PIXEL_COUNT, 0);
	// activeGrpNr = 0;

	DEBUG_PRINTLN("Adding " + String(groupSizes.size()) + " groups.");
	int nextGroupStart = 0;
	for (int i = 0; i < groupSizes.size(); i++)
	{
		String groupName = "Group " + String(i + 1);
		addGroup(groupName, nextGroupStart, groupSizes[i], 0);
		nextGroupStart += groupSizes[i];
	}
	activeGrpNr = 0;

	return doStart ? startStrip() : PIXEL_COUNT;
}

int startStrip()
{
	if (!ledsInitialized)
		return -1;

	ledsStarted = true;
	return PIXEL_COUNT;
}

int stopStrip()
{
	ledsStarted = false;

	for (int i = 2; i < neoGroups.size(); i++)
	{
		NeoGroup *neoGroup = &(neoGroups.at(i));
		neoGroup->Stop(true);
	}

	FastLED.clear(true);
	FastLED.show();

	return 0;
}

int addGroup(String grpId, int ledFirst, int ledCount, int ledOffset)
{
	if ((ledFirst >= PIXEL_COUNT) ||
		(ledCount <= 0) ||
		(ledFirst + ledCount) > PIXEL_COUNT)
		return -((((3 * 1000) + ledFirst) * 1000) + ledCount); // Invalid parameter

	DEBUG_PRINTLN("Adding group '" + String(grpId) + "' at " + String(ledFirst) + " with size " + String(ledCount) + ".");

	// V1: new NeoGroup
	//NeoGroup *newGroup = new NeoGroup(grpId, ledFirst, ledCount, ledOffset);
	//neoGroups.push_back(newGroup);
	// V2: NeoGroup w/o new
	NeoGroup newGroup = NeoGroup(grpId, ledFirst, ledCount, ledOffset);
	neoGroups.push_back(newGroup);

	currFxNr.push_back(defaultFxNr);
	currColNr.push_back(defaultColNr);
	currFps.push_back(defaultFps);
	currGlitter.push_back(defaultGlitter);

	DEBUG_PRINTLN("GroupCount: " + String(neoGroups.size()) + ".");

	return neoGroups.size();
}

bool isGroupActive(int grpNr)
{
	NeoGroup *neoGroup = &(neoGroups.at(grpNr));
	return neoGroup->Active;
}

bool isGroupFadingOut(int grpNr)
{
	NeoGroup *neoGroup = &(neoGroups.at(grpNr));
	return !(neoGroup->Active) && (neoGroup->IsFadingOut());
}

int startGroup(int grpNr, bool runOnlyOnce = false)
{
	DEBUG_PRINTLN("Starting group #" + String(grpNr) + "...");
	NeoGroup *neoGroup = &(neoGroups.at(grpNr));
	neoGroup->Start(runOnlyOnce);

	return grpNr;
}

int stopGroup(int grpNr, bool stopNow = false)
{
	DEBUG_PRINTLN("Stopping group #" + String(grpNr) + "...");
	NeoGroup *neoGroup = &(neoGroups.at(grpNr));
	neoGroup->Stop(stopNow);

	return grpNr;
}

int setGrpEffect(
	int grpNr,
	pattern pattern,
	int amountglitter = -1,
	int fps = 0,
	direction direction = FORWARD,
	mirror mirror = MIRROR0,
	wave wave = LINEAR,
	int speed = 1,
	double fpsFactor = 1.0)
{
	NeoGroup *neoGroup = &(neoGroups.at(grpNr));
	neoGroup->Stop(true);

	//int fxGlitter = amountglitter <= 0 ? neoGroup->GetGlitter() : amountglitter;
	int fxGlitter = amountglitter <= 0 ? currGlitter.at(grpNr) : amountglitter;
	//int fxFps = fps <= 0 ? neoGroup->GetFps() : fps;
	int fxFps = fps > 0 ? fps : currFps.at(grpNr);

	uint16_t result = neoGroup->ConfigureEffect(pattern, fxGlitter, fxFps, direction, mirror, wave, speed, fpsFactor);
	//neoGroup->Start();

	return result;
}

int setGrpColors(
	int grpNr,
	std::vector<CRGB> colors,
	bool clearFirst = true,
	bool generatePalette = true,
	bool crossFade = false)
{
	NeoGroup *neoGroup = &(neoGroups.at(grpNr));
	//neoGroup->Stop();
	uint16_t result = neoGroup->ConfigureColors(colors, clearFirst, generatePalette, crossFade);
	//neoGroup->Start();

	return result;
}

// [Event handling helper methods]
void StartStopEffect(int grpNr)
{
	NeoGroup *neoGroup = &(neoGroups.at(grpNr));
	DEBUG_PRINTLN("StartStopEffect ---------------------------------------------");
	DEBUG_PRINTLN("Fx: Starting/stopping group #" + String(grpNr) + ": " + String((neoGroup->Active)) + "->" + String(!(neoGroup->Active)) + ".");
	bool stopNow = false;
	if (neoGroup->Active)
		stopGroup(grpNr, stopNow);
	else
		startGroup(grpNr);
}

void SetEffect(int grpNr, int fxNr,
			   bool startFx, bool onlyOnce,
			   direction fxDirection = direction::FORWARD,
			   int amountGlitter = -1,
			   int targetFps = 0,
			   int speed = 1)
{
	DEBUG_PRINTLN("SetEffect ---------------------------------------------------");
	DEBUG_PRINTLN("Fx: Configuring LED effect #" + String(fxNr) + " for group #" + String(grpNr) + ".");

	if (fxNr == 0)
	{
		DEBUG_PRINTLN("Fx: Choosing random effect.");
		SetEffect(grpNr, random8(1, maxFxNr), startFx, onlyOnce);
		return;
	}

	String fxPatternName = "";
	pattern fxPattern = pattern::STATIC;
	int fxGlitter = currGlitter.at(grpNr);
	int fxFps = currFps.at(grpNr);
	double fxFpsFactor = 1.0;
	mirror fxMirror = MIRROR0;
	wave fxWave = wave::LINEAR;
	int fxSpeed = speed;

	NeoGroup *neoGroup = &(neoGroups.at(grpNr));
	switch (fxNr)
	{
	case fxNrWave:
		fxPatternName = "Wave";
		fxPattern = pattern::WAVE;
		fxDirection = direction::REVERSE;
		fxMirror = mirror::MIRROR1;
		fxFpsFactor = 0.5; // half FPS looks better
		break;
	case fxNrDynamicWave:
		fxPatternName = "Dynamic Wave";
		fxPattern = pattern::DYNAMICWAVE;
		fxMirror = mirror::MIRROR1; // mirror::MIRROR0;
		// fxFpsFactor = 0.5; // half FPS looks better
		break;
	case fxNrNoise:
		fxPatternName = "Noise";
		fxPattern = pattern::NOISE;
		fxMirror = mirror::MIRROR1; // mirror::MIRROR0;
		// fxFps *= 2; // double FPS looks better
		fxFpsFactor = 2.0; // double FPS looks better
		break;
	case fxNrConfetti:
		fxPatternName = "Confetti";
		fxPattern = pattern::CONFETTI;
		fxGlitter = 0;
		// fxFps /= 2; // half FPS looks better
		// fxFpsFactor = 0.5; // half FPS looks better
		break;
	case fxNrFade:
		fxPatternName = "Fade";
		fxPattern = pattern::FADE;
		// fxFps /= 2; // half FPS looks better
		fxFpsFactor = 0.5; // half FPS looks better
		break;
	case fxNrComet:
		fxPatternName = "Comet";
		fxPattern = pattern::COMET;
		fxWave = wave::EASEINOUT;
		// fxWave = wave::SINUS;
		// fxFps *= 3; //1.5; // faster FPS looks better
		// fxFpsFactor = 1.5; // faster FPS looks better
		fxMirror = mirror::MIRROR1;
		break;
	case fxNrOrbit:
		fxPatternName = "Orbit";
		fxPattern = pattern::COMET;
		// fxWave = wave::EASEINOUT;
		fxWave = wave::SINUS;
		// fxFps *= 1.5; // faster FPS looks better
		// fxFpsFactor = 1.5; // faster FPS looks better
		fxFpsFactor = 0.5; // half FPS looks better
		fxMirror = mirror::MIRROR0;
		// fxMirror = mirror::MIRROR1;
		break;
	case fxNrFill:
		fxPatternName = "Fill";
		fxPattern = pattern::FILL;
		fxWave = wave::EASEINOUT;
		// fxFps *= 1.5; // faster FPS looks better
		fxFpsFactor = 1.5; // faster FPS looks better
		fxFpsFactor = 0.5; // half FPS looks better
		// fxMirror = mirror::MIRROR0;
		fxMirror = mirror::MIRROR2;
		break;
	default:
		fxPatternName = "Static";
		fxPattern = pattern::STATIC;
		fxMirror = mirror::MIRROR0;
		break;
	}
	if (targetFps > 0)
		fxFps = targetFps;
	DEBUG_PRINTLN("Fx: Changing effect to '" + String(fxPatternName) + "'.");
	setGrpEffect(
		grpNr,
		fxPattern,
		fxGlitter,
		fxFps,
		fxDirection,
		fxMirror,
		fxWave,
		fxSpeed,
		fxFpsFactor);
	if (startFx)
		startGroup(grpNr, onlyOnce);
	DEBUG_PRINTLN("SetEffect ---------------------------------------------------");
}

void InitColorNames()
{
	InitColorPalettes();
	/*
	for (std::map<String, std::vector<CRGB>>::const_iterator it = ColorPalettes.begin(); it != ColorPalettes.end(); ++it)
	{
		String key = it->first;
		ColorNames.push_back(key);
	}
	*/
}

void SetColors(int grpNr, int colNr)
{
	DEBUG_PRINTLN("SetColors --------------------------------------------------");
	DEBUG_PRINTLN("Col: Configuring LED colors #" + String(colNr) + " for group #" + String(grpNr) + ".");

	if (colNr == 0)
	{
		DEBUG_PRINTLN("Col: Choosing random color palette.");
		SetColors(grpNr, random8(1, maxColNr));
		return;
	}

	String palKey = ColorNames[colNr - 1];
	DEBUG_PRINTLN("Col: Changing color palette to '" + palKey + "'.");
	if (ColorPalettes.find(palKey) != ColorPalettes.end())
	{
		std::vector<CRGB> colors = ColorPalettes.find(palKey)->second;
		if (colors == (std::vector<CRGB>)NULL)
		{
			DEBUG_PRINTLN("Col: Generating colours for hue " + String(currentHue) + ", sat " + String(currentSat) + " using method '" + palKey + "'.");
			colors = GeneratePaletteFromHue(palKey, currentHue, currentSat);
		}
		setGrpColors(grpNr, colors, true, true, CROSSFADE_PALETTES);
	}
}

void NextEffect(int nextFx = -1)
{
	if (nextFx < 0)
	{
		(currFxNr.at(activeGrpNr))++;
	}
	else
	{
		currFxNr.at(activeGrpNr) = nextFx;
	}
	if (currFxNr.at(activeGrpNr) > maxFxNr)
	{
		currFxNr.at(activeGrpNr) = 1;
	}
	DEBUG_PRINTLN("CONTROL: Changing effect number to: " + String(currFxNr.at(activeGrpNr)) + ".");
	SetEffect(activeGrpNr, currFxNr.at(activeGrpNr), true, false);
}

void NextColor(int nextCol = -1)
{
	if (nextCol < 0)
	{
		(currColNr.at(activeGrpNr))++;
	}
	else
	{
		currColNr.at(activeGrpNr) = nextCol;
	}
	if (currColNr.at(activeGrpNr) > maxColNr)
	{
		currColNr.at(activeGrpNr) = 1;
	}
	DEBUG_PRINTLN("CONTROL: Changing color number to: " + String(currColNr.at(activeGrpNr)) + ".");
	SetColors(activeGrpNr, currColNr.at(activeGrpNr));
}
#pragma endregion

// **************************************************
// *** BLYNK
// **************************************************
#pragma region Application Setup
// V0 In/Off
BLYNK_WRITE(V0)
{
	int pinValue = param.asInt();
	DEBUG_PRINTLN("BLYNK V0: grp#" + String(activeGrpNr) + ", on/off => " + String(pinValue));
	if (pinValue == 0)
	{
		stopGroup(activeGrpNr, false); // no immediate stop, fade out
	}
	else
	{
		startGroup(activeGrpNr, false); // no runOnlyOnce
	}
}

// V1 Brightness
BLYNK_WRITE(V1)
{
	int pinValue = param.asInt();
	pinValue = constrain(pinValue * 16, 16, 255);
	DEBUG_PRINTLN("BLYNK V1: grp#" + String(activeGrpNr) + ", brightness => " + String(pinValue));

	globalBrightness = pinValue;
	FastLED.setBrightness(globalBrightness);
}

// V2 FPS
BLYNK_WRITE(V2)
{
	int pinValue = param.asInt();
	pinValue = constrain(pinValue * 5, 10, 100);
	DEBUG_PRINTLN("BLYNK V2: grp#" + String(activeGrpNr) + ", FPS => " + String(pinValue));

	currFps.at(activeGrpNr) = pinValue;
	NeoGroup *neoGroup = &(neoGroups.at(activeGrpNr));
	neoGroup->ChangeFps(currFps.at(activeGrpNr));
}

// V3 Effect DropDown
BLYNK_WRITE(V3)
{
	int pinValue = param.asInt();
	pinValue = constrain(pinValue, 1, maxFxNr);
	DEBUG_PRINTLN("BLYNK V3: grp#" + String(activeGrpNr) + ", FX => " + String(pinValue));

	currFxNr.at(activeGrpNr) = pinValue;
	SetEffect(activeGrpNr, currFxNr.at(activeGrpNr), true, false);
}

// V10 Colour Palette DropDown
BLYNK_WRITE(V10)
{
	int pinValue = param.asInt();
	pinValue = constrain(pinValue, 1, ColorNames.size());
	DEBUG_PRINTLN("BLYNK V10: grp#" + String(activeGrpNr) + ", color palette #" + String(pinValue));

	NextColor(pinValue);
}

// V11 Colour next
BLYNK_WRITE(V11)
{
	int pinValue = param.asInt();
	DEBUG_PRINTLN("BLYNK V11: grp#" + String(activeGrpNr) + ", pinValue => " + String(pinValue));

	if (pinValue == 1)
	{
		DEBUG_PRINTLN("BLYNK V11: grp#" + String(activeGrpNr) + ", color => [NEXT]");
		NextColor();
		Blynk.virtualWrite(V10, currColNr.at(activeGrpNr));
	}
}

// V12 Hue
BLYNK_WRITE(V12)
{
	int pinValue = param.asInt();
	pinValue = constrain(pinValue, 0, 255);
	DEBUG_PRINTLN("BLYNK V12: grp#" + String(activeGrpNr) + ", hue => " + String(pinValue));

	currentHue = pinValue;
	SetColors(activeGrpNr, currColNr.at(activeGrpNr));
}

// V13 Saturation
BLYNK_WRITE(V13)
{
	int pinValue = param.asInt();
	pinValue = constrain(pinValue * 16, 0, 255);
	DEBUG_PRINTLN("BLYNK V13: grp#" + String(activeGrpNr) + ", sat => " + String(pinValue));

	currentSat = pinValue;
	SetColors(activeGrpNr, currColNr.at(activeGrpNr));
}

BLYNK_CONNECTED()
{
	DEBUG_PRINTLN("Blynk connected: synchonizing values from cloud");
	Blynk.syncAll();
}

BLYNK_APP_CONNECTED()
{
	DEBUG_PRINTLN("Blynk app connected: updating app with current values");
	SendStatusToBlynkApp();
}

BLYNK_APP_DISCONNECTED()
{
	DEBUG_PRINTLN("Blynk app disconnected");
}

void SendStatusToBlynkApp()
{
	if (WiFi.status() != WL_CONNECTED)
		return;

	DEBUG_PRINTLN("Blynk: sending labels to app");
	BlynkParamAllocated colorNames(BLYNK_MAX_SENDBYTES); // list length, in bytes
	for (int cNr = 0; cNr < ColorNames.size(); cNr++)
	{
		colorNames.add(ColorNames.at(cNr));
	}
	Blynk.setProperty(V10, "labels", colorNames);

	BlynkParamAllocated fxNames(1024); // list length, in bytes
	fxNames.add("Welle");
	fxNames.add("Dynamisch");
	fxNames.add("Rauschen");
	fxNames.add("Konfetti");
	fxNames.add("Blenden");
	fxNames.add("Komet");
	fxNames.add("Orbit");
	Blynk.setProperty(V3, "labels", fxNames);

	DEBUG_PRINTLN("Blynk: sending current values to app");
	NeoGroup *neoGroup = &(neoGroups.at(activeGrpNr));
	Blynk.virtualWrite(V0, neoGroup->Active);
	Blynk.virtualWrite(V1, (uint8_t)((globalBrightness + 1) / 16));
	Blynk.virtualWrite(V2, (uint8_t)(currFps.at(activeGrpNr) / 5));
	Blynk.virtualWrite(V3, currFxNr.at(activeGrpNr));
	Blynk.virtualWrite(V10, currColNr.at(activeGrpNr));
	Blynk.virtualWrite(V12, (uint8_t)currentHue);
	Blynk.virtualWrite(V13, (uint8_t)((currentSat + 1) / 16));
}

void BlynkSetup()
{
	// BlynkParamAllocated colorNames(BLYNK_MAX_SENDBYTES); // list length, in bytes
	// for (int cNr = 0; cNr < ColorNames.size(); cNr++)
	// {
	// 	colorNames.add(ColorNames.at(cNr));
	// }
	// Blynk.setProperty(V10, "labels", colorNames);

	// BlynkParamAllocated fxNames(1024); // list length, in bytes
	// fxNames.add("Welle");
	// fxNames.add("Dynamisch");
	// fxNames.add("Rauschen");
	// fxNames.add("Konfetti");
	// fxNames.add("Blenden");
	// fxNames.add("Komet");
	// fxNames.add("Orbit");
	// Blynk.setProperty(V3, "labels", fxNames);

	// SendStatusToBlynk();
}
#pragma endregion

// **************************************************
// *** Application Setup
// **************************************************
#pragma region Application Setup
void setup()
{
	Serial.begin(115200);

	DEBUG_PRINTLN("BOOT/SETUP ------------------------------------------------");
	DEBUG_PRINTLN("Setup: Setting up AmbientLight for Arduino.");

	//InitWifi();

	DEBUG_PRINTLN("FastLED: Initializing color palettes.");
	InitColorNames();
	maxColNr = ColorNames.size();

	DEBUG_PRINTLN("FastLED: Initializing LED strip.");
	initStrip(true, PLAY_DEMO);
	DEBUG_PRINTLN("FastLED: Amount of LEDs: " + String(PIXEL_COUNT) + ".");

	DEBUG_PRINTLN("FastLED: Starting LED strip.");
	startStrip();

	for (int grpNr = 0; grpNr < groupSizes.size(); grpNr++)
	{
		DEBUG_PRINTLN("FastLED: Setting up and starting group #" + String(grpNr) + ".");
		bool startFx = true;
#ifdef DO_NOT_START_FX_ON_INIT
		startFx = false;
#endif
		int currCol = defaultColNr;
		currColNr[grpNr] = currCol;
		SetColors(grpNr, currCol);

		int currFx = defaultFxNr;
		currFxNr[grpNr] = currFx;
		SetEffect(grpNr, currFx, startFx, false);
		//startGroup(grpNr);
	}
	//activeGrpNr = 0;

	DEBUG_PRINT("FastLED: Active group #" + String(activeGrpNr));

	Blynk.config(auth);
	Blynk.connect();

	BlynkSetup();
}
#pragma endregion

// **************************************************
// *** Application Loop
// **************************************************
#pragma region Application Loop
// Main loop
void loop()
{
	Blynk.run();

	// Evaluate expander pins and execute attached callbacks
	//DEBUG_PRINTLN("LOOP ------------------------------------------------------");

	if (!ledsStarted)
	{
		//DEBUG_PRINTLN("Loop: LEDs not started, leaving loop.");
		return;
	}

	bool ledsUpdated = false;
	for (int grpNr = 0; grpNr < groupSizes.size(); grpNr++)
	{
		NeoGroup *neoGroup = &(neoGroups.at(grpNr));

		if ((neoGroup->LedFirstNr + neoGroup->LedCount) <= PIXEL_COUNT)
		{
			ledsUpdated |= neoGroup->Update();
		}
	}

	if (ledsUpdated)
	{
#ifdef DEBUG_LOOP
		DEBUG_PRINTLN("Loop: Refreshing LEDs.");
#endif
		FastLED.show();
	}
}
#pragma endregion