# Copyright (c) 2024 Logic Magicians Software
MAKEFILE	:= $(lastword $(MAKEFILE_LIST))

TEX	=					\
	refman.tex				\
	intro.tex				\
	dfa.tex					\
	lrstar.tex				\
	lrgen.tex

PKG_MACRO	:=
STYLE_MACRO	:= $(LRSTAR_DIR)/doc/style-macros
DOC_DIR		:= $(abspath $(dir $(MAKEFILE)))
PACKAGES	:= $(PKG_MACRO):$(STYLE_MACRO):$(DOC_DIR):$(TEXINPUTS)
TEX_OPTS	:= \
	--halt-on-error


fail:
	$(PROLOG);							\
	echo "This Makefile must be used via $(LRSTAR_DIR)/Makefile";	\
	false;


$(REFMAN):		$(TEX)
	$(PROLOG);				\
	export TEXINPUTS=$(PACKAGES);		\
	pdflatex $(TEX_OPTS) $<;		\
	pdflatex $<;


$(REFMAN).d:	$(REFMAN)
	$(PROLOG);				\
	true;
