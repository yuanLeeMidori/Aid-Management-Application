// Workshop <Milestone 2>
// Name: <Yuan-Hsi Lee>
// Student #: <106936180>
// Course: OOP244 Winter 2019
// File: <ErrorState.cpp>

#include <iostream>
#include <cstring>
#include <iomanip>

#include "ErrorState.h"

using namespace std;

namespace ama{

	ErrorState::ErrorState(const char* errorMessage){

		eMessage = nullptr;

		if (errorMessage == nullptr || strlen(errorMessage) == 0)
			return;

		if (strlen(errorMessage) > 0)
			messageCopy(errorMessage);
	}


	ErrorState::~ErrorState(){

		if (eMessage != nullptr){

			delete[] eMessage;
			eMessage = nullptr;
		}
	}


	void ErrorState::messageCopy(const char* value){

		if (eMessage != nullptr){

			delete[] eMessage;
			eMessage = nullptr;
		}

		if (value == nullptr)
			return;

		if (strlen(value) > 0){

			eMessage = new char[strlen(value) + 1];
			strcpy(eMessage, value);
		}
	}


	ErrorState::operator bool() const{

		if (eMessage != nullptr && strlen(eMessage) != 0)
			return true;

		return false;
	}


	ErrorState & ErrorState::operator=(const char * pText){

		message(pText);

		return *this;
	}


	void ErrorState::message(const char* pText){

		messageCopy(pText);
	}


	const char* ErrorState::message() const{

		if (eMessage == nullptr || strlen(eMessage) == 0)
			return nullptr;

		return eMessage;
	}


	ostream& operator<<(ostream& os, const ErrorState& em){

		if (em.eMessage != nullptr && strlen(em.eMessage) != 0){

			os << em.eMessage;
		}
		return os;
	}
}
