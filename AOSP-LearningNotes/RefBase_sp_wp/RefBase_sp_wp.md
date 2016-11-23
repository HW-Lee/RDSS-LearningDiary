# Android Common Class: `RefBase`, `sp`, `wp`

## Goal
<p>
This is a document that records things I've learned about `RefBase`, `sp`, and `wp`. Since the original implementation contains lots of complicated logic, the main idea of helping myself to get used to the mechanism they work is trying to implement a much simpler version one. Therefore, the following content is a record of understanding.
</p>

## Introduction to `RefBase`, `sp`, and `wp`
### `RefBase`
<p>
`RefBase` is a basic type which is inherited by all things declared in AOSP, it refers to the **REAL** reference of an object.
</p>

### `sp` and `wp`
<p>
`sp` stands for **strong pointer** and `wp` stands for **weak pointer**, which are used for automatically managing the life cycle of an object. They are basic types of pointers, and the memory leakage issue is handled themselves. In this way, the programmer doesn't need to be too worry about memory management.
</p>

## My Implementation

#### v1
* Define a class named `RefBase` and `RefBase::weakref`.

	```
	# Variables
	RefBase
	├── class weakref
	│	├── int mCount
	│	└── RefBase* mBase
	└── <weakref> mRef

	# Functions
	RefBase
	├── protected RefBase()
	├── public void inc()
	└── public void dec()
	```

* Define a class named `sp`

	```
	# Variables
	sp<T>
	└── T* m_ptr

	# Functions
	sp<T>
	├── public sp(T*)
	└── public inline T* get()
	```
