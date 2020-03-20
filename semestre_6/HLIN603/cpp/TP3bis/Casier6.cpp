#include "Casier.h"
#include <iostream>
#include <iomanip>
#include <cstddef>
using namespace std;

template<typename T>
Casier6<T>::Casier6(){
	for (int i = 0; i < 6; ++i)
	{
		cases[i] = nullptr;
	}
}

template<typename T>