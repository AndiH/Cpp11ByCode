/**
 * @brief C++11 Example: begin(x) instead of x.begin()
 * 
 * @author Andreas Herten <a.herten@gmail.com>
 * @date 28 Sep 2015
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

struct PrintInt {
	void operator() (const int & i) {
		std::cout << i << std::endl;
	}
};
struct Square {
	template<class T>
	T operator() (T s) {
		return s*s;
	}
};

int main() {
	std::vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	for (std::vector<int>::iterator ia = begin(a); ia != end(a); ia++)  // begin(x) instead of x.begin()
		std::cout << * ia << std::endl;

	int b [] = {4, 5, 6};
	for (int * ib = std::begin(b); ib != std::end(b); ib++)  // using std::begin(), this also works for C-style arrays
		std::cout << * ib << std::endl;

	std::for_each(std::begin(b), std::end(b), PrintInt());  // enables usage of STL algorithms on arrays easily

	std::transform(std::begin(b), std::end(b), std::begin(b), Square());  // also in-place replacement is possible
	std::for_each(std::begin(b), std::end(b), PrintInt());
}
