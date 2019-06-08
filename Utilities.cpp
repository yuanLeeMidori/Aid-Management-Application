
// Workshop <Milestone 3>
// Name: <Yuan-Hsi Lee>
// Student #: <106936180>
// Course: OOP244 Winter 2019
// File: <Utilities.cpp>

#include <iostream>
#include "Utilities.h"

using namespace std;

namespace ama{

	double& operator+=(double& total, const iProduct& prod){

		total += prod.total_cost();
		return total;
	}


	ostream& operator<<(ostream& out, const iProduct& prod){

		return prod.write(out, write_human);
	}


	istream& operator>>(istream& in, iProduct& prod){

		return prod.read(in, true);
	}

	iProduct* createInstance(char tag) : Product{

		if(tag == 'N' || tag == 'n'){
			return new Product();
		}else if(tah == 'P' || tag == 'p'){

			return new Perishable();

		}else{
			return nullptr;
		}
	}
}
