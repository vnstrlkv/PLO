#include "ElectricDevice.h"
#include <Windows.h>
#include<ctime>


ElectricDevice::ElectricDevice()
{
	status = false;
	power = 400;
	name = "empty";
}

ElectricDevice::ElectricDevice(char* tmpname, int tmppower)
{
	name = tmpname;
	power = tmppower;
}

ElectricDevice::ElectricDevice(Battery *obj)
{
	power = 100;
	obj->attach(this);
}

ElectricDevice::~ElectricDevice()
{
}

int ElectricDevice::getPower()
{
	return power;
}

bool ElectricDevice::getStatus()
{
	return status;
}

void ElectricDevice::update(bool statusBattery)
{
	switch (statusBattery)
	{
	case true:
	{		
		status = true;
		std::cout<<name << "	status device: ON  " << status <<"| power "<<power<< std::endl;
	break;
	}
	case false:

	{		
	status = false;
	std::cout <<name<< "	status device: OFF " << status <<  "| power " << power << std::endl;
	break;
	}
	}
}


void ElectricDevice::OnDevice(Battery *obj)
{
	status = true;
	obj->attach(this);

}
void ElectricDevice::OffDevice(Battery *obj)
{
	status = false;
	obj->attach(this);
}
