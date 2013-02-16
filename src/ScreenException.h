#ifndef SCREEN_EXCEPTION_H
#define SCREEN_EXCEPTION_H

#include <string>

class ScreenException {
  std::string _message;

	public:
		ScreenException(std::string message) : _message(message) {
		}

		std::string getMessage() { 
			return _message; 
		}

};

#endif
