#!/bin/bash
echo "Making bin directory"
mkdir -p bin
echo "Making example include.mk, please edit to point to things on your computer"
cat > include.mk <<EOF
CC=gcc44
CXX=g++44
CFLAGS=-g -O2
CXXFLAGS=-g -O2
KENTSOURCE=\$(HOME)/src/KentLib
SAMTOOLS=\$(KENTSOURCE)/thirdparty/samtools
KENTINC=\$(KENTSOURCE)/include
BOOSTBASE=/hive/groups/genomeAssem
BOOSTINC=\$(BOOSTBASE)/include
BOOSTLIBDIR=\$(BOOSTBASE)/lib
BOOSTLIBS=-lboost_date_time -lboost_filesystem -lboost_graph -lboost_graph_parallel -lboost_iostreams -lboost_math_c99 -lboost_math_c99f -lboost_math_c99l -lboost_math_tr1 -lboost_math_tr1f -lboost_math_tr1l -lboost_mpi -lboost_mpi_python -lboost_prg_exec_monitor -lboost_program_options -lboost_python -lboost_random -lboost_regex -lboost_serialization -lboost_signals -lboost_system -lboost_test_exec_monitor -lboost_thread -lboost_unit_test_framework -lboost_wave -lboost_wserialization
EOF

echo "please add `pwd`/bin to your path"


