include ./include.mk
SRCDIR=src
BINDIR=bin
CHEADERS=$(shell find $(SRCDIR) -type f -name '*.h')
CPPHEADERS=$(shell find $(SRCDIR) -type f -name '*.hpp')
CPPINCLUDES=-I$(BOOSTINC)
CINCLUDES=-I$(KENTINC) -I$(SAMTOOLS)
CPPLIBARGS=-L$(BOOSTLIBDIR) $(BOOSTLIBS)
CLIBARGS=-L$(KENTDIR) -L$(SAMTOOLS) -lbam -lkent -lm -lz 
CFLAGS=-O3
CXXFLAGS=-O3
CPPSRCLIST=$(shell find $(SRCDIR) -type f -name '*.cpp')
CSRCLIST=$(shell find $(SRCDIR) -type f -name '*.c')
CPPSRCLISTNODIR=$(notdir $(CPPSRCLIST)) 
CSRCLISTNODIR=$(notdir $(CSRCLIST)) 
CPPPROGRAMS=$(patsubst %.cpp, $(BINDIR)/%, $(CPPSRCLISTNODIR))
CPROGRAMS=$(patsubst %.cpp, $(BINDIR)/%, $(CSRCLISTNODIR))

all: $(CPPPROGRAMS) $(CPROGRAMS)

$(BINDIR)/%: $(SRCDIR)/%.cpp $(CPPHEADERS) $(CHEADERS)
	$(CXX) $(CXXFLAGS) $(CINCLUDES) $(CPPINCLUDES) $(CPPLIBARGS) $(CLIBARGS) $< -o $@

$(BINDIR)/%: $(SRCDIR)/%.c $(CHEADERS)
	$(CC) $(CFLAGS) $(CINCLUDES) $(CLIBARGS) $< -o $@

