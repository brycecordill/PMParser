TARGET   = pmparser
CC       = g++
CCFLAGS  = -Wall -O2
SOURCES  = $(wildcard *.cpp)
DEPS 	 = $(wildcard *.h)
OBJECTS  = $(SOURCES:.cpp=.o)
PREFIX	 = /usr/local

all:$(TARGET)

$(TARGET):$(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

$(OBJECTS):$(SOURCES) $(DEPS)
	$(CC) -c $(CCFLAGS) $(SOURCES)

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: install
install: pmparser
	mkdir -p $(PREFIX)/bin
	cp $< $(PREFIX)/bin/pmparser

.PHONY: uninstall
uninstall:
	rm $(PREFIX)/bin/pmparser
