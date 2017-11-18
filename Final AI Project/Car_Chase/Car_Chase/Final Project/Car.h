#ifndef CAR_H
#define CAR_H

#include "Unit.h"

class CarComponent;
class RenderComponent;

class Car : public Unit
{
	private:
		CarComponent* mpCarComponent;
		RenderComponent* mpRenderComponent;

	public:
		Car(int locX, int locY);
		~Car();

		void render();
		void update();
};

#endif