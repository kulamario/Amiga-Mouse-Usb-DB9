#include "stdint.h"
#include "usb_host.h"
#include "usbh_hid.h"
//#include "usbh_hid_gamepad.h"
#include "usbh_hid_mouse.h"
#include "stm32f4xx_hal_tim.h"


#define MOUSEX	0
#define MOUSEY	1
#define Q_RATELIMIT 500
#define Q_BUFFERLIMIT 300
#define DPI_DIVIDER 2

volatile int8_t mouseDirectionX = 0;		// X direction (0 = decrement, 1 = increment)
volatile int8_t mouseEncoderPhaseX = 0;		// X Quadrature phase (0-3)
volatile int8_t mouseDirectionY = 0;		// Y direction (0 = decrement, 1 = increment)
volatile int8_t mouseEncoderPhaseY = 0;		// Y Quadrature phase (0-3)
volatile int16_t mouseDistanceX = 0;		// Distance left for mouse to move
volatile int16_t mouseDistanceY = 0;		// Distance left for mouse to move
volatile uint8_t xTimerTop = 1;				// X axis timer TOP value
volatile uint8_t yTimerTop = 1;				// Y axis timer TOP value

HID_MOUSE_Info_TypeDef    *mousemap;
extern HID_MOUSE_Info_TypeDef mouse_info;
extern ApplicationTypeDef Appli_state;
extern USBH_HandleTypeDef hUsbHostFS;
extern void USBH_HID_NextInterface(USBH_HandleTypeDef *phost);


void ProcessMouse();

void ProcessX_IRQ();
void ProcessY_IRQ();
