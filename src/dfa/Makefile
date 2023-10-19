# Copyright (c) 2000, 2020-2023 Logic Magicians Software
MAKEFILE	:= $(lastword $(MAKEFILE_LIST))
include $(LRSTAR_DIR)/make/config.mk

SOURCE	:=					\
	CM_Global.cpp				\
	CM_Main.cpp				\
	LG_Actions2.cpp				\
	LG_Actions.cpp				\
	LG_AddExtra.cpp				\
	LG_BuildStates.cpp			\
	LG_CheckGrammar.cpp			\
	LG_ComputeLA.cpp			\
	LG_CreateTables.cpp			\
	LG_Generate.cpp				\
	LG_Lexer.cpp				\
	LG_Main.cpp				\
	LG_OptimizeStates.cpp			\
	LG_Parser.cpp				\
	LG_PrintGrammar.cpp			\
	LG_PrintStates.cpp

OBJ	= $(SOURCE:.cpp=.o)


$(OBJ):	$(LRSTAR_DIR)/make/config.mk $(MAKEFILE)


fail:
	$(PROLOG);							\
	echo "This Makefile must be used via $(LRSTAR_DIR)/Makefile";	\
	false;


src/dfa__:	$(OBJ)
	$(PROLOG);					\
	$(CC) -g $(PROFILE) $(OBJ) -o dfa;


-include $(SOURCE:.cpp=.d)
