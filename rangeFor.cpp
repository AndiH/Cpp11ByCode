/**
 * @brief C++11 Example: ranged for loops
 * 
 * @author Andreas Herten <a.herten@gmail.com>
 * @date 28 Sep 2015
 */
#include <iostream>
#include <vector>
#include <map>
#include <string>

int main() {
	std::vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	for(int ia : a)  // new syntax, for() is a new a implicit for_each()
		std::cout << ia << std::endl;
	std::cout << std::endl;

	for(int & ia : a)  // works also with references
		std::cout << ia++ << std::endl;
	std::cout << std::endl;
	
	for(int ia : a)  // see? content of a has changed
		std::cout << ia << std::endl;
	std::cout << std::endl;

	std::map<std::string, int * > b;
	b["hello"] = new int(3);
	for (auto & ib : b)  // especially useful with the new auto keyword
		std::cout << ib.first << " -> " << * ib.second << std::endl;
}
