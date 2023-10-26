# Build 'PL1' parser.


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
	PL1_Actions.cpp			\
	PL1_Lexer.cpp			\
	PL1_Main.cpp			\
	PL1_Parser.cpp


OBJS	:= $	$(SOURCE:.cpp=.o)


PL1:	$(OBJS)
	$(CC) -o $@ $(OBJS);


clean:
	rm $(SOURCE) $(OBJS) PL1;