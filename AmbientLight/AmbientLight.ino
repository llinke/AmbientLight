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
#define ENABLE_SERIAL_DEBUG
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

// **************************************************
// *** Variable and Constamts  Declarations
// **************************************************
const String wifiApName = "AP_AmbientLight";
const int ConfigureAPTimeout = 300;

const uint8_t globalBrightness = 128;

// Real room sizes
const std::vector<int> groupRoomSizes = {PIXEL_COUNT};

int groupRoomTotalSize = 0;
int groupRoomCount = 0;
int activeGrpNr = 0;

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

//std::vector<NeoGroup *> neoGroups;
std::vector<NeoGroup> neoGroups;

// **************************************************
// *** Helper methods
// **************************************************
#pragma region Helper Methods
bool InitWifi(bool useWifiCfgTimeout = true, bool forceReconnect = false)
{
	DEBUG_PRINTLN("WIFI ------------------------------------------------------");
	if (!forceReconnect && WiFi.status() == WL_CONNECTED)
	{
		DEBUG_PRINTLN("WiFi: already connected...");
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
	if (ledsInitialized)
	{
		fill_solid(leds, PIXEL_COUNT, connected ? CRGB::Green : CRGB::Red);
		FastLED.show();
	}
	if (connected)
	{
		DEBUG_PRINTLN("Wifi is connected...yay!!!");
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

	DEBUG_PRINTLN("Calculating groups.");
	groupRoomCount = groupRoomSizes.size();
	groupRoomTotalSize = 0;
	for (int i = 0; i < groupRoomSizes.size(); i++)
	{
		groupRoomTotalSize += groupRoomSizes[i];
	}

	DEBUG_PRINTLN("Adding special groups.");
	neoGroups.clear();
	// Group 0: all LEDs
	addGroup("All LEDs' group", 0, PIXEL_COUNT, 0);
	activeGrpNr = 0;

	DEBUG_PRINTLN("Adding " + String(groupRoomCount) + " groups for rooms.");
	int nextGroupStart = 0;
	for (int i = 0; i < groupRoomSizes.size(); i++)
	{
		String roomName = "Raum " + String(i + 1);
		addGroup(roomName, nextGroupStart, groupRoomSizes[i], 0);
		nextGroupStart += groupRoomSizes[i];
	}

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
	NeoGroup *neoGroup = &(neoGroups.at(grpNr));
	neoGroup->Start(runOnlyOnce);

	return grpNr;
}

int stopGroup(int grpNr, bool stopNow = false)
{
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
	int speed = 1)
{
	NeoGroup *neoGroup = &(neoGroups.at(grpNr));
	neoGroup->Stop(true);

	//int fxGlitter = amountglitter <= 0 ? neoGroup->GetGlitter() : amountglitter;
	int fxGlitter = amountglitter <= 0 ? currGlitter.at(grpNr) : amountglitter;
	//int fxFps = fps <= 0 ? neoGroup->GetFps() : fps;
	int fxFps = fps > 0 ? fps : currFps.at(grpNr);

	uint16_t result = neoGroup->ConfigureEffect(pattern, fxGlitter, fxFps, direction, mirror, wave, speed);
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
	int offsetGrpNr = grpNr;
	NeoGroup *neoGroup = &(neoGroups.at(offsetGrpNr));
	DEBUG_PRINTLN("StartStopEffect ---------------------------------------------");
	DEBUG_PRINTLN("Fx: Starting/stopping group #" + String(offsetGrpNr) + ": " + String((neoGroup->Active)) + "->" + String(!(neoGroup->Active)) + ".");
	bool stopNow = false;
	if (neoGroup->Active)
		stopGroup(offsetGrpNr, stopNow);
	else
		startGroup(offsetGrpNr);
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
	mirror fxMirror = MIRROR0;
	wave fxWave = wave::LINEAR;

	NeoGroup *neoGroup = &(neoGroups.at(grpNr));
	switch (fxNr)
	{
	case fxNrWave:
		fxPatternName = "Wave";
		fxPattern = pattern::WAVE;
		fxMirror = mirror::MIRROR2;
		break;
	case fxNrDynamicWave:
		fxPatternName = "Dynamic Wave";
		fxPattern = pattern::DYNAMICWAVE;
		fxMirror = mirror::MIRROR1; // mirror::MIRROR0;
		break;
	case fxNrNoise:
		fxPatternName = "Noise";
		fxPattern = pattern::NOISE;
		fxMirror = mirror::MIRROR1; // mirror::MIRROR0;
		fxFps *= 2;					// double FPS looks better
		break;
	case fxNrConfetti:
		fxPatternName = "Confetti";
		fxPattern = pattern::CONFETTI;
		fxGlitter = 0;
		// Not in this case :-p
		// fxFps /= 2; // half FPS looks better
		break;
	case fxNrFade:
		fxPatternName = "Fade";
		fxPattern = pattern::FADE;
		fxFps /= 2; // half FPS looks better
		break;
	case fxNrComet:
		fxPatternName = "Comet";
		fxPattern = pattern::COMET;
		fxWave = wave::EASEINOUT;
		// fxWave = wave::SINUS;
		fxFps *= 3; //1.5; // faster FPS looks better
		// fxMirror = mirror::MIRROR0;
		fxMirror = mirror::MIRROR2;
		break;
	case fxNrOrbit:
		fxPatternName = "Orbit";
		fxPattern = pattern::COMET;
		// fxWave = wave::EASEINOUT;
		fxWave = wave::SINUS;
		fxFps *= 1.5; // faster FPS looks better
		// fxMirror = mirror::MIRROR0;
		fxMirror = mirror::MIRROR2;
		break;
	case fxNrFill:
		fxPatternName = "Fill";
		fxPattern = pattern::FILL;
		fxWave = wave::EASEINOUT;
		fxFps *= 1.5; // faster FPS looks better
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
		speed);
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
	DEBUG_PRINTLN("Col: Changing color palette to '" + String(palKey) + "'.");
	if (ColorPalettes.find(palKey) != ColorPalettes.end())
	{
		std::vector<CRGB> colors = ColorPalettes.find(palKey)->second;
		if (colors == (std::vector<CRGB>)NULL)
		{
			colors = GeneratePaletteFromHue(currentHue, palKey);
		}
		setGrpColors(grpNr, colors, true, true, CROSSFADE_PALETTES);
	}
}

void NextEffect(int nextFx = -1)
{
	int offsetGrpNr = activeGrpNr;
	if (nextFx < 0)
	{
		(currFxNr.at(offsetGrpNr))++;
	}
	else
	{
		currFxNr.at(offsetGrpNr) = nextFx;
	}
	if (currFxNr.at(offsetGrpNr) > maxFxNr)
	{
		currFxNr.at(offsetGrpNr) = 1;
	}
	DEBUG_PRINTLN("CONTROL: Changing effect number to: " + String(currFxNr.at(offsetGrpNr)) + ".");
	SetEffect(offsetGrpNr, currFxNr.at(offsetGrpNr), true, false);
}

void NextColor(int nextCol = -1)
{
	int offsetGrpNr = activeGrpNr;
	if (nextCol < 0)
	{
		(currColNr.at(offsetGrpNr))++;
	}
	else
	{
		currColNr.at(offsetGrpNr) = nextCol;
	}
	if (currColNr.at(offsetGrpNr) > maxColNr)
	{
		currColNr.at(offsetGrpNr) = 1;
	}
	DEBUG_PRINTLN("CONTROL: Changing color number to: " + String(currColNr.at(offsetGrpNr)) + ".");
	SetColors(offsetGrpNr, currColNr.at(offsetGrpNr));
}
#pragma endregion

// **************************************************
// *** Application Setuo
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

	for (int i = 0; i < groupRoomCount; i++)
	{
		int offsetGrpNr = i;
		DEBUG_PRINTLN("FastLED: Setting up and starting group #" + String(offsetGrpNr) + ".");
		bool startFx = true;
#ifdef DO_NOT_START_FX_ON_INIT
		startFx = false;
#endif
		int currCol = defaultColNr;
		currColNr[offsetGrpNr] = currCol;
		SetColors(offsetGrpNr, currCol);

		int currFx = defaultFxNr;
		currFxNr[offsetGrpNr] = currFx;
		SetEffect(offsetGrpNr, currFx, startFx, false);
		//startGroup(offsetGrpNr);
	}
	//activeGrpNr = 0;

	DEBUG_PRINT("FastLED: Active group #" + String(activeGrpNr));
}
#pragma endregion

// **************************************************
// *** Application Loop
// **************************************************
#pragma region Application Loop
// Main loop
void loop()
{
	// Evaluate expander pins and execute attached callbacks
	//DEBUG_PRINTLN("LOOP ------------------------------------------------------");

	if (!ledsStarted)
	{
		//DEBUG_PRINTLN("Loop: LEDs not started, leaving loop.");
		return;
	}

	bool ledsUpdated = false;
	for (int i = 0; i < groupRoomCount; i++)
	{
		int offsetGrpNr = i;
		NeoGroup *neoGroup = &(neoGroups.at(offsetGrpNr));

		if ((neoGroup->LedFirstNr + neoGroup->LedCount) <= PIXEL_COUNT)
		{
			ledsUpdated |= neoGroup->Update();
		}
	}

	// Cycle palette of group at corresponding status LED
	static unsigned long lastUpdate = 0;
	static unsigned long updateInterval = (1000 / 50); // 50 fps
	if ((millis() - lastUpdate) > updateInterval)
	{
#ifdef DEBUG_LOOP
		DEBUG_PRINTLN("DONE");
#endif
		ledsUpdated = true;
		lastUpdate = millis();
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