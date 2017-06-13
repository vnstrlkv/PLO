#pragma once

class Electric
{
protected:
	//int index;
	bool status;
	int power;
public:
	virtual ~Electric() {};
	virtual void update(bool value) = 0;
	virtual int getPower() = 0;
	virtual bool getStatus() = 0;
};
