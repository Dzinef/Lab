#include "header1.h"

int32_t main() {
	const int32_t MAX_SIZE{ 100 };
	int32_t choice{}, size{};

	EnterSize(size);
	if (!CheckSize(size))
		return 0;
    int32_t* arr = new int32_t[size];
	double* arr_double = new double[size];

	std::cout << "Enter choice (0 - Dynamic, 1 - Static)\n";
	EnterNumber(choice);

	switch (choice) {
	case 0:
		std::cout << "Enter choice (0 - Auto, 1 - Manually)\n";
		EnterNumber(choice);
		if (!CheckChoice(choice))
			return 0;
		if (choice == 1)
			InputArray(arr_double, size);
		else {
			int32_t right{}, left{};
			InputElements(right, left);
			FillArray(arr_double, size, right, left);
		}
		std::cout << "Summ of positive elements = " << SummOfArrayPos(arr_double, size) << std::endl;
		std::cout << "Multiplication = " << Multiplication(arr_double, size) << std::endl;
		std::cout << "Sorted Array = ";
		SortElements(arr_double, size);
		DeleteArray(arr_double);
		EnterSize(size);
		if (!CheckSize(size)) {
			return 0;
		}
		std::cout << "Enter choice (0 - Auto, 1 - Manually)\n";
		EnterNumber(choice);
		if (!CheckChoice(choice))
			return 0;
		if (choice == 1)
			InputArray(arr, size);
		else {
			int32_t right{}, left{};
			InputElements(right, left);
			FillArray(arr, size, right, left);
		}
		std::cout << "Quantity of different elements = " << DifferentElements(arr, size) << std::endl;
		std::cout << "Multiplication after Max element = " << MultiplicationAfter(arr, size) << std::endl;
		std::cout << "Sort Negativse = ";
		SortArrayNegativse(arr, size);
		DeleteArray(arr);
		break;
	case 1:
		double array_double[MAX_SIZE];
		int32_t array[MAX_SIZE];
		std::cout << "Enter choice (0 - Auto, 1 - Manually)\n";
		EnterNumber(choice);
		if (!CheckChoice(choice))
			return 0;
		if (choice == 1)
			InputArray(array_double, size);
		else {
			int32_t right{}, left{};
			InputElements(right, left);
			FillArray(array_double, size, right, left);
		}
		std::cout << "Summ of positive elements = " << SummOfArrayPos(array_double, size) << std::endl;
		std::cout << "Multiplication = " << Multiplication(array_double, size) << std::endl;
		std::cout << "Sorted Array = "; 
		SortElements(array_double, size);
		EnterSize(size);
		if (!CheckSize(size)) {
			return 0;
		}
		std::cout << "Enter choice (0 - Auto, 1 - Manually)\n";
		EnterNumber(choice);
		if (!CheckChoice(choice))
			return 0;
		if (choice == 1)
			InputArray(array, size);
		else {
			int32_t right{}, left{};
			InputElements(right, left);
			FillArray(array, size, right, left);
		}
		std::cout << "Quantity of different elements = " << DifferentElements(array, size) << std::endl;
		std::cout << "Multiplication after Max element = " << MultiplicationAfter(array, size) << std::endl;
		std::cout << "Sort Negativse = ";
		SortArrayNegativse(array, size);
		break;
	default:
		std::cout << "Incorrect number\n";
	}
}