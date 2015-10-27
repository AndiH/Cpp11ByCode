/**
 * @brief C++11 Example: Constructor Delegation
 * 
 * Also two ways of defaulting member variables with C++11
 * 
 * See also:
 * 	* https://en.wikipedia.org/wiki/C%2B%2B11#Object_construction_improvement
 * 
 * @author Andreas Herten <a.herten@gmail.com>
 * @date 27 Oct 2015
 */
#include <iostream>

class A {
public:
	A() {std::cout << "Initializing A!" << std::endl;};
	A(int _a) : A() {  // the constructor with int argument calls the simple constructor form above
		a = _a;
		std::cout << "a was also set to " << a << std::endl;
	};

	void WhatIsa() {std::cout << "a is " << a << std::endl;}
private:
	int a = 42;  // this is also new in C++11
};

// Following, an alternative to the default via the "int a = 42" expression, offloading the default value declaration from the class interface to the class implementation; might be beneficial for some cases
class B {
public:
	B() : B(42) {std::cout << "Initializing B!" << std::endl;};
	B(int _b) : b(_b) {std::cout << "b was also set to " << b << std::endl;};

	void WhatIsb() {std::cout << "b is " << b << std::endl;}
private:
	int b;
};

int main() {
	A a1;
	a1.WhatIsa();
	A a2(1);
	a2.WhatIsa();

	B b1;
	b1.WhatIsb();
	B b2(2);
	b2.WhatIsb();
}
