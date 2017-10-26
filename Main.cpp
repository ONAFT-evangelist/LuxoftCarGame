#include "CarClass.h"

int main() {
	srand(time(0));
	CarClass car;
	car.mapSet();
	while (true) 
	{
		car.flickerEscape();
		car.objectsCreate();
		car.carMove();
		car.keyPress();
		car.checker();
		car.refresher();
		car.startCheck();
	}
	return 0;
}