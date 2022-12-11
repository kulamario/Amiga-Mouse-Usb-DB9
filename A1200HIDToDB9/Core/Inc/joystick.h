#include "stdint.h"
#include "usb_host.h"
#include "usbh_hid.h"
//#include "usbh_hid_gamepad.h"
#include "usbh_hid_mouse.h"
#include "stm32f4xx_hal_tim.h"

HID_gamepad_Info_TypeDef* joymap;


extern ApplicationTypeDef Appli_state;
extern USBH_HandleTypeDef hUsbHostFS;

void ProcessJoystick();
