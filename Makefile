.POSIX:

CXX = g++
CXXFLAGS = -std=c++14 -Wall
LDLIBS = -lGL -lGLU -lglut
OUT  = ball

main: main.cpp View.o Ground.o Ball.o
	$(CXX) $(CXXFLAGS) -o $(OUT) main.cpp View.o Ball.o Ground.o $(LDLIBS)

View.o: View.cpp View.hpp
	$(CXX) $(CXXFLAGS) -c View.cpp View.hpp $(LDLIBS)

Ball.o: Ball.cpp Ball.hpp
	$(CXX) $(CXXFLAGS) -c Ball.cpp Ball.hpp $(LDLIBS)

Ground.o: Ground.cpp Ground.hpp
	$(CXX) $(CXXFLAGS) -c Ground.cpp Ground.hpp $(LDLIBS)


run: main
	./$(OUT)

clean:
	rm -f $(OUT) *.o *.gch
