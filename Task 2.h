#pragma once
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
void SortPointers(vector<T*>& v)
{
	sort(v.begin(), v.end(),
		[](T* left, T* right)
			{
				return *left < *right;
			});
}