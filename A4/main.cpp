#include <iostream>
#include "list.h"
using namespace std;

int main()
{
	const float BIAS = 0.5;
	const float STEP = 0.1;
	const float SLOPE = 0.01;
	const int NODES = 5;

	// create a list with 10 9 degree steps
	List LL[10];

	double leastError = 0;	// holds value of the least error
	float xError = 0;		// holds x position of the least error

	// create grid
	for (int i = 0; i < sizeof(LL) / sizeof(List); i++) {
		float x = i * STEP;
		LL[i].createList(x, BIAS, SLOPE, NODES);

		// if new error value is less than the current one, assign new value
		if (LL[i].getError() < leastError || leastError == 0) {
			leastError = LL[i].getError();
			xError = x;
		}
			
	}

	// display grid
	for (int i = 0; i < sizeof(LL) / sizeof(List); i++) {
		float x = i * STEP;
		cout << "X= " << setprecision(1) << fixed << x << ": ";
		LL[i].display(false);
	}
	cout << endl;

	// display least error
	cout << "the value of x with the least error is X= " << setprecision(1) << xError << ": " << setprecision(6) << leastError << endl;

	return 0;
}