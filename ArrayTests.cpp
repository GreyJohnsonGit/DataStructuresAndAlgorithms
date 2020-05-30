#include "ArrayTests.h"

#include <string>
#include "Array.hpp"
#include "PrintC.hpp"


bool ArrayTests::ConstructorAndDestructor() {
	try {
		Array<int> array = Array<int>(8);
		array.~Array();
	}
	catch (...) {
		PrintC("Failed: Array could not be created then destroyed\n", TextColor::red);
		return false;
	}
	PrintC("Success: Array successfully created\n", TextColor::green);
	return true;
}


bool ArrayTests::PushAndPopArray() {
	Array<int> array = Array<int>(5);
	const int testNum = 5;

	try {
		for (unsigned int i = 1; i <= 5; i++) {
			array.PushBack(i);
		}

		for (unsigned int i = 5; i >= 1; i--) {
			if (array.PopBack() != i) {
				PrintC("Failed: Inaccurate pops", TextColor::red);
				return false;
			}
		}
	}
	catch (...) {
		PrintC("Failed: Exception thrown\n", TextColor::red);
		return false;
	}

	PrintC("Success: Push and pop success", TextColor::green);
	return true;
}


bool ArrayTests::ResizeArray() {
	printf("No Implementation\n");
	return false;
}


bool ArrayTests::CheckArraySize() {
	Array<int> array;
	if (array.GetSize() != 0) {
		PrintC("Failed: Array size not initialized to 0\n", TextColor::red);
		return false;
	}

	array = Array<int>(50);
	if (array.GetSize() != 50) {
		PrintC("Failed: Array size not properly set\n", TextColor::red);
		return false;
	}

	PrintC("Success: Array size properly modified\n", TextColor::green);
	return true;
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
	
	PrintC("Begining Array Tests...\n");
	
	int testCount = 0;
	int successCount = 0;

	auto runTest = [&](bool (*test)(void)) {
		testCount++;
		if ((*test)() == true)
			successCount++;
	};

	PrintC("ConstructorAndDestructor.....");
	runTest(ConstructorAndDestructor);
	PrintC("PushAndPopArray.....");
	runTest(PushAndPopArray);

	return false;
}