#include "counter.h"

nBlock_Counter::nBlock_Counter(uint32_t auto_reset){
	
	_count = 0;
	reset_number = auto_reset;
	return;
}

void nBlock_Counter::triggerInput(nBlocks_Message message){
	
	if(message.inputNumber == COUNT_IN && message.intValue !=0){
		
		
		_count++;
		
		if(_count == reset_number){reset_flag = 1;return;}
		
		output[0] = _count;
		available[0] = 1;
		
		
	}
	else if(message.inputNumber == RESET){// reset may need to go in endframe
	
	
		reset_flag = 1;
			
	}
	
		
	
}

void nBlock_Counter::endFrame(void) {
	
	if(reset_flag == 1){
		
		_count = 0;
		output[0] = _count;
		available[0] = 1;
		reset_flag = 0;
	}
	

}

