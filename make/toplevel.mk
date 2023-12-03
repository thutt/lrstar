# Copyright (c) 2023 Logic Magicians Software
# BSD 3 License


LRSTAR_RELA_DIR		:= src/lrstar
LRSTAR_BUILD_DIR	:= $(_BUILD_DIR)/$(LRSTAR_RELA_DIR)
LRSTAR			:= $(LRSTAR_BUILD_DIR)/lrstar

DFA_RELA_DIR		:= src/dfa
DFA_BUILD_DIR		:= $(_BUILD_DIR)/$(DFA_RELA_DIR)
DFA			:= $(DFA_BUILD_DIR)/dfa

LOWERCASE_RELA_DIR	:= src/lowercase
LOWERCASE_BUILD_DIR	:= $(_BUILD_DIR)/$(LOWERCASE_RELA_DIR)
LOWERCASE_LIB		:= $(LOWERCASE_BUILD_DIR)/lowercase.o


export LRSTAR
export DFA
export LOWERCASE_LIB
