all: RefBase.o main.o
	g++ -o refbase_demo_v1 *.o

RefBase.o: RefBase.h RefBase.cpp
	g++ -c RefBase.cpp

main.o: refbase_demo.cpp
	g++ -c refbase_demo.cpp

clean:
	rm -rf *.o refbase_demo_v1
