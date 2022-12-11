#include "joystick.h"

void ProcessJoystick() {

	if (Appli_state == APPLICATION_READY) {
		HID_TypeTypeDef device_type = USBH_HID_GetDeviceType(&hUsbHostFS);

		if (device_type == HID_UNKNOWN) {

			joymap = USBH_HID_GetGamepadInfo(&hUsbHostFS);

			if (joymap != NULL) {

				HAL_GPIO_WritePin(RHQ_GPIO_Port, RHQ_Pin, !(joymap->gamepad_data & 0x1));
				HAL_GPIO_WritePin(LVQ_GPIO_Port, LVQ_Pin, !(joymap->gamepad_data >> 1 & 0x1));
				HAL_GPIO_WritePin(BH_GPIO_Port, BH_Pin, !(joymap->gamepad_data >> 2 & 0x1));
				HAL_GPIO_WritePin(FV_GPIO_Port, FV_Pin, !(joymap->gamepad_data >> 3 & 0x1));
				HAL_GPIO_WritePin(LB_GPIO_Port, LB_Pin, !(joymap->gamepad_data >> 4 & 0x1));
				HAL_GPIO_WritePin(RB_GPIO_Port, RB_Pin, !(joymap->gamepad_data >> 5 & 0x1));
				HAL_GPIO_WritePin(MB_GPIO_Port, MB_Pin, !(joymap->gamepad_data >> 6 & 0x1));
			}
		}
	}
}

