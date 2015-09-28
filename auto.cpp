/**
 * @brief C++11 Example: auto and decltype()
 * 
 * @author Andreas Herten <a.herten@gmail.com>
 * @date 28 Sep 2015
 */
#include <iostream>
#include <vector>

int main() {
	auto a = 1;  // a is of type int
	const auto b = 2.3;  // b is of type const double
	auto c = "hello";  // c is of type char
	auto d = new float(4.2);  // d is of type * float
	decltype(b) e = 3.1415;  // e is of the same type as b (const double)

	std::vector<int> v;
	v.push_back(a);
	v.push_back(b);  // implicitly converted to int
	v.push_back(*d);  // implicitly converted to int
	v.push_back(e);  // implicitly converted to int
	for (auto v_it = v.begin(); v_it != v.end(); v_it++)
		std::cout << * v_it << std::endl;

}
