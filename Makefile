CC := g++
SRCD := src
BLDD := build
BIND := bin
INCD := include

EXEC := main

# Declaring all paths for src and object files
ALL_SRCF := $(shell find $(SRCD) -type f -name *.cpp)
ALL_OBJF := $(patsubst $(SRCD)/%,$(BLDD)/%,$(ALL_SRCF:.cpp=.o))

all: setup $(BIND)/$(EXEC)

# Creates build and bin directory
setup: $(BIND) $(BLDD)
$(BIND):
	mkdir -p $(BIND)
$(BLDD):
	mkdir -p $(BLDD)

# g++ command for executable
$(BIND)/$(EXEC): $(ALL_OBJF)
	$(CC) $^ -o $@

# g++ command for object files
$(BLDD)/%.o: $(SRCD)/%.cpp
	$(CC) -I $(INCD) -c -o $@ $<

# Debug option to compile with -g
debug: CC := g++ -g
debug: all

# Remove build and bin directories
clean:
	rm -rf $(BLDD) $(BIND)