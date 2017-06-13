#include "Battery.h"
#include<iostream>
#include <list>     // подключаем заголовок списка
#include <iterator> // заголовок итераторов


Battery::Battery()
{
	statusBattery = false;
	power = 1000;
}


Battery::~Battery()
{
}



void Battery::set_val(int value)
{
	if (value>=0)
	power -= value;
	if (value < 0)
		power -= value;
	if (power < 0)
		statusBattery = false;
	notify();
}
void Battery::attach(Electric *obs)
{
	if (obs->getStatus() == true)
	{
		e_device.push_back(obs);
		set_val(obs->getPower());
	}
	else if (obs->getStatus() == false)
	{
		e_device.remove(obs);
		set_val(-(obs->getPower()));
	}

}
void Battery::notify()
{
	for (auto &i : e_device)
		i->update(statusBattery);

}
void Battery::printStatus()
{
	std::cout << "Status battery ";
	switch (statusBattery)
	{
	case true:	std::cout << "ON power: " <<power<< std::endl;
		break;
	case false:	
		
		std::cout << "OFF power: 0" <<  std::endl;
		break;
	}
}

void Battery::OnBattery()
{
	if(power>=0)
	statusBattery = true;
	notify();

}

void Battery::OffBattery()
{
	statusBattery = false;
	notify();
}