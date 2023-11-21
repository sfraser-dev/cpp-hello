all: hello-world compiler-language-info test

# hello-world: hello-world.o
# 	clang++ hello-world.o -o hello-world.exe

# hello-world.o:
# 	clang++ -c hello-world.cpp -I.

compiler-language-info: compiler-language-info.o 
	clang++ compiler-language-info.o -o compiler-language-info.exe

compiler-language-info.o:
	clang++ -c compiler-language-info.cpp -I.

# link the object code to other libraries (eg: std c++ library) and output executable
test: test.o test-joe.o
	clang++ test.o test-joe.o -o test.exe

# compile sourde to object code
test.o: test.cpp test-joe.h 
	clang++ -c test.cpp -I.

# compile sourde to object code
test-joe.o: test-joe.cpp test-joe.h
	clang++ -c test-joe.cpp -I.

clean:
	$(RM) *.o *.exe

