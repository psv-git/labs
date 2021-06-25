#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "../task/stdafx.h"

template <typename T>
bool LessByHeight(T s1, T s2)
{
	return s1->GetHeight() < s2->GetHeight();
}

template <typename T>
bool LessByWeight(T s1, T s2)
{
	return s1->GetWeight() < s2->GetWeight();
}

template <typename T, typename Less>
bool FindMaxEx(const std::vector<T>& arr, T& maxValue, const Less& less)
{
	if (arr.size() == 0)
	{
		return false;
	}
	maxValue = arr[0];
	for (size_t i = 1; i < arr.size(); i++)
	{
		if (less(maxValue, arr[i]))
		{
			maxValue = arr[i];
		}
	}
	return true;
}

#endif // FUNCTIONS_HPP
