#ifndef REFBASE_H
#define REFBASE_H

class RefBase
{
public:
	class weakref
	{
	public:
		weakref(RefBase* base);
		void inc();
		void dec();

		RefBase* mBase;
		unsigned int mCount;
	};

	void inc();
	void dec();
	
	RefBase();
	virtual ~RefBase();

	weakref* mRefs;
};

template<typename T>
class sp
{
public:
	sp(T* other);
	~sp();

	T* get();

private:
	T* m_ptr;
};

template<typename T>
sp<T>::sp(T* other)
	: m_ptr(other)
{
	if (other) m_ptr->inc();
}

template<typename T>
sp<T>::~sp()
{
	if (m_ptr) m_ptr->dec();
}

template<typename T>
T* sp<T>::get()
{
	return m_ptr;
}

#endif