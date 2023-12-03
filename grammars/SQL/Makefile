# Build 'SQL' parser.


GRM		:= SQL
.DEFAULT_GOAL	:= recurse


INSTALL_ROOT :=			\
	$(if $(LRSTAR_INSTALL_ROOT),$(LRSTAR_INSTALL_ROOT),/usr/local)


include $(LRSTAR_INSTALL_ROOT)/make/sample.defs


SOURCE	:=			\
	$(GRM)_Lexer.cpp	\
	$(GRM)_Main.cpp		\
	$(GRM)_Parser.cpp	\
	$(GRM)_user.cpp		\


OBJS	:= $	$(SOURCE:.cpp=.o) $(LRSTAR_INSTALL_ROOT)/lib/lowercase.o


$(GRM)_Parser.cpp:	$(GRM).grm
	$(LRSTAR) $<


$(GRM)_LexerTables_typedef.h:	$(GRM).lgr $(GRM)_Parser.cpp
	$(DFA) $<


$(GRM)_Lexer.o:	$(GRM)_LexerTables_typedef.h


$(GRM):	$(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS);


clean:
	rm $(SOURCE) $(OBJS) $(GRM);