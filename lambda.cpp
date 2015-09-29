/**
 * @brief C++11 Example: Lambda expressions
 * 
 * @author Andreas Herten <a.herten@gmail.com>
 * @date 29 Sep 2015
 */
#include <iostream>
#include <vector>
#include <algorithm>

struct something {  // read at invokation below
	std::vector<int> a;
	void SetB(int _b) {b = _b;};

	void PrintSomething() {
		std::for_each(a.begin(), a.end(), [this] (int a0) -> void {
			std::cout << "b: " << b << ", a_i: " << a0 << std::endl;
		});
	};
private:
	int b;
};

int main() {
	auto x = [] () {std::cout << "This is x!" << std::endl;};  // Simple lambda function without any parameters...
	x();  // ... which is called like this
	[] () {std::cout << "This is y!" << std::endl;} ();  // can be also created anonymously and called in-place

	std::vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	std::for_each(a.begin(), a.end(), [] (int & a1) {
		std::cout << a1++ << std::endl;
	});  // work very well with STL functions; a[i] is captured by reference, using the &

	auto coutByValue = [] (int a2) {
		std::cout << a2 << std::endl;
	};  // lambda function can also be declared like this (note: there's no & between int and a2; so a2 is captured by copy)
	std::for_each(a.begin(), a.end(), coutByValue);  // ... and used like this multiple times

	std::string b = "Number";
	std::for_each(a.begin(), a.end(), [&b] (int a3) {
		std::cout << b << ": " << a3 << std::endl;
	});  // parent-scope variables are captured in the square brackets, here b by reference

	int c = 4;
	std::transform(a.begin(), a.end(), a.begin(), [&c, b] (int & a4) -> int {
		return a4 + c++;
	});  // parent-scope variables can be explicitly captured by reference or by copy; also, the return type is being given here (unnecessarily); notice that c changes for every call since it's captured by reference
	std::for_each(a.begin(), a.end(), coutByValue);

	std::for_each(a.begin(), a.end(), [&] (int a5) {  // & captures all parent-scope variables by reference; = does so by copy; this can be mixed as well, like [&, b]
		b = "Capture all parent-scope variables by reference";
		std::cout << b << ": " << a5 + c++ << std::endl;
	});

	something B;
	B.a = a;
	B.SetB(20);
	B.PrintSomething();  // The lambda function inside of this method has the this pointer, enabling access to all member variables of the class
}
