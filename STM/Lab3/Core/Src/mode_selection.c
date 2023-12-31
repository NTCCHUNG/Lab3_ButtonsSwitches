

#include "mode_selection.h"

// timer 2, tan so quet cua led REDs trong mode 2 3 4
// timer 3 , tan so quet cua led 7 doan

void mode_1(){
	fsm_automatic_run_0();
	fsm_automatic_run_1();
}


void selection(){
	switch (status) {
		case 0:
			mode_1();
			if(is_button_Pressed(0)){
				status = 1 ;
				value = 0 ;
				counter = 1 ;
				i = 0 ;
				i1 = 0 ;
				setTimer7(500) ;
				setTimer9(500) ;
				bufferValue(value) ;
				bufferMode(status) ;
				// turn on LED RED and turn off another LEDs
				HAL_GPIO_WritePin(RED1, Pin_RED1, RESET) ;
				HAL_GPIO_WritePin(RED2, Pin_RED2, RESET) ;
				HAL_GPIO_WritePin(AMBER1, Pin_AMBER1, SET) ;
				HAL_GPIO_WritePin(AMBER2, Pin_AMBER2, SET) ;
				HAL_GPIO_WritePin(GREEN1, Pin_GREEN1, SET) ;
				HAL_GPIO_WritePin(GREEN2, Pin_GREEN2, SET) ;
			}
			break;
		case 1:

			// led 7SEGs
			if(timer9_flag >= 1){
				setTimer9(500);
				if(i > 1) i = 0 ;
				update_mode(i++) ;
				if(i1 > 1) i1 = 0 ;
				update_value(i1++) ;
			}
			if(timer8_flag >= 1){
		//			HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState)
				setTimer8(1000);
				counter--;
				bufferValue(counter);
			}

			// toggle led REDs
			if(timer7_flag >= 1){
				setTimer7(500);
				HAL_GPIO_TogglePin(RED1, Pin_RED1) ;
				HAL_GPIO_TogglePin(RED2, Pin_RED2) ;
			}
			// increase a value of counter
			if(is_button_Pressed(1)){
				  value++;
				  if(value > 99) value = 0;
				  bufferValue(value) ;
			}
			// set a value of counter then decreased value of counter
			if(is_button_Pressed(2)){
				counter = value ;
				setTimer8(1000) ;
			}
			// chuyen trang thai
			if(is_button_Pressed(0)){
				status = 2  ;
				value = 0 ;
				counter = 1 ;
				i = 0 ;
				i1 = 0 ;
				setTimer7(500) ;
				setTimer9(500) ;
				bufferValue(value) ;
				bufferMode(status) ;
				HAL_GPIO_WritePin(RED1, Pin_RED1, SET) ;
				HAL_GPIO_WritePin(RED2, Pin_RED2, SET) ;
				HAL_GPIO_WritePin(AMBER1, Pin_AMBER1, RESET) ;
				HAL_GPIO_WritePin(AMBER2, Pin_AMBER2, RESET) ;
				HAL_GPIO_WritePin(GREEN1, Pin_GREEN1, SET) ;
				HAL_GPIO_WritePin(GREEN2, Pin_GREEN2, SET) ;
			}

			if(counter <= 0 ){
				status = 0 ;
				status_traffic_0 = INIT;
				status_traffic_1 = INIT;
				bufferMode(status);
			}

			break;

	case 2:
		// led 7SEGs
		if(timer9_flag >= 1){
			setTimer9(500);
			if(i > 1) i = 0 ;
			update_mode(i++) ;
			if(i1 > 1) i1 = 0 ;
			update_value(i1++) ;
		}
		if(timer8_flag >= 1){
			setTimer8(1000);
			counter--;
			bufferValue(counter);
		}

		// toggle led REDs
		if(timer7_flag >= 1){
			setTimer7(500);
			HAL_GPIO_TogglePin(AMBER1, Pin_AMBER1) ;
			HAL_GPIO_TogglePin(AMBER2, Pin_AMBER2) ;
		}
		// increase a value of counter
		if(is_button_Pressed(1)){
			  value++;
			  if(value > 99) value = 0;
			  bufferValue(value) ;
		}
		// set a value of counter then decreased value of counter
		if(is_button_Pressed(2)){
			counter = value ;
			setTimer8(1000) ;
		}
		// chuyen trang thai
		if(is_button_Pressed(0)){
			status = 3  ;
			value = 0 ;
			counter = 1 ;
			i = 0 ;
			i1 = 0 ;
			setTimer7(500) ;
			setTimer9(500) ;
			bufferValue(value) ;
			bufferMode(status) ;
			HAL_GPIO_WritePin(RED1, Pin_RED1, SET) ;
			HAL_GPIO_WritePin(RED2, Pin_RED2, SET) ;
			HAL_GPIO_WritePin(AMBER1, Pin_AMBER1, SET) ;
			HAL_GPIO_WritePin(AMBER2, Pin_AMBER2, SET) ;
			HAL_GPIO_WritePin(GREEN1, Pin_GREEN1, RESET) ;
			HAL_GPIO_WritePin(GREEN2, Pin_GREEN2, RESET) ;
		}

		if(counter <= 0 ){
			status = 0 ;
			status_traffic_0 = INIT;
			status_traffic_1 = INIT;
			bufferMode(status);
		}

			break;
		case 3:
			// led 7SEGs
			if(timer9_flag >= 1){
				setTimer9(500);
				if(i > 1) i = 0 ;
				update_mode(i++) ;
				if(i1 > 1) i1 = 0 ;
				update_value(i1++) ;
			}
			if(timer8_flag >= 1){
				setTimer8(1000);
				counter--;
				bufferValue(counter);
			}

			// toggle led REDs
			if(timer7_flag >= 1){
				setTimer7(500);
				HAL_GPIO_TogglePin(GREEN1, Pin_GREEN1) ;
				HAL_GPIO_TogglePin(GREEN2, Pin_GREEN2) ;
			}
			// increase a value of counter
			if(is_button_Pressed(1)){
				  value++;
				  if(value > 99) value = 0;
				  bufferValue(value) ;
			}
			// set a value of counter then decreased value of counter
			if(is_button_Pressed(2)){
				counter = value ;
				setTimer8(1000) ;
			}
			// chuyen trang thai
			if(is_button_Pressed(0) || counter <= 0){
				status = 0 ;
				status_traffic_0 = INIT;
				status_traffic_1 = INIT;
				bufferMode(status);
			}

			break;

		default:
			break;
	}
}
