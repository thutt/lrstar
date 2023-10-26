# Build 'Python' parser.


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
	Python_Actions.cpp			\
	Python_Lexer.cpp			\
	Python_Main.cpp			\
	Python_Parser.cpp


OBJS	:= $	$(SOURCE:.cpp=.o)


Python:	$(OBJS)
	$(CC) -o $@ $(OBJS);


clean:
	rm $(SOURCE) $(OBJS) Python;