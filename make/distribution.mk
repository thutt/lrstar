# Copyright (c) 2023 Logic Magicians Software
# BSD 3 License
#
# This section of the build process delivers files into a directory
# tree structure that is identical to how the program would be
# installed in a root filesystem.
#
INSTALL		:=	\
	/usr/bin/install

DISTRIB_ROOT	:=	\
	$(_BUILD_DIR)/usr/local


DISTRIB_LRSTAR	:=	\
	$(DISTRIB_ROOT)/bin/lrstar


DISTRIB_DFA	:=	\
	$(DISTRIB_ROOT)/bin/dfa


DISTRIB_BASIC_DEFS_HEADER	:=	\
	$(DISTRIB_ROOT)/include/lrstar_basic_defs.h


DISTRIB_LIBRARY_DEFS_HEADER	:=	\
	$(DISTRIB_ROOT)/include/lrstar_library_defs.h


DISTRIB_LEXER_HEADER	:=	\
	$(DISTRIB_ROOT)/include/lrstar_lexer.h
$(DISTRIB_LEXER_HEADER):	$(LRSTAR_DIR)/src/code/lrstar_lexer.h


DISTRIB_MAIN_CODE	:=	\
	$(DISTRIB_ROOT)/include/lrstar_main.cpp

DISTRIB_MAIN_HEADER	:=	\
	$(DISTRIB_ROOT)/include/lrstar_main.h

DISTRIB_LRSTAR_HEADER	:=	\
	$(DISTRIB_ROOT)/include/lrstar.h

DISTRIB_SAMPLE_MAKE_DEFS	:=	\
	$(DISTRIB_ROOT)/make/sample.defs

$(DISTRIB_MAIN_CODE):		$(LRSTAR_DIR)/src/code/lrstar_main.cpp
$(DISTRIB_MAIN_HEADER):		$(LRSTAR_DIR)/src/code/lrstar_main.h


DISTRIB_PARSER_HEADER	:=	\
	$(DISTRIB_ROOT)/include/lrstar_parser.h

DISTRIB_PARSER_TABLES_HEADER	:=	\
	$(DISTRIB_ROOT)/include/lrstar_parser_tables.h

$(DISTRIB_PARSER_HEADER):		$(LRSTAR_DIR)/src/code/lrstar_parser.h
$(DISTRIB_PARSER_TABLES_HEADER):	$(LRSTAR_DIR)/src/code/lrstar_parser_tables.h
$(DISTRIB_LRSTAR_HEADER):		$(LRSTAR_DIR)/src/code/lrstar.h
$(DISTRIB_SAMPLE_MAKE_DEFS):		$(LRSTAR_DIR)/make/sample.defs

$(DISTRIB_LEXER_HEADER)					\
$(DISTRIB_LRSTAR_HEADER)				\
$(DISTRIB_MAIN_CODE)	$(DISTRIB_MAIN_HEADER)		\
$(DISTRIB_PARSER_HEADER)				\
$(DISTRIB_PARSER_TABLES_HEADER):
	$(PROLOG);					\
	$(INSTALL)					\
		--mode=444				\
		-D					\
		"$(LRSTAR_DIR)/src/code/$(notdir $@)"	\
		$@;					\
	echo "LIBRARY: $@";


$(DISTRIB_SAMPLE_MAKE_DEFS):
	$(PROLOG);					\
	$(INSTALL)					\
		--mode=444				\
		-D					\
		"$(LRSTAR_DIR)/make/$(notdir $@)"	\
		$@;					\
	echo "SAMPLE: $@";


$(DISTRIB_BASIC_DEFS_HEADER):	$(LRSTAR_DIR)/src/include/lrstar_basic_defs.h
	$(PROLOG);				\
	$(INSTALL)				\
		--mode=444			\
		-D				\
		"$<"				\
		$@;				\
	echo "BASIC DEFS: $@";


$(DISTRIB_LIBRARY_DEFS_HEADER):	$(LRSTAR_DIR)/src/include/lrstar_library_defs.h
	$(PROLOG);				\
	$(INSTALL)				\
		--mode=444			\
		-D				\
		"$<"				\
		$@;				\
	echo "LIBRARY DEFS: $@";


$(DISTRIB_LRSTAR):	$(LRSTAR)
	$(PROLOG);				\
	$(INSTALL)				\
		--mode=555			\
		-D				\
		"$(LRSTAR)"			\
		$@;				\
	echo "LRSTAR: $@";


$(DISTRIB_DFA):		$(DFA)
	$(PROLOG);				\
	$(INSTALL)				\
		--mode=555			\
		-D				\
		"$(DFA)"			\
		$@;				\
	echo "DFA   : $@";


# The 'distribution' target uses Gnu Coreutils 'install' program to
# put all the delivered build artifacts into the '/usr/local'
# directory tree.
distribution:					\
		$(DISTRIB_BASIC_DEFS_HEADER)	\
		$(DISTRIB_DFA)			\
		$(DISTRIB_LEXER_HEADER)		\
		$(DISTRIB_LIBRARY_DEFS_HEADER)	\
		$(DISTRIB_LRSTAR)		\
		$(DISTRIB_LRSTAR_HEADER)	\
		$(DISTRIB_MAIN_CODE)		\
		$(DISTRIB_MAIN_HEADER)		\
		$(DISTRIB_PARSER_HEADER)	\
		$(DISTRIB_PARSER_TABLES_HEADER)	\
		$(DISTRIB_SAMPLE_MAKE_DEFS)
	$(PROLOG);	\
	true;
