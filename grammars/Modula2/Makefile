# Build 'Modula2' parser.


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
	Modula2_Actions.cpp			\
	Modula2_Lexer.cpp			\
	Modula2_Main.cpp			\
	Modula2_Parser.cpp


OBJS	:= $	$(SOURCE:.cpp=.o)


Modula2:	$(OBJS)
	$(CC) -o $@ $(OBJS);


clean:
	rm $(SOURCE) $(OBJS) Modula2;