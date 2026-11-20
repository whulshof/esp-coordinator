#pragma once
// Signal of the received Zigbee frames, for the host's sensors. Plain build:
// nothing. ESPHome build: the zboss_ncp component keeps a running window
// (ncp_host_rx_note() in ncp_host.cpp) and publishes it as sensors.
#include "sdkconfig.h"
#include <stdint.h>

#if CONFIG_NCP_ESPHOME
extern "C" void ncp_host_rx_note(int8_t rssi, uint8_t lqi);
static inline void ncp_rx_note(int8_t rssi, uint8_t lqi) { ncp_host_rx_note(rssi, lqi); }
#else
static inline void ncp_rx_note(int8_t, uint8_t) {}
#endif
