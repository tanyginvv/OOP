#include "stdafx.h"
#include "RemoteControl.h"
#include "Car.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Car car;
	CRemoteControl remoteControl(car, cin, cout);

	return 0;
}
