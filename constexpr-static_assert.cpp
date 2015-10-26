/**
 * @brief C++11 Example: constexpr, static_assert
 * 
 * Further reading:
 *   * http://www.stroustrup.com/C++11FAQ.html#constexpr
 *   * http://stackoverflow.com/a/4748291/1548394
 * 
 * @author Andreas Herten <a.herten@gmail.com>
 * @date 26 Oct 2015
 */
#include <iostream>
#include <cstdlib>

constexpr int product(int a, int b) {return a * b;};

int main() {
	std::cout << product(2, 3) << std::endl;  // evaluated during compile-time

	std::srand(std::time(0));
	int somevalue = product(std::rand(), 5);
	std::cout << somevalue << std::endl;  // not

	static_assert(product(2, 3) == 6, "That calculation is not right!");
	// static_assert(product(std::rand(), 5) == somevalue, "That calculation is not right!");  // This fails during compile time
}
