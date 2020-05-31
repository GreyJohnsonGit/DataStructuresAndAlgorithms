#ifndef MESSAGES
#define MESSAGES

#include <iostream>
#include "PrintC.hpp"

struct Messages {

	template <class T> static void ExpectedActual(T expected, T actual) {
		PrintC("Failed" << std::endl << "Expected " << expected << " Actual " << actual << std::endl, TextColor::red);
	}

	static void Exception() {
		PrintC("Failed" << std::endl << "Exception thrown" << std::endl, TextColor::red);
	}

	static void Success() {
		PrintC("Success" << std::endl, TextColor::green);
	}
};

#endif
