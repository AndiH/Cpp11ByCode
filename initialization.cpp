/**
 * @brief C++11 Example: Initialization with curly braces
 * 
 * @author Andreas Herten <a.herten@gmail.com>
 * @date 28 Sep 2015
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>

struct A {
	A(int a1, int a2) {
		std::cout << a1 * a2 << std::endl;
	}
};

struct B {
private:
	int b1[2] {1, 2};
public:
	B(int b2, std::string b3) {
		std::cout << b3 << ": " << b1[0] * b2 + b1[1] * b2 << std::endl;
	}
};

int main() {
	// Old ways of initializing:
	int a = 1;
	std::string b("two");
	int c [] = {3, 4};
	std::vector<int> d;
	d.push_back(5);
	d.push_back(6);
	d.push_back(7);
	A e(1, 2);

	// New ways of initializing:
	int f {8};  // curly braces...
	std::cout << f << std::endl;

	std::string g {"nine"};  // ... curly braces everywhere
	std::cout << g << std::endl;

	std::vector<int> h {10, 11, 12};  // makes std::vector initialization especially convenient
	std::copy(h.begin(), h.end(), std::ostream_iterator<int>(std::cout, "\n"));  // (showing off this handy copy-to-cout thingy)

	std::map<std::string, int> i { 
		{"thirteen", 13}, 
		{"fourteen", 14} 
	};  // initializing std::maps now is like writing JSON files, isn't it?

	int * j = new int[3] {15, 17, 19};  // can also be allocated like this
	std::cout << *j << ", " << *(++j) << ", " << *(j + 1) << std::endl;

	A k {20, 21};  // classes can be initialized as well
	B l {22, "result"};  // look into B where now the private variable b1 is defined with {}
}
