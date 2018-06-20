#include "SerialDebug.h"
#include "WrapperUdpLed.h"

WrapperUdpLed::WrapperUdpLed(
    uint16_t ledCount, uint16_t udpPort)
{
  DEBUG_PRINT("UDP: Constructing WrapperUdpLed for" + String(ledCount) + "LEDs on port " + String(udpPort) + "...");
  _udp = WiFiUDP();
  _ledCount = ledCount;
  _udpPort = udpPort;

  _bufferSize = _ledCount * 3; //3 bytes per LED

  _udpBuffer = new byte[_bufferSize + 1];
  _udpBuffer[_bufferSize] = 0;

  _opened = false;
  DEBUG_PRINTLN("done.");
}

void WrapperUdpLed::begin(void)
{
  DEBUG_PRINT("UDP: Opening port " + String(_udpPort) + " for UDP...");
  if (!_opened)
  {
    if (_udp.begin(_udpPort))
    {
      DEBUG_PRINTLN("success.");
      _opened = true;
    }
    else
    {
      DEBUG_PRINTLN("no success.");
    }
  }
  else
  {
    DEBUG_PRINTLN("already open.");
  }
}

void WrapperUdpLed::stop(void)
{
  if (_opened)
  {
    DEBUG_PRINTLN("UDP: Closing port " + String(_udpPort) + " for UDP...");
    _udp.stop();
    _opened = false;
  }
}

bool WrapperUdpLed::handle(bool handleData)
{
  int bytes = _udp.parsePacket();

  if (bytes > 0)
  {
    DEBUG_PRINTLN("UDP: Packet received, length: " + String(bytes));
    if (bytes == _bufferSize)
    {
      _udp.readBytes(_udpBuffer, _bufferSize);

      if (handleData)
      {
        // DEBUG_PRINTLN("UDP: Contents: %s", _udpBuffer);
        for (int i = 0; i < _ledCount; i++)
        {
          updateLed(i, _udpBuffer[i * 3 + 0], _udpBuffer[i * 3 + 1], _udpBuffer[i * 3 + 2]);
        }
      }
      else
      {
        DEBUG_PRINTLN("UDP: ignoring received data");
      }
      return true;
    }
    else
    {
      DEBUG_PRINTLN("UDP: Packet size expected=" + String(_bufferSize) + ", actual=" + String(bytes));
    }
  }
  return false;
}

void WrapperUdpLed::onUpdateLed(
    void (*function)(int, byte, byte, byte))
{
  DEBUG_PRINTLN("UDP: attaching onUpdateLed handler...");
  updateLedPointer = function;
}

void WrapperUdpLed::updateLed(
    int id, byte r, byte g, byte b)
{
  if (updateLedPointer)
  {
    updateLedPointer(id, r, g, b);
  }
}
