CXX      = g++
CXXFLAGS = -std=c++11 -Wall
EXEC     = prog

SRC = $(wildcard *.cpp)        # tous les .cpp du dossier
OBJ = $(SRC:.cpp=.o)           # les .o correspondants
HDR = $(wildcard *.h)          # tous les .h

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $@

%.o: %.cpp $(HDR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(EXEC)

.PHONY: clean