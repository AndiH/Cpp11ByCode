/**
 * @brief C++11 Example: Class keywords: override, final, delete, default
 * 
 * How to read this document:
 * Since this is about classes, reading this file is not as straight forward as the other files. Start in main() for a refresher on how 'virtual' works (classes A and B), then look at the class definitions for the implementation of this. Continue to 'override' and 'final' in the class definitions. Finally, see what 'default' and 'delete' does in the class definitions.
 * 
 * @author Andreas Herten <a.herten@gmail.com>
 * @date 26 Oct 2015
 */

#include <iostream>

// ### Basic polymorphism
class A {
public: 
	virtual void f(int _value) {std::cout << "A::f <int>: " <<  _value << std::endl;}
	void g(int _value) {std::cout << "A::g <int>: " <<  _value << std::endl;}
};

class B : public A {
public:
	void f(int _value) {std::cout << "B::f <int>: " <<  _value << std::endl;}
	void g(int _value) {std::cout << "B::g <int>: " <<  _value << std::endl;}
};

// ### OVERRIDE
class C : public A {
public:
	// virtual void f(float) override {std::cout << "B::f <float>" << std::endl;}  // "override" tells the compiler that this method should override another method; since it does not in this case (notice float vs. int; this method is overloaded), the compiler errors out
	void f(int _value) override {std::cout << "C::f <int>: " << _value << std::endl;}  // this works, as B::f(int) overrides A::f(int)
};

// ### FINAL
class D : public A {
public:
	virtual void f(int _value) final {std::cout << "D::f <int>: " << _value << std::endl;}  // "final" declares the end of the line; this is the last allowed override of f(), any further inheritance will error
};
class E : public D {
public:
	// virtual void f(int _value) {std::cout << "E::f <int>: " << _value << std::endl;}  // not allowed, because D::f() was delcared "final"; compiler error
};

// ### DEFAULT, DELETE
// See, e.g., http://www.stroustrup.com/C++11FAQ.html#default
class F {
public:
	F() = default;
	F(int _a) : a(_a) {std::cout << "Constructed with " << a << std::endl;};
	virtual ~F() = default;

	F(double) = delete;

private:
	int a;
};


int main() {
	A a;
	a.f(1);
	a.g(2);

	B b;
	b.f(3);
	b.g(4);

	A & ba = b;
	ba.f(5);  // because A::f was declared virtual, this also calls B::f, as opposed to ...
	ba.g(6);  // ... this, which calls the 'original' A::g
	ba.A::f(7);  // if you really do want to call A::f, this can still be done like this 

	F f1;
	F f2(2);
	// F f3((float)3.14);  // compiler error, since this constructor has explicitly been deleted
}
