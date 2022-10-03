/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
int matrix[6][6]={0};
int int_to_pin(int input){
	int pin_gate;
		switch(input){
		case 1:
				pin_gate=GPIO_PIN_1;
				break;
		case 2:
				pin_gate=GPIO_PIN_2;
				break;
		case 3:
				pin_gate=GPIO_PIN_3;
				break;
		case 4:
				pin_gate=GPIO_PIN_4;
				break;
		case 5:
				pin_gate=GPIO_PIN_5;
				break;
		case 6:
				pin_gate=GPIO_PIN_6;
				break;
		case 7:
				pin_gate=GPIO_PIN_7;
				break;
		case 8:
				pin_gate=GPIO_PIN_8;
				break;
		case 9:
				pin_gate=GPIO_PIN_9;
				break;
		case 10:
				pin_gate=GPIO_PIN_10;
				break;
		}
		return pin_gate;
}
void setPin(int input, int logic) {
	GPIO_PinState state;
	if (logic) state = GPIO_PIN_SET;
	else state = GPIO_PIN_RESET;
	int pin_gate=int_to_pin(input);
	HAL_GPIO_WritePin(GPIOA, pin_gate, state);

}
void run(int matrix[][6]) {
	int x,y;
	for (x=1;x<6;x++){
		for (y=1;y<6;y++){
			if (matrix[y][x]) setPin(y+5,0);
			else setPin(y+5,1);
		}
		setPin(x,1);
		HAL_Delay(1);
		setPin(x,0);
	}
}
void clearAllClock(int matrix[][6]){
	for (int i=0;i<6;i++){
		for (int j=0;j<6;j++){
			matrix[i][j]=0;
		}
	}
}
void  setNumberOnClock(int num) {
	switch (num) {
	case 0:
		matrix[1][3]=1;
		break;
	case 1:
		matrix[1][4]=1;
		break;
	case 2:
		matrix[2][5]=1;
		break;
	case 3:
		matrix[3][5]=1;
		break;
	case 4:
		matrix[4][5]=1;
		break;
	case 5:
		matrix[5][4]=1;
		break;
	case 6:
		matrix[5][3]=1;
		break;
	case 7:
		matrix[5][2]=1;
		break;
	case 8:
		matrix[4][1]=1;
		break;
	case 9:
		matrix[3][1]=1;
		break;
	case 10:
		matrix[2][1]=1;
		break;
	case 11:
		matrix[1][2]=1;
		break;
	}
}

void  setNumberOnClock1(int num) {
	switch (num) {
	case 0:
		matrix[1][3]=1;
		break;
	case 1:
		matrix[1][4]=1;
		break;
	case 2:
		matrix[2][5]=1;
		break;
	case 3:
		matrix[3][5]=1;
		break;
	case 4:
		matrix[4][5]=1;
		break;
	case 5:
		matrix[5][4]=1;
		break;
	case 6:
		matrix[5][3]=1;
		break;
	case 7:
		matrix[5][2]=1;
		break;
	case 8:
		matrix[4][1]=1;
		break;
	case 9:
		matrix[3][1]=1;
		break;
	case 10:
		matrix[2][1]=1;
		break;
	case 11:
		matrix[1][2]=1;
		break;
	}
}

void  setNumberOnClock2(int num) {
	switch (num) {
	case 0:
		matrix[1][3]=1;
		break;
	case 1:
		matrix[1][4]=1;
		break;
	case 2:
		matrix[2][5]=1;
		break;
	case 3:
		matrix[3][5]=1;
		break;
	case 4:
		matrix[4][5]=1;
		break;
	case 5:
		matrix[5][4]=1;
		break;
	case 6:
		matrix[5][3]=1;
		break;
	case 7:
		matrix[5][2]=1;
		break;
	case 8:
		matrix[4][1]=1;
		break;
	case 9:
		matrix[3][1]=1;
		break;
	case 10:
		matrix[2][1]=1;
		break;
	case 11:
		matrix[1][2]=1;
		break;
	}
}

void  clearNumberOnClock(int num) {
	switch (num) {
	case 0:
		matrix[1][3]=0;
		break;
	case 1:
		matrix[1][4]=0;
		break;
	case 2:
		matrix[2][5]=0;
		break;
	case 3:
		matrix[3][5]=0;
		break;
	case 4:
		matrix[4][5]=0;
		break;
	case 5:
		matrix[5][4]=0;
		break;
	case 6:
		matrix[5][3]=0;
		break;
	case 7:
		matrix[5][2]=0;
		break;
	case 8:
		matrix[4][1]=0;
		break;
	case 9:
		matrix[3][1]=0;
		break;
	case 10:
		matrix[2][1]=0;
		break;
	case 11:
		matrix[1][2]=0;
		break;
	}
}
void  clearNumberOnClock1(int num) {
	switch (num) {
	case 0:
		matrix[1][3]=0;
		break;
	case 1:
		matrix[1][4]=0;
		break;
	case 2:
		matrix[2][5]=0;
		break;
	case 3:
		matrix[3][5]=0;
		break;
	case 4:
		matrix[4][5]=0;
		break;
	case 5:
		matrix[5][4]=0;
		break;
	case 6:
		matrix[5][3]=0;
		break;
	case 7:
		matrix[5][2]=0;
		break;
	case 8:
		matrix[4][1]=0;
		break;
	case 9:
		matrix[3][1]=0;
		break;
	case 10:
		matrix[2][1]=0;
		break;
	case 11:
		matrix[1][2]=0;
		break;
	}
}
void  clearNumberOnClock2(int num) {
	switch (num) {
	case 0:
		matrix[1][3]=0;
		break;
	case 1:
		matrix[1][4]=0;
		break;
	case 2:
		matrix[2][5]=0;
		break;
	case 3:
		matrix[3][5]=0;
		break;
	case 4:
		matrix[4][5]=0;
		break;
	case 5:
		matrix[5][4]=0;
		break;
	case 6:
		matrix[5][3]=0;
		break;
	case 7:
		matrix[5][2]=0;
		break;
	case 8:
		matrix[4][1]=0;
		break;
	case 9:
		matrix[3][1]=0;
		break;
	case 10:
		matrix[2][1]=0;
		break;
	case 11:
		matrix[1][2]=0;
		break;
	}
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  for(int i =0;i<12;i++) {
	  		  setNumberOnClock(i);
	  		  clearNumberOnClock(i-1);
	  		  run(matrix);
	  		  for(int j=0;j<12;j++) {
	  			  if (j==0 && i!=11) clearNumberOnClock1(11);
	  			  run(matrix);
	  			  setNumberOnClock1(j);
	  			  if((j-1)!=i) clearNumberOnClock1(j-1);
	  			  run(matrix);
	  			  for (int k =0;k<12;k++) {
	  				  if (k==0 && i!=11 && j!=11) clearNumberOnClock2(11);
	  				  run(matrix);
	  				  setNumberOnClock2(k);
	  				  if(k-1!=i && k-1 != j) clearNumberOnClock2(k-1);
	  				  run(matrix);
	  				  HAL_Delay(50);
	  			  }
	  		  }
	  	  }
	  	  clearAllClock(matrix);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8
                          |GPIO_PIN_9|GPIO_PIN_10, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA1 PA2 PA3 PA4
                           PA5 PA6 PA7 PA8
                           PA9 PA10 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8
                          |GPIO_PIN_9|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
