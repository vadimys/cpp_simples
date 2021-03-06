#include "stdafx.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

#pragma region test1
struct A
{	
	A() { cout << "A()" << endl; }
	virtual ~A() { cout << "~A()" << endl; }

	virtual void first() const { cout << "A::first()" << endl; }
	virtual void second() const { cout << "A::second()" << endl; }
	void third() const { cout << "A::third()" << endl; }
};

struct B : public A
{
	B() { cout << "B()" << endl; }
	~B() { cout << "~B()" << endl; }

	void first() const { cout << "B::first()" << endl; }
	void second() const { cout << "B::second()" << endl; }
	void third() const { cout << "B::third()" << endl; }
};

struct C : public B
{
	C() { cout << "C()" << endl; }
	~C() { cout << "~C()" << endl; }

	void first() const { cout << "C::first()" << endl; }
	void second() const { cout << "C::second()" << endl; }
	void third() const { cout << "C::third()" << endl; }
};
#pragma endregion

#pragma region test2
struct Empty
{
};

struct EmptyVirt
{
	virtual ~EmptyVirt() {}
};

struct NotEmpty 
{ 
	int m_i; 
};

struct NotEmptyVirt
{
	virtual ~NotEmptyVirt() {}
	int m_i;
};

struct NotEmptyNonVirt
{
	void foo() const {}
	int m_i;
};
#pragma endregion

#pragma region test3
struct Base
{
	Base() { cout << "Base::Base()" << endl; }
	virtual ~Base() { cout << "Base::~Base()" << endl; }

	virtual void foo() { cout << "Base::foo()" << endl; }
	virtual void bar() { cout << "Base::bar()" << endl; }
	virtual void baz() { cout << "Base::baz()" << endl; }
};

struct Inherited : public Base
{
	Inherited() { cout << "Inherited::Inherited()" << endl; }
	virtual ~Inherited() { cout << "Inherited::~Inherited()" << endl; }

	virtual void bar() { cout << "Inherited::bar()" << endl; }
	virtual void qux() { cout << "Inherited::qux()" << endl; }
};
#pragma endregion

#pragma region Virtual Cats
class Cat
{
public:
	virtual ~Cat() { sayGoodbye(); }

	void askForFood() const
	{
		speak();
		eat();
	}
	virtual void speak() const { cout << "Meow! "; }
	virtual void eat() const { cout << "*champing*" << endl; }
	virtual void sayGoodbye() const { cout << "Meow-meow!" << endl; }
};

class CheshireCat : public Cat
{
public:
	void speak() const { cout << "WTF?! Where\'s my milk? =) "; }
	void sayGoodbye() const { cout << "Bye-bye! (:" << endl; }
};
#pragma endregion

void test4()
{
	Cat * cats[] = { new Cat, new CheshireCat };

	cout << "Ordinary Cat: "; cats[0]->askForFood();
	cout << "Cheshire Cat: "; cats[1]->askForFood();

	delete cats[0]; delete cats[1];
}

void test1()
{
	cout << "pA is B:" << endl;
	A * pA = new B;
	pA->first();
	pA->second();
	pA->third();
	delete pA;

	cout << "\npA is C:" << endl;
	pA = new C;
	pA->first();
	pA->second();
	pA->third();
	delete pA;
}

void test2()
{
	std::cout << sizeof(Empty) << std::endl;
	std::cout << sizeof(EmptyVirt) << std::endl;
	std::cout << sizeof(NotEmpty) << std::endl;
	std::cout << sizeof(NotEmptyVirt) << std::endl;
	std::cout << sizeof(NotEmptyNonVirt) << std::endl;
}

void test3()
{
	Base * pBase = new Inherited;
	pBase->foo();
	pBase->bar();
	pBase->baz();
	//pBase->qux();    // Error
}

int main()
{
	test4();

	system("pause");
	return EXIT_SUCCESS;
}