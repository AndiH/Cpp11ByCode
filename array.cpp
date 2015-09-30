/**
 * @brief C++11 Example: std::array
 * 
 * @author Andreas Herten <a.herten@gmail.com>
 * @date 30 Sep 2015
 */
#include <iostream>
#include <array>

int main() {
	std::array<int, 3> a = {1, 2, 3};  // constructed, like C-style array, with braced list of number; length of array (second template argument) is defined during compile time (important for hardware-close optimization)
	for (std::array<int, 3>::iterator ia = a.begin(); ia != a.end(); ia++)  // provides begin() and end(), so it can be used with iterators and stuff; note: the definition of ia is much shorter using C++11's "auto"
		std::cout << *ia << std::endl;

	std::cout << "Size of array: " << a.size() << std::endl;  // does have .size() member method

	a[2] = 4;  // accessible with []

	std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, "\n"));  // one can use the STL functions now finally on a pretty much plain old array without any bone-breaking

	std::array<int, 4> b = {5, 6};  // non-specified elements are initialized to 0
	std::copy(b.begin(), b.end(), std::ostream_iterator<int>(std::cout, "\n"));

	int c = b[2];
	int * d = b.data();  // to get a pointer, use .data(), which points to the underlying array
	for (int id = 0; id < b.size(); id++)  // don't do this
		std::cout << *(d++) << std::endl;

	std::cout << "front() of b: " << b.front() << ", back() of b: " << b.back() << std::endl;

	std::cout << "b[5]: " << b[5] << std::endl;  // access without bounds checking
	std::cout << "b.at(5): " << b.at(5) << std::endl;  // access with bounds checking; fails
}
