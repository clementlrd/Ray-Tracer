.PHONY : all build start clean init
CC := g++-10
FLAGS := -W -Wall -Wextra -std=c++20
SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:src/%.cpp=bin/%.o)
MAIN := src/main.cpp
EXE := bin/main.exe

all : init build start

build : $(OBJS)
	@$(CC) $^ -o $(EXE) $(FLAGS)

start : $(EXE)
	@./$<

$(MAIN) : src/
	@touch $(@)
	@echo "#include <iostream>\n\nint main()\n{\n\treturn 0;\n}" > $(@)

%/ :
	@mkdir $@

bin/%.o : src/%.cpp
	@$(CC) -c $< -o $@ $(FLAGS)

init: bin/ $(MAIN)

clean :
	@rm $(wildcard bin/*)
