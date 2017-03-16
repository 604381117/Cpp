SRCS := $(wildcard ./src/*.cc)
CC := g++
LIBS := -lpthread

#OBJS := $(patsubst %.cc, %.o, $(SRCS))
CXXFLAGS := -w -g -std=c++11 $(LIBS)

RM := rm -rf
EXE := ./bin/main.exe
$(EXE):
	$(CC) -o $(EXE) $(SRCS) $(CXXFLAGS)
	sh main.sh
.PHONY : clean rebuild
clean :
	$(RM) $(EXE)
rebuild:
	sh main.sh
