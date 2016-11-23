#include <iostream>
#include "RefBase.h"

class Foo : public RefBase
{
public:
	Foo(int id);
	~Foo();

	int mId;
};

Foo::Foo(int id)
	: RefBase()
	, mId(id)
{
	std::cout << "[LOG] Foo(" << this->mId << ") is constructed." << std::endl;
}

Foo::~Foo()
{
	std::cout << "[LOG] Foo(" << this->mId << ") is destructed." << std::endl;
}

void test_refbase();
void test_sp();

int main()
{
	test_refbase();
	test_sp();

	return 0;
}

void test_refbase()
{
	std::cout << "[enter] test_refbase()" << std::endl;

	Foo* f = new Foo(1);

	for (int i = 0; i < 10; i++) {
		f->inc();
	}
	
	std::cout << f->mRefs->mCount << std::endl;

	int loopCount = 0;
	while(1) {
		loopCount++;
		int i = f->mRefs->mCount-1;
		f->dec();
		if (!i) break;
	}

	std::cout << "The loop is repeated " << loopCount << " times." << std::endl;

	std::cout << "[exit] test_refbase()" << std::endl;
}

void test_sp()
{
	std::cout << "[enter] test_sp()" << std::endl;

	std::cout << "[code] sp<Foo> s(new Foo(2));" << std::endl;
	sp<Foo> s(new Foo(2));
	std::cout << "[code] Foo* f = s.get();" << std::endl;
	Foo* f = s.get();

	std::cout << "Now f has " << f->mRefs->mCount << " references." << std::endl;
	
	std::cout << "[code] {\n        sp<Foo> p(f);" << std::endl;
	{
	sp<Foo> p(f);
	std::cout << "Now f has " << f->mRefs->mCount << " references." << std::endl;
	}
	std::cout << "[code] }" << std::endl;

	std::cout << "Now f has " << f->mRefs->mCount << " references." << std::endl;

	std::cout << "[exit] test_sp()" << std::endl;
}
