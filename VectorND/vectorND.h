#pragma once

#include <iostream>
#include <numeric>



template <typename T, unsigned int N>
class Vector
{
public:
	Vector();
	template <typename ... Args>
	Vector(const Args&... args);

	void print();

public:
	T X[N] = {static_cast<T>(0)};

	Vector operator+(const Vector& v)
	{
		static_assert(std::is_same<decltype(v), Vector<T, N>>::value == 0, "Vectors must be the same size");

		Vector ret;
		for (int i = 0; i < N; ++i)
		{
			ret.X[i] = X[i] + v.X[i];
		}

		return ret;
	}

	void operator+=(const Vector& v)
	{
		static_assert(std::is_same<decltype(v), Vector<T, N>>::value == 0, "Vectors must be the same siz");

		for (int i = 0; i < N; ++i)
		{
			X[i] += v.X[i];
		}
	}

	Vector operator-(const Vector& v)
	{
		static_assert(std::is_same<decltype(v), Vector<T, N>>::value == 0, "Vectors must be the same siz");

		Vector ret;
		for (int i = 0; i < N; ++i)
		{
			ret.X[i] = X[i] - v.X[i];
		}

		return ret;
	}

	void operator-=(const Vector& v)
	{
		static_assert(std::is_same<decltype(v), Vector<T, N>>::value == 0, "Vectors must be the same siz");

		for (int i = 0; i < N; ++i)
		{
			X[i] -= v.X[i];
		}
	}

	Vector operator*(const T& t)
	{
		Vector ret;
		for (int i = 0; i < N; ++i)
		{
			ret.X[i] = X[i] * t;
		}

		return ret;
	}

	void operator*=(const T& t)
	{
		for (int i = 0; i < N; ++i)
		{
			 X[i] *= t;
		}
	}

	/* Cross product */
	Vector operator^(const Vector& v)
	{
		static_assert(std::is_same<decltype(v), Vector<T, N>>::value == 0, "Vectors must be the same siz");
		static_assert(N == 3, "Can not cross product vectors wich dimensions are different than 3");

		Vector ret;

		ret.X[0] = X[1] * v.X[2] - X[2] * v.X[1];
		ret.X[1] = X[0] * v.X[2] - X[2] * v.X[0];
		ret.X[2] = X[0] * v.X[1] - X[1] * v.X[0];

		return ret;
	}

	/* Dot product */
	T operator*(const Vector& v)
	{
		static_assert(std::is_same<decltype(v), Vector<T, N>>::value == 0, "Vectors must be the same siz");

		return std::inner_product(std::begin(X), std::end(X), std::begin(v.X), static_cast<T>(0));
	}
};


