/**
 * @brief C++11 Example: Smart Pointers (unique_ptr, shared_ptr, weak_ptr)
 * 
 * Also see: http://www.codeproject.com/Articles/541067/Cplusplus-Smart-Pointers
 * @author Andreas Herten <a.herten@gmail.com>
 * @date 5 Oct 2015
 */
#include <memory>
#include <iostream>

struct A {  // a struct enabling visualizing construction and destruction of an object
	A (const int & _a) : a(_a) {
		std::cout << "An object of A with value " << a << " is being created." << std::endl;
	}
	~A () {
		std::cout << "An object of A with value " << a << " is being destroyed." << std::endl;
	}
	const int a;
};

int main() {
	A * x = new A(-1);  // a "plain old pointer" which is created, but never deleted


	// ### UNIQUE pointers
	// unique pointers can have only one owner
	std::unique_ptr<int> a(new int(0));  // memory is allocated as usual by "new"
	a.get();  // gets the pointer, for conversion to old-styled pointer thingys

	std::unique_ptr<A> b(new A(1));
	std::cout << "The value b is pointing to is: " << (*b).a << std::endl;  // smart pointers can be used as usual pointers, so b->a will work
	
	std::unique_ptr<A> c(new A(2));
	// std::unique_ptr<A> d = c;  // not possible, because ownership transfer is not possible like this; the pointer wouldn't be unique
	std::unique_ptr<A> d = std::move(c);  // the ownership must be explicitly moved by this new STL function
	d.reset();  // deletes memory, d is pointing to
	std::cout << "d was reset before this line." << std::endl;
	if (c == nullptr)  // "if (!c)" works as well
		std::cout << "c is the null pointer." << std::endl;
	c.reset();  // has no effect


	// ### SHARED pointers
	// shared pointers can have many owners
	std::shared_ptr<A> e(new A(3));
	std::shared_ptr<A> f = e;  // now, f and e both own the memory
	std::cout << "Use count of e: " << e.use_count() << "; is e unique?: " << e.unique() << std::endl;

	f.reset();  // memory still allocated, since e is existing
	std::cout << "Use count of e: " << e.use_count() << "; is e unique?: " << e.unique() << std::endl;
	e.reset();  // but now it is freed

	std::shared_ptr<A> ff(new A(33), [] (A * p) {std::cout << "This function is called at destruction, replacing the usual destructor!" << std::endl;});  // optional second argument which also accepts a new lambda function
	std::shared_ptr<int> fff(new int[3], [] (int * p) {delete[] p;});  // useful for arrays

	auto g = std::make_shared<A>(4);  // this allocates memory for the smart pointer and the underlying shared object at once; "auto" is a new C++11 keyword for the lazy
	auto h = std::make_shared<A>(5);
	g.swap(h);
	std::cout << "Content of g: " << g->a << ", content of h: " << h->a << std::endl;

	g.reset(new A(6));  // reset can also be used to re-initialize after deleting the old value


	// ### WEAK pointers
	// weak pointers are copies of shared pointers, but having no effect on the shared pointers
	// handy resource: http://stackoverflow.com/a/21877073 and https://en.wikipedia.org/wiki/Smart_pointer
	std::weak_ptr<A> i = h;  // i points to data, but h still owns the memory
	std::cout << "Use count of h: " << h.use_count() << std::endl;  // use count is 1

	h.reset(new A(7));  // old memory is deleted, new memory is acquired
	std::weak_ptr<A> j = h;
	std::cout << "Because of the reset, i is expired (i_expired == " << i.expired() << "), whereas j is still pointing to data (j_expired == " << j.expired() << ")" << std::endl;

	std::shared_ptr<A> k = i.lock();  // i needs to be locked, in order to access the memory behind the pointer; a shared_ptr is returned (use "auto")
	std::cout << "Since the memory behind i was freed, k is pointing to " << (k ? "somewhere" : "nowhere") << std::endl;
	std::shared_ptr<A> l = j.lock();
	std::cout << "But j is still there, hence l is pointing to " << (l ? "somewhere" : "nowhere")  << std::endl;
}
