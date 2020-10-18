mbf8exact: mbf8exact.o quicklist.o mbf6.o swap.o
	g++ mbf8exact.o quicklist.o mbf6.o swap.o -O3 -o mbf8exact
mbf8exact.o: mbf8exact.cpp
	g++ -c -O3 mbf8exact.cpp
quicklist.o: quicklist.cpp
	g++ -c -O3 quicklist.cpp
mbf6.o:
	g++ -c -O3 mbf6.cpp
swap.o:
	g++ -c -O3 swap.cpp
clean:
	rm -rf *.o mbf8exact