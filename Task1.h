#pragma once


template<typename T>
void Swap(T* firstPtr, T* secondPtr)
{
	T ptr_L = move(*firstPtr);
	*firstPtr = move(*secondPtr);
	*secondPtr = move(ptr_L);
}
