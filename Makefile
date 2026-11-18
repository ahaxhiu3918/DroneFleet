CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

main: main.cpp Drone.cpp Drone.h
	$(CXX) $(CXXFLAGS) main.cpp Drone.cpp -o main

clean:
	rm -f main