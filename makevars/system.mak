CXX = g++
AR = ar
GCOV = gcov
CFLAGS += -MMD
LDFLAGS =

ifeq ($(OS), Windows_NT)
    EXT = .exe
    RM = del
    CFLAGS += -std=c++11
    CXX = g++
    PREFIX = 
else
    EXT =
    PREFIX = ./
    RM = rm -f
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S), Linux)
        CFLAGS += 
    endif
    ifeq ($(UNAME_S), Darwin)
        CFLAGS += -Wno-deprecated-declarations
		LDFLAGS += -framework OpenGL -framework GLUT
    endif
endif

