#include "RefBase.h"

#define DEBUG true

#if DEBUG
#include <iostream>
#endif

RefBase::RefBase() 
	: mRefs(new RefBase::weakref(this))
{
#if DEBUG
	std::cout << "[LOG] RefBase::RefBase() is called." << std::endl;
#endif
}

RefBase::~RefBase()
{
#if DEBUG
	std::cout << "[LOG] RefBase::~RefBase() is called." << std::endl;
#endif
	delete mRefs;
}

void RefBase::inc()
{
	this->mRefs->inc();
}

void RefBase::dec()
{
	this->mRefs->dec();
}

RefBase::weakref::weakref(RefBase* base) 
	: mBase(base)
	, mCount(0)
{
#if DEBUG
	std::cout << "[LOG] RefBase::weakref::weakref() is called." << std::endl;
#endif
}

void RefBase::weakref::inc()
{
	this->mCount++;
}

void RefBase::weakref::dec()
{
	this->mCount--;
	if (!mCount) {
		delete mBase;
	}
}
