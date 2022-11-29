CC := g++-10
FLAGS := -W -Wall -Wextra -std=c++20
SRC := src
SRCS := $(wildcard $(SRC)/*.cpp) $(wildcard $(SRC)/**/*.cpp)
OBJS := $(SRCS:src/%.cpp=bin/%.o)
MAIN := src/main.cpp
EXE := bin/main.exe

.PHONY : all build start clean

all : build start

build : $(OBJS)
	$(CC) $^ -o $(EXE) $(FLAGS)

start : $(EXE)
	./$<

clean :
	-rm -f $(wildcard bin/**/*.o) $(wildcard bin/*.o) $(EXE)

dir_guard = @mkdir -p $(@D)

bin/%.o : src/%.cpp
	$(dir_guard)
	$(CC) -c $< -o $@ $(FLAGS)
