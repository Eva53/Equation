#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

struct answer {
	double D;
	double x1;
	double x2;
};

struct coeffs {
	double a;
	double b;
	double c;
};

void Input(coeffs* data) {
	std::cout << "Enter coefficients:" << endl;
	std::cout << "a: ";
	std::cin >> data->a;
	std::cout << "b: ";
	std::cin >> data->b;
	std::cout << "c: ";
	std::cin >> data->c;
	return;
}

answer Equation(coeffs data) {
	answer root;
	root.D = data.b * data.b - 4.0 * data.a * data.c;
	/*if (root.D < 0)
	{

	}*/
	if (root.D == 0)
	{
		root.x1 = -data.b / (2.0 * data.a);
		root.x2 = root.x1;
	}
	if (root.D > 0)
	{
		root.x1 = (-data.b + sqrt(root.D)) / (2.0 * data.a);
		root.x2 = (-data.b - sqrt(root.D)) / (2.0 * data.a);
	}
	return root;
}

void PrintRoots(answer root) {
	if (root.D < 0) {
		std::cout << "The equation has no roots" << endl;
	}
	if (root.D == 0) {
		std::cout << "The equation has only root: " << root.x1 << endl;
	}
	if (root.D > 0) {
		std::cout << "The equation has two roots: " << root.x1 << " and " << root.x2 << endl;
	}
}

int main()
{
	coeffs data;
	answer root;
	Input(&data);
	root = Equation(data);
	PrintRoots(root);
	return 0;
}