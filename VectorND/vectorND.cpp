#include "VectorND.h"



template <typename T, unsigned int N>
Vector<T, N>::Vector()
{

}


template <typename T, unsigned int N>
template <typename ... Args>
Vector<T, N>::Vector(const Args&... args)
{
	static_assert(sizeof...(Args) == N, "Wrong arguments number");

	unsigned int i = 0;
	for (const auto& arg : { args... })
	{
		X[i++] = arg;
	}
}

template <typename T, unsigned int N>
void Vector<T, N>::print()
{
	for (auto&& x : X)
	{
		std::cout << x << " ";
	}

	std::cout << std::endl;
}