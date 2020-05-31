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

	static void StartTest(std::string testName) {
		PrintW(testName.append("....."));
	}

	static void TestResults(int testCount, int successCount) {
		if (testCount == successCount) {
			PrintC("All tests passed. Passed:(" << successCount << "/" << testCount << ")" << std::endl, TextColor::green);
		}
		else {
			PrintC(testCount - successCount << " tests failed. Passed:(" << successCount << "/" << testCount << ")" << std::endl, TextColor::red);
		}
	}
};

#endif
