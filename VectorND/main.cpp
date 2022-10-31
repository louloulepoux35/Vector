#include <cstdlib>
#include <iostream>
#include "VectorND.h"
#include "VectorND.cpp"


int main(int argc, char* argv[])
{
	Vector<int, 3> v3i(1, 0, 0);
	Vector<int, 3> v3i4(2, 2, 2);
	Vector<int, 3> v3i2(0, 1, 0);
	Vector<double, 4> v3d(2.3, 2.6, 3.8, 0.0);

	Vector<int, 3> v3i3 = v3i ^ v3i2;
	v3i *= 4;
	v3i.print();
	v3i3.print();
	int dotP = v3i * v3i4;
	std::cout << dotP;

	return 0;
}