/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    tim.h
  * @brief   This file contains all the function prototypes for
  *          the tim.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TIM_H__
#define __TIM_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

/* USER CODE BEGIN Private defines */
extern volatile int8_t mouseDirectionX;		// X direction (0 = decrement, 1 = increment)
extern volatile int8_t mouseEncoderPhaseX;		// X Quadrature phase (0-3)
extern volatile int8_t mouseDirectionY;		// Y direction (0 = decrement, 1 = increment)
extern volatile int8_t mouseEncoderPhaseY;		// Y Quadrature phase (0-3)
extern volatile int16_t mouseDistanceX;		// Distance left for mouse to move
extern volatile int16_t mouseDistanceY;		// Distance left for mouse to move
extern volatile uint8_t xTimerTop;				// X axis timer TOP value
extern volatile uint8_t yTimerTop;				// Y axis timer TOP value

/* USER CODE END Private defines */

void MX_TIM2_Init(void);
void MX_TIM3_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __TIM_H__ */

