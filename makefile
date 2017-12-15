DEPS = files.h
OBJ = ai.o
FILES = $(OBJ:.o=.cpp)
all:	$(OBJ)
	c++ -o ai $(OBJ)
dev:	
	c++ -c $(FILES) -g
	c++ -o ai $(OBJ)
clean:	
	rm $(OBJ)