# Build 'ALGOL60' parser.


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
	ALGOL60_Actions.cpp			\
	ALGOL60_Lexer.cpp			\
	ALGOL60_Main.cpp			\
	ALGOL60_Parser.cpp


OBJS	:= $	$(SOURCE:.cpp=.o)


ALGOL60:	$(OBJS)
	$(CC) -o $@ $(OBJS);


clean:
	rm $(SOURCE) $(OBJS) ALGOL60;