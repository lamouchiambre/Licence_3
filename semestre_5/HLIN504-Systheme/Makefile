CXX 		= gcc
CXXFLAGS 	= -Wall -g -ansi -pedantic
SOURCES 	= pascal.c
HEADERS 	=
PROG 		= pascal
OBJECTS 	= $(SOURCES:.c=.o)

%: %.o
	$(CXX) -o $@ $^

$(PROG): $(OBJECTS)

run:
	./$(PROG)

clean:
	rm -f *~ *.o $(PROG) .depend

depend:
	makedepend $(SOURCES)
