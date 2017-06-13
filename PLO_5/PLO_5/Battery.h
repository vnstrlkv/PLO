#pragma once
#include"Electric.h"
#include<list>
#include<vector>

class Battery
{
private:
	bool statusBattery;
	int power;
	std::list < class Electric * > e_device;
public:
	Battery();
	~Battery();
	void OnBattery();
	void OffBattery();
	void attach(Electric *device);
	void set_val(int value);
	void notify();
	void printStatus();
};