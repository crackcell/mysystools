# Author:  Tan Menglong <tanmenglong@gmail.com>
# Date:    Sun Aug 26 17:04:21 2012
#
# Make Target:
# ------------
# The Makefile provides the following targets to make:
#   $ make           compile and link
#   $ make clean     clean objects and the executable file
#
#===========================================================================

include ../Makefile.env

MODULE = findproc
VERSION = $(shell git log --name-status HEAD^..HEAD | grep commit | cut -f 2 -d " ")

CQ_ROOT = ../..
DA_ROOT = ../

BUILD_TARGETS = findproc findproc_d

INC = -I$(DA_ROOT) -I$(ZHUHAI)/output/include
LIB = 
LIB_DEBUG =

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
OBJ_DEBUG = $(patsubst %.cpp, %_d.o, $(SRC))

.PHONY : all clean check

all : $(BUILD_TARGETS)

check : all
	valgrind --leak-check=full --show-reachable=yes ./findproc_d

findproc : $(OBJ)
	$(CXX) -o $@ $^ $(LIB)

findproc_d : $(OBJ_DEBUG)
	$(CXX) -o $@ $^ $(LIB_DEBUG)

clean :
	rm -rf $(OBJ) $(OBJ_DEBUG) $(BUILD_TARGETS)
