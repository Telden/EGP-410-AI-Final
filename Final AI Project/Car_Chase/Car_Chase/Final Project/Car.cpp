#include "Car.h"
#include "CarComponent.h"
#include "RenderComponent.h"

Car::Car(int locX, int locY)
{

	setLocX(locX);
	setLocY(locY);

	mpCarComponent = new CarComponent(this);
	mpRenderComponent = new RenderComponent(this);
}

Car::~Car()
{
	delete mpCarComponent;
}

void Car::render()
{
	mpRenderComponent->render();
}

void Car::update()
{
	mpCarComponent->update();
}