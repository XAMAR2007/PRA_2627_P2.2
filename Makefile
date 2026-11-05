bin/testDyV: testDyV.cpp DyV.h
	mkdir -p bin
	g++ -o bin/testDyV testDyV.cpp

clean:
	rm -rf *.o *.gch *.pch bin
bin/testMonedas: testMonedas.cpp Monedas.h
	mkdir -p bin
	g++ -o bin/testMonedas testMonedas.cpp
bin/testMochila: testMochila.cpp Mochila.h
	mkdir -p bin
	g++ -o bin/testMochila testMochila.cpp
