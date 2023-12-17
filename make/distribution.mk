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


DISTRIB_LRGEN	:= 	\
	$(DISTRIB_ROOT)/bin/lrgen


DISTRIB_BASIC_DEFS_HEADER	:=	\
	$(DISTRIB_ROOT)/include/lrstar_basic_defs.h


DISTRIB_LOWERCASE_HEADER	:=	\
	$(DISTRIB_ROOT)/include/lowercase.h



DISTRIB_SAMPLE_HEADER	:=	\
	$(DISTRIB_ROOT)/include/lrstar_sample.h


DISTRIB_CMDLINE_HEADER	:=	\
	$(DISTRIB_ROOT)/include/lrstar_cmdline.h


DISTRIB_LRSTAR_LIB	:=	\
	$(DISTRIB_ROOT)/lib/lrstar.a

DISTRIB_BASIC_DEFS_GCC_HEADER	:=	\
	$(DISTRIB_ROOT)/include/lrstar_basic_defs_gcc.h

DISTRIB_LEXER_HEADER	:=	\
	$(DISTRIB_ROOT)/include/lrstar_lexer.h
$(DISTRIB_LEXER_HEADER):	$(LRSTAR_DIR)/src/include/lrstar_lexer.h


DISTRIB_SAMPLE_MAKE_DEFS	:=	\
	$(DISTRIB_ROOT)/make/sample.defs

$(DISTRIB_LOWERCASE_HEADER):	$(LRSTAR_DIR)/src/include/lowercase.h
$(DISTRIB_SAMPLE_HEADER):	$(LRSTAR_DIR)/src/include/lrstar_sample.h
$(DISTRIB_LRSTAR_LIB):		$(LRSTAR_LIB)



DISTRIB_PARSER_HEADER	:=	\
	$(DISTRIB_ROOT)/include/lrstar_parser.h

DISTRIB_PARSER_TABLES_HEADER	:=	\
	$(DISTRIB_ROOT)/include/lrstar_parser_tables.h

$(DISTRIB_PARSER_HEADER):		$(LRSTAR_DIR)/src/include/lrstar_parser.h
$(DISTRIB_PARSER_TABLES_HEADER):	$(LRSTAR_DIR)/src/include/lrstar_parser_tables.h
$(DISTRIB_SAMPLE_MAKE_DEFS):		$(LRSTAR_DIR)/make/sample.defs

$(DISTRIB_LEXER_HEADER)					\
$(DISTRIB_PARSER_HEADER)				\
$(DISTRIB_PARSER_TABLES_HEADER):
	$(PROLOG);						\
	$(INSTALL)						\
		--mode=444					\
		-D						\
		"$(LRSTAR_DIR)/src/include/$(notdir $@)"	\
		$@;						\
	echo "LIBRARY: $@";


$(DISTRIB_SAMPLE_HEADER)			\
$(DISTRIB_LOWERCASE_HEADER):
	$(PROLOG);						\
	$(INSTALL)						\
		--mode=444					\
		-D						\
		"$(LRSTAR_DIR)/src/include/$(notdir $@)"	\
		$@;						\
	echo "HEADER: $@";





# Always installed because $(LRSTAR_LIB) is .PHONY.
#
$(DISTRIB_LRSTAR_LIB):
	$(PROLOG);					\
	$(INSTALL)					\
		--mode=444				\
		-D					\
		$<					\
		$@;					\
	echo "LIB: $@";


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


$(DISTRIB_BASIC_DEFS_GCC_HEADER):	$(LRSTAR_DIR)/src/include/lrstar_basic_defs_gcc.h
	$(PROLOG);				\
	$(INSTALL)				\
		--mode=444			\
		-D				\
		"$<"				\
		$@;				\
	echo "BASIC GCC DEFS: $@";


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
	echo "DFA: $@";


$(DISTRIB_LRGEN):	$(LRSTAR_DIR)/scripts/lrgen
	$(PROLOG);				\
	$(INSTALL)				\
		--mode=555			\
		-D				\
		"$<"				\
		$@;				\
	echo "LRGEN: $@";


# The 'distribution' target uses Gnu Coreutils 'install' program to
# put all the delivered build artifacts into the '/usr/local'
# directory tree.
distribution:						\
		$(DISTRIB_BASIC_DEFS_GCC_HEADER)	\
		$(DISTRIB_BASIC_DEFS_HEADER)		\
		$(DISTRIB_DFA)				\
		$(DISTRIB_LEXER_HEADER)			\
		$(DISTRIB_LOWERCASE_HEADER)		\
		$(DISTRIB_LRGEN)			\
		$(DISTRIB_LRSTAR)			\
		$(DISTRIB_LRSTAR_LIB)			\
		$(DISTRIB_PARSER_HEADER)		\
		$(DISTRIB_PARSER_TABLES_HEADER)		\
		$(DISTRIB_SAMPLE_HEADER)		\
		$(DISTRIB_SAMPLE_MAKE_DEFS)
	$(PROLOG);	\
	true;
