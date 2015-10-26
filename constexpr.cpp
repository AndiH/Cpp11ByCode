/**
 * @brief C++11 Example: constexpr
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
	std::cout << product(std::rand(), 5) << std::endl;  // not
}
