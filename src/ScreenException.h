#ifndef SCREEN_EXCEPTION_H
#define SCREEN_EXCEPTION_H

#include <string>

class ScreenException {
	public:
		ScreenException(std::string message) : message(message) {
		}

		std::string getMessage() { 
			return message; 
		}

	private:
		std::string message;
};

#endif
