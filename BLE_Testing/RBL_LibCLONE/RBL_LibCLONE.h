
#ifndef  _RBL_LibCLONE_H
#define _RBL_LibCLONE_H

#include <boards.h>
#include <lib_aci.h>
#include <aci_setup.h>
#include <SPI.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include "RBL_services.h"


#define DEFAULT_REQN    9
#define DEFAULT_RDYN    8

void ble_begin();
void ble_set_name(char *name);
void ble_write(unsigned char data);
void ble_write_bytes(unsigned char *data, unsigned char len);
void ble_do_events();
int ble_read();
unsigned char ble_available();
unsigned char ble_connected(void);
void ble_set_pins(uint8_t reqn, uint8_t rdyn);
unsigned char ble_busy();

#endif

