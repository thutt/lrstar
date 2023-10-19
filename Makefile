# Copyright (c) 2023 Logic Magicians Software
# BSD 3 License

$(if $(LRSTAR_DIR),,$(error 'LRSTAR_DIR' is not defined.))

include $(LRSTAR_DIR)/make/config.mk

.DEFAULT_GOAL	:= all


.PHONY:	src/dfa src/lrstar
all:	src/dfa src/lrstar
	$(PROLOG);					\
	echo "Master: All targets built.";

src/dfa src/lrstar:				\
		build-directories
	$(PROLOG);				\
	$(MAKE)					\
	    -C $(_BUILD_DIR)/$@			\
	    -f $(LRSTAR_DIR)/$@/Makefile	\
	    --no-print-directory		\
	    VPATH=$(LRSTAR_DIR)/$@		\
	    _BUILD_DIR=$(_BUILD_DIR)/$@		\
	    $@__;

clean:
	$(PROLOG);	\
	rm -rf $(_BUILD_DIR);

$(addprefix $(_BUILD_DIR)/,src/dfa src/lrstar):
	$(PROLOG);	\
	mkdir -p $@;

build-directories:				\
	| $(_BUILD_DIR)/src/dfa			\
	  $(_BUILD_DIR)/src/lrstar


# Show predefined preprocessor symbols for this compiler.  This is
# useful when looking for symbols that are defined by a particular
# compiler.  For example: determining if the compiler is big- or
# little-endian.
#
show-preprocessor-symbols:
	$(CC) -dM -E - </dev/null
