MODULE_SRC= main.cpp
MODULE_OBJ= main.o
MODULE_TARGET= main
MODULE_INCS= -Ipgn/include/
CCFLAGS= -ansi -pedantic -Wall -g -c
LDFLAGS= -g -o

$(MODULE_TARGET): $(MODULE_OBJ)
	g++ $(MODULE_OBJ) -lpgn $(LDFLAGS) ./$(MODULE_TARGET)

.cpp.o:
	g++ $(CCFLAGS) $< $(MODULE_INCS)

clean:
	rm -f *.o
	rm -f ./$(MODULE_TARGET)

