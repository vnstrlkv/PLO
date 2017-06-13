#include <iostream>
#include <vector>
#include<Windows.h>
#include <stdio.h>
#include <conio.h>

#include"ElectricDevice.h"
#include"Electric.h"
#include"Battery.h"


using namespace std;


int main()
{  
	Battery bat;
	ElectricDevice TV("TV", 300);
	ElectricDevice Teapot("Teapot", 250);
	ElectricDevice PC("PC", 450);
	ElectricDevice Cooler("Cooler", 340);

	bat.printStatus();
	cout << endl;
	cout << endl << "ON Batt"<<endl;
	bat.OnBattery();
	bat.printStatus();
	cout << endl;
	cout << endl << "Plug TV" << endl;
	TV.OnDevice(&bat);
	bat.printStatus();
	cout << endl;
	cout << endl << "Plug PC" << endl;
	PC.OnDevice(&bat);
	bat.printStatus();
	cout << endl;
	cout << endl << "Plug Teapot" << endl;
	Teapot.OnDevice(&bat);
	bat.printStatus();
	cout << endl;
	cout << endl << "Plug Cooler" << endl;
	Cooler.OnDevice(&bat);
	bat.printStatus();
	cout << endl;
	cout << endl << "UNPlug Teapot" << endl;
	Teapot.OffDevice(&bat);
	bat.printStatus();
	cout << endl;
	cout << endl << "UNPlug Cooler" << endl;
	Cooler.OffDevice(&bat);
	bat.printStatus();
	cout << endl;
	cout << endl << "ON Batt" << endl;
	bat.OnBattery();
	bat.printStatus();
	cout << endl;
	cout << endl << "OFF Batt" << endl;
	bat.OffBattery();
	bat.printStatus();



	system("pause");
}

