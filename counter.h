/**
 * @brief       counter.h
 * @details     Counter node class header file.
 */
#ifndef __NB_COUNTER
#define __NB_COUNTER

#include "mbed.h"
#include "nworkbench.h"

class nBlock_Counter: public nBlockSimpleNode<1> {
public:

	enum input{
		
		COUNT_IN = 0,
		RESET = 1
	};
	
    nBlock_Counter(uint32_t auto_reset);
    void triggerInput(uint32_t inputNumber, uint32_t value);
	void endFrame(void);
   
private:

	uint32_t _count;
	uint32_t reset_number;
	uint32_t reset_flag;
    
	
};

#endif