#ifndef WrapperUdpLed_h
#define WrapperUdpLed_h

#include <Arduino.h>
#include "SerialDebug.h"
#include <WiFiUdp.h>

class WrapperUdpLed
{
  public:
    WrapperUdpLed(){};
    WrapperUdpLed(
        uint16_t ledCount, uint16_t udpPort);

    void begin(void);
    void stop(void);
    bool handle(bool);

    void onUpdateLed(
        void (*function)(int, byte, byte, byte));
    void onRefreshLeds(
        void (*function)(void));

  private:
    WiFiUDP _udp;
    uint16_t _ledCount;
    uint16_t _udpPort;
    byte *_udpBuffer;
    uint16_t _bufferSize;
    boolean _opened;

    void updateLed(
        int id, byte r, byte g, byte b),
        (*updateLedPointer)(int, byte, byte, byte);
};

#endif
