EXEC = Main

SRC = $(wildcard *.cpp)

OBJ = $(SRC:.cpp=.o)

CXXFLAGS = -Wall -Wextra -Werror -std=c++11 -g

$(EXEC): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

clean:
	rm -rf *.o

distclean: clean
	rm -rf $(EXEC)