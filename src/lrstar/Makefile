# Copyright (c) 2000, 2020-2023 Logic Magicians Software
MAKEFILE	:= $(lastword $(MAKEFILE_LIST))


SOURCE	:=					\
	CM_Global.cpp				\
	PG_Actions.cpp				\
	PG_Actions1.cpp				\
	PG_Actions2.cpp				\
	PG_Actions3.cpp				\
	PG_BuildLR0.cpp				\
	PG_CheckGrammar.cpp			\
	PG_ComputeLA.cpp			\
	PG_CreateTables.cpp			\
	PG_Generate.cpp				\
	PG_Lexer.cpp				\
	PG_Main.cpp				\
	PG_OptimizeStates.cpp			\
	PG_Parser.cpp				\
	PG_PrintGrammar.cpp			\
	PG_PrintStates.cpp


OBJ	= $(SOURCE:.cpp=.o)


$(OBJ):	$(LRSTAR_DIR)/make/config.mk $(MAKEFILE)


fail:
	$(PROLOG);							\
	echo "This Makefile must be used via $(LRSTAR_DIR)/Makefile";	\
	false;

$(LRSTAR):	$(OBJ)
	$(PROLOG);				\
	$(CC) $(PROFILE) $(OBJ) $(CXXFLAGS) -o lrstar;

$(LRSTAR).d:	$(LRSTAR)
	$(PROLOG);				\
	true;

-include $(SOURCE:.cpp=.d)
