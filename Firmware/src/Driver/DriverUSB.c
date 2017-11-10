/*
 * DriverUSB.c
 *
 *  Created on: 8 de nov. de 2017
 *      Author: Dante Sangiovanni
 */

#include "DriverUSB.h"

USBD_HANDLE_T g_hUsb;
const  USBD_API_T *g_pUsbApi = &g_usbApi;

const  USBD_HW_API_T hw_api;
const  USBD_CORE_API_T core_api;
const  USBD_HID_API_T hid_api;

void InitUSB (void)
{
	usb_pin_clk_init();
}

/* Initialize pin and clocks for USB port */
void usb_pin_clk_init(void)
{
	/* enable USB PLL and clocks */
	Chip_USB_Init();
	/* enable USB 1 port on the board */
	//Board_USBD_Init(1);
}

/* Find the address of interface descriptor for given class type. */
USB_INTERFACE_DESCRIPTOR *find_IntfDesc(const uint8_t *pDesc, uint32_t intfClass)
{
	USB_COMMON_DESCRIPTOR *pD;
	USB_INTERFACE_DESCRIPTOR *pIntfDesc = 0;
	uint32_t next_desc_adr;

	pD = (USB_COMMON_DESCRIPTOR *) pDesc;
	next_desc_adr = (uint32_t) pDesc;

	while (pD->bLength) {
		/* is it interface descriptor */
		if (pD->bDescriptorType == USB_INTERFACE_DESCRIPTOR_TYPE) {

			pIntfDesc = (USB_INTERFACE_DESCRIPTOR *) pD;
			/* did we find the right interface descriptor */
			if (pIntfDesc->bInterfaceClass == intfClass) {
				break;
			}
		}
		pIntfDesc = 0;
		next_desc_adr = (uint32_t) pD + pD->bLength;
		pD = (USB_COMMON_DESCRIPTOR *) next_desc_adr;
	}

	return pIntfDesc;
}
