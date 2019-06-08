// Workshop <Milestone 3>
// Name: <Yuan-Hsi Lee>
// Student #: <106936180>
// Course: OOP244 Winter 2019
// File: <Utilities.h>

#ifndef AMA_UTILITIES_H
#define AMA_UTILITIES_H

#include <ostream>
#include "Product.h"

using namespace std;

namespace ama{

	double& operator+=(double& total, const iProduct& prod);
	ostream& operator<<(ostream& out, const iProduct& prod);
	istream& operator>>(istream& in, iProduct& prod);

	iProduct* createInstance(char tag);
}

#endif
