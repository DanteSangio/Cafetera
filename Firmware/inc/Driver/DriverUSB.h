/*
 * DriverUSB.h
 *
 *  Created on: 8 de nov. de 2017
 *      Author: Dante Sangiovanni
 */

#ifndef FIRMWARE_INC_DRIVER_DRIVERUSB_H_
#define FIRMWARE_INC_DRIVER_DRIVERUSB_H_

#include "chip.h"

#include "app_usbd_cfg.h"
#include "hid_generic.h"

extern USBD_HANDLE_T g_hUsb;

extern const  USBD_HW_API_T hw_api;
extern const  USBD_CORE_API_T core_api;
extern const  USBD_HID_API_T hid_api;
/* Since this example only uses HID class link functions for that class only */
static const  USBD_API_T g_usbApi = {
	&hw_api,
	&core_api,
	0,
	0,
	&hid_api,
	0,
	0,
	0x02221101,
};

extern const USBD_API_T *g_pUsbApi;

void InitUSB (void);
void usb_pin_clk_init(void);
USB_INTERFACE_DESCRIPTOR *find_IntfDesc(const uint8_t *, uint32_t );

#endif /* FIRMWARE_INC_DRIVER_DRIVERUSB_H_ */
