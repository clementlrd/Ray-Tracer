CC := g++-10
FLAGS := -W -Wall -Wextra -std=c++20
SRC := src
SRCS := $(wildcard $(SRC)/*.cpp) $(wildcard $(SRC)/**/*.cpp)
OBJS := $(SRCS:src/%.cpp=bin/%.o)
MAIN := src/main.cpp
EXE := bin/main.exe

IMAGE_PATH := render/test
DEFAULT_ARGS := 
ARGS := $(DEFAULT_ARGS)

.PHONY : all build start clean

all : build start

build : $(OBJS)
	$(CC) $^ -o $(EXE) $(FLAGS)

start : start-ppm

start-ppm : $(EXE)
	./$< $(ARGS) > $(IMAGE_PATH).ppm

clean :
	-rm -f $(wildcard bin/**/*.o) $(wildcard bin/*.o) $(EXE)
	-rm -f render/* $(dir $(IMAGE_PATH))*

dir_guard = @mkdir -p $(@D)

bin/%.o : src/%.cpp
	$(dir_guard)
	$(CC) -c $< -o $@ $(FLAGS)
