// Workshop <Milestone 2>
// Name: <Yuan-Hsi Lee>
// Student #: <106936180>
// Course: OOP244 Winter 2019
// File: <ErrorState.h>

#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H

#include <iostream>

namespace ama{

	class ErrorState{

		char *eMessage;
		//user defined member function
		void messageCopy(const char* value);

	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& other) = delete;
		ErrorState& operator=(const ErrorState& other) = delete;
		~ErrorState();
		operator bool() const;
		ErrorState& operator=(const char* pText);
		void message(const char* pText);
		const char* message() const;

		friend std::ostream& operator<<(std::ostream& os, const ErrorState& erText);
	};

}

#endif
