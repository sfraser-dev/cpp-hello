test: test.o test-joe.o
	clang++ test.o test-joe.o -o test-exe-file

test.o: test.cpp test-joe.h 
	clang++ -c test.cpp -I.

test-joe.o: test-joe.cpp test-joe.h
	clang++ -c test-joe.cpp -I.

clean:
	$(RM) test.o test-joe.o test-exe-file.exe

