# Build 'XPL' parser.


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
	XPL_Actions.cpp			\
	XPL_Lexer.cpp			\
	XPL_Main.cpp			\
	XPL_Parser.cpp


OBJS	:= $	$(SOURCE:.cpp=.o)


XPL:	$(OBJS)
	$(CC) -o $@ $(OBJS);


clean:
	rm $(SOURCE) $(OBJS) XPL;