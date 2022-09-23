
ListaEncadeada: main.o Lista.o No.o
	g++ main.o Lista.o -o ListaEncadeada

main.o: main.cpp
	g++ -c main.cpp

Lista.o: Lista.cpp Lista.hpp 
	g++ -c Lista.cpp

No.o: No.cpp No.hpp 
	g++ -c No.hpp

clean:
	rm *.o ListaEncadeada

#no windows se usa o comando mingw32-make, e não so make