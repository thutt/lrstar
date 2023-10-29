# Build 'YACC' parser.


CC	:=			\
	g++


INCLUDES	:=			\
	$(LRSTAR_INSTALL_ROOT)/include


DEFINES	:=			\
	LRSTAR_LINUX


ERROR_FORMAT	:=			\
	-fdiagnostics-color=never			\
	-fno-diagnostics-show-caret			\


BUILD_TYPE	:=	\
	$(if $(LRSTAR_BUILD_TYPE),$(if $(filter debug,$(LRSTAR_BUILD_TYPE)),DEBUG,RELEASE),RELEASE)


CXXFLAGS	:=			\
	$(ERROR_FORMAT)			\
	$(addprefix -I,$(INCLUDES))			\
	$(addprefix -D,LRSTAR_$(BUILD_TYPE) $(DEFINES))			\


SOURCE	:=			\
	YACC_Actions.cpp			\
	YACC_Lexer.cpp			\
	YACC_Main.cpp			\
	YACC_Parser.cpp


OBJS	:= $	$(SOURCE:.cpp=.o)


YACC:	$(OBJS)
	$(CC) -o $@ $(OBJS);


clean:
	rm $(SOURCE) $(OBJS) YACC;