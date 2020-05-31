#include "ArrayTests.h"

#include <string>
#include <limits>
#include "Array.hpp"
#include "PrintC.hpp"
#include "Messages.hpp"

bool ArrayTests::ConstructorAndDestructor() {
	try {
		Array<int> array = Array<int>(0);
		array.~Array();

		array = Array<int>(54);
		array.~Array();

		array = Array<int>(INT_MAX);
		array.~Array();
	}
	catch (...) {
		Messages::Exception();
		return false;
	}
	Messages::Success();
	return true;
}


bool ArrayTests::PushAndPopArray() {
	Array<int> array = Array<int>();
	const int testNum = 7;

	try {
		for (int i = 1; i <= testNum; i++) {
			array.PushBack(i);
		}

		int pop;
		for (int i = testNum; i >= 1; i--) {
			pop = array.PopBack();
			if (pop != i) {
				Messages::ExpectedActual(i, pop);
				return false;
			}
		}
	}
	catch (...) {
		Messages::Exception();
		return false;
	}

	Messages::Success();
	return true;
}


bool ArrayTests::CheckArraySize() {
	try {
		int resizeValue;
		Array<int> array;
		if (array.GetSize() != 0) {
			Messages::ExpectedActual((unsigned int)0, array.GetSize());
			return false;
		}

		resizeValue = 50;
		array = Array<int>(resizeValue);
		if (array.GetSize() != resizeValue) {
			Messages::ExpectedActual((unsigned int)resizeValue, array.GetSize());
			return false;
		}

		resizeValue = 44;
		array.Resize(resizeValue);
		if (array.GetSize() != resizeValue) {
			Messages::ExpectedActual((unsigned int)resizeValue, array.GetSize());
			return false;
		}
	}
	catch (...) {
		PrintC("Failed" << std::endl << "Exception thrown" << std::endl, TextColor::red);
		return false;
	}
	PrintC("Success" << std::endl, TextColor::green);
	return true;
}


bool ArrayTests::ResizeArray() {
	try {
		Array<int> array = Array<int>(100);
		array.Resize(0);
		
	}
	catch (...) {

	}
	return false;
}


bool ArrayTests::CheckArrayLength() {
	printf("No Implementation\n");
	return false;
}


bool ArrayTests::AssignAndAccessArray() {
	printf("No Implementation\n");
	return false;
}


bool ArrayTests::AddPastArraySize() {
	printf("No Implementation\n");
	return false;
}

bool ArrayTests::AddBelowArraySize() {
	printf("No Implementation\n");
	return false;
}


bool ArrayTests::AssignmentOperator() {
	printf("No Implementation\n");
	return false;
}


bool ArrayTests::RunAllTests() {
	
	PrintW("Begining Array Tests..." << std::endl)
	
	int testCount = 0;
	int successCount = 0;

	auto runTest = [&](bool (*test)(void)) {
		testCount++;
		if ((*test)() == true)
			successCount++;
	};

	PrintW("ConstructorAndDestructor.....");
	runTest(ConstructorAndDestructor);
	PrintW("PushAndPopArray.....");
	runTest(PushAndPopArray);
	PrintW("CheckArraySize.....");
	runTest(CheckArraySize);

	return false;
}