EXE:=main.exe
CC:=g++
CXXFLAGS:= -std=c++11 -lpthread
SRCS:=$(wildcard *.cc)
CC:=g++
RM:=rm -rf
$(EXE):$(SRCS)
	$(CC) -o $(EXE) $(SRCS) $(CXXFLAGS)

.PHONY : clean rebuild
clean :
	$(RM) $(EXE)

