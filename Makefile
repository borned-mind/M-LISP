COMPILER=g++
FILES_INTEPRITATOR_CPP = lexer.cpp parser.cpp main.cpp
VERSION=\"0.0.1\"
NAMEPROGRAM=\"mlisp\"
OUTPUTNAME="MLisp-intepritator"

FLAGS=-DVERSION=$(VERSION) -DNAMEPROGRAM=$(NAMEPROGRAM)


intepritator:
	$(COMPILER) $(FLAGS) $(FILES_INTEPRITATOR_CPP) -o $(OUTPUTNAME)

all:
	
