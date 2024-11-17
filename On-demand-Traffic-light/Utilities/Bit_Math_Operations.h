/*
 * Bit_Math_Operations.h
 *
 * Created: 10/11/2022 12:31:03 PM
 *  Author: Ramzy
 */ 


#ifndef BIT_MATH_OPERATIONS_H_
#define BIT_MATH_OPERATIONS_H_


#define SET_BIT(Register,Bit_No)       (Register |= (1<<Bit_No))			// Set Bit value to 1
#define CLEAR_BIT(Register,Bit_No)       (Register &= ~(1<<Bit_No))		    // Clear Bit value to 0
#define TOGGLE_BIT(Register,Bit_No)       (Register ^= (1<<Bit_No))			// Toggle Bit value
#define GET_BIT(Register,Bit_No)       ((Register&(1<<Bit_No))>>Bit_No)		// Read Bit value


#endif /* BIT_MATH_OPERATIONS_H_ */