CXX := clang++
CPPFLAGS := -g -Wall 

all: hello.exe hello2.exe compiler-language-info.exe test.exe

hello.exe: hello.o
	$(CXX) hello.o -o hello.exe

hello.o:
	$(CXX) -c $(CPPFLAGS) hello.cpp -I.

hello2.exe: hello2.o
	$(CXX) hello2.o -o hello2.exe

hello2.o:
	$(CXX) -c $(CPPFLAGS) hello2.cpp -I.

compiler-language-info.exe: compiler-language-info.o 
	$(CXX) compiler-language-info.o -o compiler-language-info.exe

compiler-language-info.o:
	$(CXX) -c $(CPPFLAGS) compiler-language-info.cpp -I.

# link the object code to other libraries (eg: std c++ library) and output executable
test.exe: test.o test-joe.o
	$(CXX) test.o test-joe.o -o test.exe

# compile sourde to object code
test.o: test.cpp test-joe.h 
	$(CXX) -c $(CPPFLAGS) test.cpp -I.

# compile sourde to object code
test-joe.o: test-joe.cpp test-joe.h
	$(CXX) -c $(CPPFLAGS) test-joe.cpp -I.

clean:
	$(RM) *.o *.exe

