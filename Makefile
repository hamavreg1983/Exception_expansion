# Yuval Hamberg
# yuval.hamberg@gmail.com
# 05/06/2017
# TException_t

# File names
EXE_NAME = TEXCEPTION
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
H_FILES = $(wildcard *.h)

CC = g++
CFLAGS = -ansi -pedantic -Wall

.Phony : clean rebuild run

# Main target
$(EXE_NAME): $(OBJECTS) $(H_FILES) 
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXE_NAME) 
 
# To obtain object files
%.o: %.c $(H_FILES)
	$(CC) -c $(CFLAGS) $< -o $@


run: ${EXE_NAME}
	$(DYN_LIB_PATH) ./${EXE_NAME} 

clean:
	rm -f *.o
	rm -f *~
	rm -f $(EXE_NAME)
	rm -f a.out

rebuild : clean $(EXE_NAME)


