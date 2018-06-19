#include "WrapperUdpLed.h"

WrapperUdpLed::WrapperUdpLed(uint16_t ledCount, uint16_t udpPort)
{
  _udp = WiFiUDP();
  _ledCount = ledCount;
  _udpPort = udpPort;

  _bufferSize = _ledCount * 3; //3 bytes per LED

  _udpBuffer = new byte[_bufferSize + 1];
  _udpBuffer[_bufferSize] = 0;

  _opened = false;
}

void WrapperUdpLed::begin(void)
{
  if (!_opened)
  {
    DEBUG_PRINT("UDP: Open port %i for UDP...", _udpPort);
    if (_udp.begin(_udpPort))
    {
      DEBUG_PRINTLN("success");
      _opened = true;
    }
    else
    {
      DEBUG_PRINTLN("no success");
    }
  }
}
void WrapperUdpLed::stop(void)
{
  if (_opened)
  {
    DEBUG_PRINTLN("UDP: Close port %i for UDP...", _udpPort);
    _udp.stop();
    _opened = false;
  }
}
bool WrapperUdpLed::handle(void)
{
  int bytes = _udp.parsePacket();
  if (bytes > 0)
  {
    DEBUG_PRINTLN("UDP: Packet received, length: %i", bytes);
    if (bytes == _bufferSize)
    {
      _udp.readBytes(_udpBuffer, _bufferSize);
      // DEBUG_PRINTLN("UDP: Contents: %s", _udpBuffer);
      for (int i = 0; i < _ledCount; i++)
      {
        updateLed(i, _udpBuffer[i * 3 + 0], _udpBuffer[i * 3 + 1], _udpBuffer[i * 3 + 2]);
      }
      // refreshLeds();
      return true;
    }
    else
    {
      DEBUG_PRINTLN("UDP: Packet size expected=%i, actual=%i", _bufferSize, bytes);
    }
  }
  return false;
}

void WrapperUdpLed::onUpdateLed(void (*function)(int, byte, byte, byte))
{
  updateLedPointer = function;
}
void WrapperUdpLed::updateLed(int id, byte r, byte g, byte b)
{
  if (updateLedPointer)
  {
    updateLedPointer(id, r, g, b);
  }
}

// void WrapperUdpLed::onRefreshLeds(void (*function)(void))
// {
//   refreshLedsPointer = function;
// }
// void WrapperUdpLed::refreshLeds(void)
// {
//   if (refreshLedsPointer)
//   {
//     refreshLedsPointer();
//   }
// }
