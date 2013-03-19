# Author:  Tan Menglong <tanmenglong@gmail.com>
# Date:    Sun Mar  3 16:38:38 2013
#
# Make Target:
# ------------
# The Makefile provides the following targets to make:
#   $ make           compile and link
#   $ make clean     clean objects and the executable file
#
#===========================================================================

.PHONY : all clean

all :
	make -C killproc
	make -C findproc
#	make -C unittest

clean :
	make clean -C killproc
	make clean -C findproc
#	make clean -C unittest
