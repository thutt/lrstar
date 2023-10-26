# Build 'PLSQL' parser.


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
	PLSQL_Actions.cpp			\
	PLSQL_Lexer.cpp			\
	PLSQL_Main.cpp			\
	PLSQL_Parser.cpp


OBJS	:= $	$(SOURCE:.cpp=.o)


PLSQL:	$(OBJS)
	$(CC) -o $@ $(OBJS);


clean:
	rm $(SOURCE) $(OBJS) PLSQL;