#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "cmsis_os.h"

extern osSemaphoreId binarySemUartMsgHandle;

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	if(binarySemUartMsgHandle != NULL){
		if(xSemaphoreTake(binarySemUartMsgHandle, (TickType_t) 10 == pdTRUE)){
			uartMsgRdy();
		}
	}
}

void Model::uartMsgRdy(){
	modelListener->uartMsgRdy();
}
