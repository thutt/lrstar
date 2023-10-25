# Copyright (c) 2023 Logic Magicians Software
# BSD 3 License


LRSTAR_RELA_DIR		:= src/lrstar
LRSTAR_BUILD_DIR	:= $(_BUILD_DIR)/$(LRSTAR_RELA_DIR)
LRSTAR			:= $(LRSTAR_BUILD_DIR)/lrstar

DFA_RELA_DIR		:= src/dfa
DFA_BUILD_DIR		:= $(_BUILD_DIR)/$(DFA_RELA_DIR)
DFA			:= $(DFA_BUILD_DIR)/dfa

export LRSTAR
export DFA
