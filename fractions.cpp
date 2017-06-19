#include <iostream>
#include <fstream>

class fraction; 
int plus(fraction a, fraction b); 
int minus(fraction a, fraction b); 
int times(fraction a, fraction b);
int divide(fraction a, fraction b);

class fraction {
public: 
	fraction()
	{
		a = 0; 
		b = 1; 
	}
	fraction(int input_a, int input_b)
	{
		a = input_a; 
		b = input_b; 
	}

	int operator+(fraction input_b)
	{
		return plus(*this, input_b); 
	}
	int operator-(fraction input_b)
	{
		return minus(*this, input_b); 
	}
	int operator*(fraction input_b)
	{
		return times(*this, input_b); 
	}
	int operator/(fraction input_b)
	{
		return divide(*this, input_b); 
	}
	
	int get_a()
	{
		return a; 
	}
	int get_b()
	{
		return b; 
	}
		
private: 
	int a; 
	int b; 
};

void byebyeData(std::ostream& out, int a)
{
	out << a; 
}

int plus(fraction a, fraction b)
{
	return int(((a.get_a() * b.get_b()) + (a.get_b() * b.get_a())) / (a.get_b() * b.get_b())); 
}
int minus(fraction a, fraction b)
{
	return int((a.get_a()*b.get_b()) - (a.get_b()*b.get_a())) / (a.get_b()*b.get_b());
}
int times(fraction a, fraction b)
{
	return int((a.get_a()*b.get_a()) / (b.get_b()*a.get_b())); 
}
int divide(fraction a, fraction b)
{
	return int((a.get_a()*b.get_b()) / (a.get_b()*b.get_a())); 
}

bool GreaterThan(fraction a, fraction b)
{
	if ((a.get_a() / a.get_b()) > (b.get_a() / b.get_b()))
	{
		return true; 
	}
	else return false; 
}

int main()
{
	fraction a(8, 2); 
	fraction b(2, 2); 
	std::cout << "a+b = " << a + b << std::endl; 
	std::cout << "a-b = " << a - b << std::endl;
	std::cout << "a*b = " << a * b << std::endl;
	std::cout << "a/b = " << a / b << std::endl;

	std::ofstream outputData("Fractions"); 
	byebyeData(outputData, (a + b)); 
	byebyeData(outputData, (a - b));
	byebyeData(outputData, (a * b));
	byebyeData(outputData, (a / b));

	if (GreaterThan(a, b)
	{
		std::cout << "WOOT"; 
	}
	else
	{
		std::cout << "ha"; 
	}
	
	/*std::ofstream outputData("Fractions"); 
	outputData << "a+b = " << a + b << std::endl;
	outputData << "a-b = " << a - b << std::endl;
	outputData << "a*b = " << a * b << std::endl;
	outputData << "a/b = " << a / b << std::endl;

	outputData.close(); */

	return 0; 
}
