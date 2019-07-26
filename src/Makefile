TARGET   = pmparser
CC       = g++
CCFLAGS  = -Wall
SOURCES  = $(wildcard *.cpp)
DEPS 	 = $(wildcard *.h)
OBJECTS  = $(SOURCES:.cpp=.o)

all:$(TARGET)

$(TARGET):$(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

$(OBJECTS):$(SOURCES) $(DEPS)
	$(CC) -c $(CCFLAGS) $(SOURCES)

clean:
	rm -f $(TARGET) $(OBJECTS)

