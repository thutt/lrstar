# Copyright (c) 2023, 2024 Logic Magicians Software
# BSD 3 License


LRSTAR_RELA_DIR		:= src/lrstar
LRSTAR_BUILD_DIR	:= $(_BUILD_DIR)/$(LRSTAR_RELA_DIR)
LRSTAR			:= $(LRSTAR_BUILD_DIR)/lrstar


DFA_RELA_DIR		:= src/dfa
DFA_BUILD_DIR		:= $(_BUILD_DIR)/$(DFA_RELA_DIR)
DFA			:= $(DFA_BUILD_DIR)/dfa


LIBRARY_RELA_DIR	:= src/lib
LIBRARY_BUILD_DIR	:= $(_BUILD_DIR)/$(LIBRARY_RELA_DIR)
LRSTAR_LIB		:= $(LIBRARY_BUILD_DIR)/lrstar.a

REFMAN_RELA_DIR		:= doc/refman
REFMAN_BUILD_DIR	:= $(_BUILD_DIR)/$(REFMAN_RELA_DIR)
REFMAN			:= $(REFMAN_BUILD_DIR)/refman.pdf

export LRSTAR
export DFA
export LRSTAR_LIB
export REFMAN
