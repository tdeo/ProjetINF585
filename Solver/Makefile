# Copyright (C) 2006 International Business Machines.
# All Rights Reserved.
# This file is distributed under the Common Public License.
#
# Author: Andreas Waechter       IBM      2006-03-14

# $Id: Makefile.in,v 1.1.2.1 2006/04/19 23:25:14 andreasw Exp $

##########################################################################
#    You can modify this example makefile to fit for your own program.   #
#    Usually, you only need to change the five CHANGEME entries below.   #
##########################################################################

# CHANGEME: This should be the name of your executable
EXE = SolverBonmin

# CHANGEME: Here is the name of all object files corresponding to the source
#           code that you wrote in order to define the problem statement
OBJS = MyBonmin.o MyTMINLP.o

# CHANGEME: Additional libraries
ADDLIBS =

# CHANGEME: Additional flags for compilation (e.g., include flags)
ADDINCFLAGS =

# CHANGEME: Directory to the sources for the (example) problem definition
# files
SRCDIR = .
VPATH = .

##########################################################################
#  Usually, you don't have to change anything below.  Note that if you   #
#  change certain compiler options, you might have to recompile Bonmin.   #
##########################################################################

COIN_HAS_PKGCONFIG = #TRUE
COIN_CXX_IS_CL = #TRUE

# C++ Compiler command
CXX = g++

# C++ Compiler options
CXXFLAGS = -O3 -pipe -DNDEBUG -pedantic-errors -Wparentheses -Wreturn-type -Wcast-qual -Wall -Wpointer-arith -Wwrite-strings -Wconversion -Wno-unknown-pragmas -Wno-long-long   -DBONMIN_BUILD -std=c++11

# additional C++ Compiler options for linking
CXXLINKFLAGS =  -Wl,--rpath -Wl,/home/thierry/Bonmin-stable/build/lib

# Include directories (we use the CYGPATH_W variables to allow compilation with Windows compilers)
ifeq ($(COIN_HAS_PKGCONFIG), TRUE)
  INCL = `PKG_CONFIG_PATH=/home/thierry/Bonmin-stable/build/lib/pkgconfig:/home/thierry/Bonmin-stable/build/share/pkgconfig:  --cflags bonmin`
else
  INCL =  -I/home/thierry/Bonmin-stable/build/include/coin  -I/home/thierry/Bonmin-stable/build/include/coin  -I/home/thierry/Bonmin-stable/build/include/coin  -I/home/thierry/Bonmin-stable/build/include/coin  -I/home/thierry/Bonmin-stable/build/include/coin  -I/home/thierry/Bonmin-stable/build/include/coin  -I/home/thierry/Bonmin-stable/build/include/coin  -I/home/thierry/Bonmin-stable/build/include/coin/ThirdParty  -I/home/thierry/Bonmin-stable/build/include/coin/ThirdParty    
endif
INCL += $(ADDINCFLAGS)

# Linker flags
ifeq ($(COIN_HAS_PKGCONFIG), TRUE)
  LIBS = `PKG_CONFIG_PATH=/home/thierry/Bonmin-stable/build/lib/pkgconfig:/home/thierry/Bonmin-stable/build/share/pkgconfig:  --libs bonmin`
else
  ifeq ($(COIN_CXX_IS_CL), TRUE)
    LIBS = -link -libpath:`$(CYGPATH_W) /home/thierry/Bonmin-stable/build/lib` libbonmin.lib  -L/home/thierry/Bonmin-stable/build/lib -lCbcSolver -lCbc   -L/home/thierry/Bonmin-stable/build/lib -lCgl   -L/home/thierry/Bonmin-stable/build/lib -lOsiClp   -L/home/thierry/Bonmin-stable/build/lib -lClp   -L/home/thierry/Bonmin-stable/build/lib -lOsi   -L/home/thierry/Bonmin-stable/build/lib -lCoinUtils -lm   -L/home/thierry/Bonmin-stable/build/lib -lipopt -lm -ldl  -L/home/thierry/Bonmin-stable/build/lib -lcoinmumps -lpthread -L/usr/lib/gcc/i686-linux-gnu/4.7 -L/usr/lib/gcc/i686-linux-gnu/4.7/../../../i386-linux-gnu -L/usr/lib/gcc/i686-linux-gnu/4.7/../../../../lib -L/lib/i386-linux-gnu -L/lib/../lib -L/usr/lib/i386-linux-gnu -L/usr/lib/../lib -L/usr/lib/gcc/i686-linux-gnu/4.7/../../.. -lgfortran -lm -lgcc_s -lquadmath  -L/home/thierry/Bonmin-stable/build/lib -lcoinhsl -L/usr/lib/gcc/i686-linux-gnu/4.7 -L/usr/lib/gcc/i686-linux-gnu/4.7/../../../i386-linux-gnu -L/usr/lib/gcc/i686-linux-gnu/4.7/../../../../lib -L/lib/i386-linux-gnu -L/lib/../lib -L/usr/lib/i386-linux-gnu -L/usr/lib/../lib -L/usr/lib/gcc/i686-linux-gnu/4.7/../../.. -lgfortran -lm -lgcc_s -lquadmath  -L/home/thierry/Bonmin-stable/build/lib -lcoinlapack -L/usr/lib/gcc/i686-linux-gnu/4.7 -L/usr/lib/gcc/i686-linux-gnu/4.7/../../../i386-linux-gnu -L/usr/lib/gcc/i686-linux-gnu/4.7/../../../../lib -L/lib/i386-linux-gnu -L/lib/../lib -L/usr/lib/i386-linux-gnu -L/usr/lib/../lib -L/usr/lib/gcc/i686-linux-gnu/4.7/../../.. -lgfortran -lm -lgcc_s -lquadmath  -L/home/thierry/Bonmin-stable/build/lib -lcoinblas -L/usr/lib/gcc/i686-linux-gnu/4.7 -L/usr/lib/gcc/i686-linux-gnu/4.7/../../../i386-linux-gnu -L/usr/lib/gcc/i686-linux-gnu/4.7/../../../../lib -L/lib/i386-linux-gnu -L/lib/../lib -L/usr/lib/i386-linux-gnu -L/usr/lib/../lib -L/usr/lib/gcc/i686-linux-gnu/4.7/../../.. -lgfortran -lm -lgcc_s -lquadmath  
  else
    LIBS = -L/home/thierry/Bonmin-stable/build/lib -lbonmin  -L/home/thierry/Bonmin-stable/build/lib -lCbcSolver -lCbc   -L/home/thierry/Bonmin-stable/build/lib -lCgl   -L/home/thierry/Bonmin-stable/build/lib -lOsiClp   -L/home/thierry/Bonmin-stable/build/lib -lClp   -L/home/thierry/Bonmin-stable/build/lib -lOsi   -L/home/thierry/Bonmin-stable/build/lib -lCoinUtils -lm   -L/home/thierry/Bonmin-stable/build/lib -lipopt -lm -ldl  -L/home/thierry/Bonmin-stable/build/lib -lcoinmumps -lpthread -L/usr/lib/gcc/i686-linux-gnu/4.7 -L/usr/lib/gcc/i686-linux-gnu/4.7/../../../i386-linux-gnu -L/usr/lib/gcc/i686-linux-gnu/4.7/../../../../lib -L/lib/i386-linux-gnu -L/lib/../lib -L/usr/lib/i386-linux-gnu -L/usr/lib/../lib -L/usr/lib/gcc/i686-linux-gnu/4.7/../../.. -lgfortran -lm -lgcc_s -lquadmath  -L/home/thierry/Bonmin-stable/build/lib -lcoinhsl -L/usr/lib/gcc/i686-linux-gnu/4.7 -L/usr/lib/gcc/i686-linux-gnu/4.7/../../../i386-linux-gnu -L/usr/lib/gcc/i686-linux-gnu/4.7/../../../../lib -L/lib/i386-linux-gnu -L/lib/../lib -L/usr/lib/i386-linux-gnu -L/usr/lib/../lib -L/usr/lib/gcc/i686-linux-gnu/4.7/../../.. -lgfortran -lm -lgcc_s -lquadmath  -L/home/thierry/Bonmin-stable/build/lib -lcoinlapack -L/usr/lib/gcc/i686-linux-gnu/4.7 -L/usr/lib/gcc/i686-linux-gnu/4.7/../../../i386-linux-gnu -L/usr/lib/gcc/i686-linux-gnu/4.7/../../../../lib -L/lib/i386-linux-gnu -L/lib/../lib -L/usr/lib/i386-linux-gnu -L/usr/lib/../lib -L/usr/lib/gcc/i686-linux-gnu/4.7/../../.. -lgfortran -lm -lgcc_s -lquadmath  -L/home/thierry/Bonmin-stable/build/lib -lcoinblas -L/usr/lib/gcc/i686-linux-gnu/4.7 -L/usr/lib/gcc/i686-linux-gnu/4.7/../../../i386-linux-gnu -L/usr/lib/gcc/i686-linux-gnu/4.7/../../../../lib -L/lib/i386-linux-gnu -L/lib/../lib -L/usr/lib/i386-linux-gnu -L/usr/lib/../lib -L/usr/lib/gcc/i686-linux-gnu/4.7/../../.. -lgfortran -lm -lgcc_s -lquadmath  
  endif
endif

# The following is necessary under cygwin, if native compilers are used
CYGPATH_W = echo

all: $(EXE)

.SUFFIXES: .cpp .c .o .obj

$(EXE): $(OBJS)
	bla=;\
	for file in $(OBJS); do bla="$$bla `$(CYGPATH_W) $$file`"; done; \
	$(CXX) $(CXXLINKFLAGS) $(CXXFLAGS) -o $@ $$bla $(LIBS) $(ADDLIBS)

clean:
	rm -rf $(EXE) $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCL) -c -o $@ `test -f '$<' || echo '$(SRCDIR)/'`$<


.cpp.obj:
	$(CXX) $(CXXFLAGS) $(INCL) -c -o $@ `if test -f '$<'; then $(CYGPATH_W) '$<'; else $(CYGPATH_W) '$(SRCDIR)/$<'; fi`
