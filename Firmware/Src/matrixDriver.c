/*
 * matrixDriver.c
 *
 *  Created on: Jun 17, 2019
 *      Author: Sean
 */


//#include "main.h"
#include "matrixDriver.h"
#include "stdbool.h"
//#include "matrixData.c"
uint8_t columnIndex = 0;

#define FRAME_BUFF_SIZE 32
volatile uint8_t mdFrameBuffer[FRAME_BUFF_SIZE];


const uint8_t charset[27][5] = {
		{0x1e, 0x05, 0x05, 0x05, 0x1e}, // A
		{0x1f, 0x15, 0x15, 0x15, 0x0a}, // B
		{0x0e, 0x11, 0x11, 0x11, 0x00}, // C
		{0x1f, 0x11, 0x11, 0x11, 0x0e}, // D
		{0x1f, 0x15, 0x15, 0x15, 0x11}, // E
		{0x1f, 0x05, 0x05, 0x05, 0x01}, // F
		{0x0e, 0x11, 0x11, 0x15, 0x0c}, // G
		{0x1f, 0x04, 0x04, 0x04, 0x1f}, // H
		{0x00, 0x11, 0x1f, 0x11, 0x00}, // I
		{0x00, 0x08, 0x11, 0x0f, 0x01}, // J
		{0x1f, 0x04, 0x0a, 0x11, 0x00}, // K
		{0x1f, 0x10, 0x10, 0x10, 0x10}, // L
		{0x3f, 0x02, 0x04, 0x02, 0x3f}, // M
		{0x3f, 0x02, 0x04, 0x08, 0x3f}, // N
		{0x0e, 0x11, 0x11, 0x11, 0x0e}, // O
		{0x1f, 0x05, 0x05, 0x05, 0x02}, // P
		{0x0e, 0x11, 0x15, 0x09, 0x16}, // Q
		{0x1f, 0x05, 0x05, 0x0d, 0x12}, // R
		{0x12, 0x15, 0x15, 0x15, 0x09}, // S
		{0x01, 0x01, 0x1f, 0x01, 0x01}, // T
		{0x0f, 0x10, 0x10, 0x10, 0x0f}, // U
		{0x03, 0x0c, 0x30, 0x0c, 0x03}, // V
		{0x0f, 0x10, 0x0c, 0x10, 0x0f}, // W
		{0x11, 0x0a, 0x04, 0x0a, 0x11}, // X
		{0x01, 0x02, 0x1c, 0x02, 0x01}, // Y
		{0x11, 0x19, 0x15, 0x13, 0x11}, // Z
		{0x00, 0x00, 0x00, 0x00, 0x00}, // (SPACE)
};


uint8_t mdUpdate(){
	dispCol(columnIndex, mdFrameBuffer[15-columnIndex]);
	++columnIndex;
	if(columnIndex>16){
		columnIndex = 0;
	}
	return columnIndex;
}

void shiftFrameBuffer(bool direction){
	if(direction){
		for(uint8_t i = FRAME_BUFF_SIZE; i>0; --i){
			mdFrameBuffer[i] = mdFrameBuffer[i-1];
		}
		mdFrameBuffer[0] = 0;
	}
	else{
		for(uint8_t i = 1; i<FRAME_BUFF_SIZE; ++i){
			mdFrameBuffer[i-1] = mdFrameBuffer[i];
		}
		mdFrameBuffer[FRAME_BUFF_SIZE-1] = 0;
	}
}

void dispCol(uint8_t col, uint8_t disp){
	switch(col){
			case 0:
			GPIOA->MODER = 0b0101010101 | (0b1111111111111111 << 14);
			GPIOB->MODER = 0b1111;
			GPIOC->MODER = 0b0111<<(14*2);
			GPIOC->ODR = 0b10<<(14);
			GPIOA->ODR = ~disp;
			break;

			case 1:
			GPIOC->ODR = 0b00<<(14);
			GPIOA->ODR = disp;
			break;

			case 2:
			GPIOC->MODER = 0b1101<<(14*2);
			GPIOC->ODR = 0b01<<(14);
			GPIOA->ODR = ~disp;
			break;

			case 3:
			GPIOC->ODR = 0b00<<(14);
			GPIOA->ODR = disp;
			break;

			case 4:
			GPIOA->MODER = 0b0101010101 | (0b0111111111111111 << 14) ;
			GPIOC->MODER = 0b1111<<(14*2);
			GPIOA->ODR = (~disp & 0b11111) | 0b0100000000000000;
			break;

			case 5:
			GPIOA->ODR = disp;
			break;

			case 6:
			GPIOA->MODER = 0b0101010101 | (0b1101111111111111 << 14) ;
			GPIOA->ODR = (~disp & 0b11111) | 0b0010000000000000;
			break;

			case 7:
			GPIOA->ODR = disp;
			break;

			case 8:
			GPIOA->MODER = 0b0101010101 | (0b1111111101111111 << 14) ;
			GPIOA->ODR = (~disp & 0b11111) | 0b0000010000000000;
			break;

			case 9:
			GPIOA->ODR = disp;
			break;

			case 10:
			GPIOA->MODER = 0b0101010101 | (0b1111111111011111 << 14) ;
			GPIOA->ODR = (~disp & 0b11111) | 0b0000001000000000;
			break;

			case 11:
			GPIOA->ODR = disp;
			break;

			case 12:
			GPIOA->MODER = 0b0101010101 | (0b1111111111111111 << 14) ;
			GPIOB->MODER = 0b0111;
			GPIOB->ODR = 0b10;
			GPIOA->ODR = ~disp;
			break;

			case 13:
			GPIOB->ODR = 0b00;
			GPIOA->ODR = disp;
			break;

			case 14:
			GPIOA->MODER = 0b0101010101 | (0b1111111111111101 << 14) ;
			GPIOB->MODER = 0b1111;
			GPIOA->ODR = (~disp & 0b11111) | 0b0000000010000000;
			break;

			case 15:
			GPIOA->ODR = disp;
			break;

			case 16:
			GPIOA->MODER = 0b1111111111 | (0b111111111111111111 << 13) ;
			GPIOB->MODER = 0b1111;
			GPIOC->MODER = 0b1111<<(14*2);
			break;



	}
}

