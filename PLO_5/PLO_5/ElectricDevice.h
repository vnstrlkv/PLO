#pragma once
#include<iostream>
#include "Battery.h"
#include "Electric.h"

class ElectricDevice : public Electric
{
protected:
	char* name;

public:
	ElectricDevice();
	ElectricDevice(char* tmpname, int tmppower);
	ElectricDevice(Battery *obj);
	~ElectricDevice();
	void OnDevice(Battery *obj);
	void OffDevice(Battery *obj);
	void update(bool status);
	int getPower();
	bool getStatus();
};