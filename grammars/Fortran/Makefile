# Build 'Fortran' parser.


CC	:=			\
	g++


INCLUDES	:=			\
	$(LRSTAR_INSTALL_ROOT)/include


DEFINES	:=			\
	LRSTAR_LINUX


ERROR_FORMAT	:=			\
	-fdiagnostics-color=never			\
	-fno-diagnostics-show-caret			\


CXXFLAGS	:=			\
	$(ERROR_FORMAT)			\
	$(addprefix -I,$(INCLUDES))			\
	$(addprefix -D,$(DEFINES))			\


SOURCE	:=			\
	Fortran_Actions.cpp			\
	Fortran_Lexer.cpp			\
	Fortran_Main.cpp			\
	Fortran_Parser.cpp


OBJS	:= $	$(SOURCE:.cpp=.o)


Fortran:	$(OBJS)
	$(CC) -o $@ $(OBJS);


clean:
	rm $(SOURCE) $(OBJS) Fortran;