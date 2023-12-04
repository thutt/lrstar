# Copyright (c) 2023 Logic Magicians Software
# BSD 3 License

$(if $(LRSTAR_DIR),,$(error 'LRSTAR_DIR' is not defined.))

include $(LRSTAR_DIR)/make/config.mk
include $(LRSTAR_DIR)/make/toplevel.mk
include $(LRSTAR_DIR)/make/distribution.mk

.DEFAULT_GOAL	:= distribution


all:	$(DFA) $(LRSTAR)
	$(PROLOG);					\
	echo "Master: All targets built.";

.PHONY:	$(DFA) $(LRSTAR) $(LRSTAR_LIB)
$(DFA) $(LRSTAR) $(LRSTAR_LIB):		\
		| build-directories
	$(PROLOG);							\
	src_dir="$(subst $(_BUILD_DIR),$(LRSTAR_DIR),$(dir $@))";	\
	$(MAKE)								\
	    -C $(dir $@)						\
	    -f $${src_dir}Makefile					\
	    --no-print-directory					\
	    VPATH=$${src_dir}						\
	    _BUILD_DIR=$(dir $@)					\
	    SHELL=$(SHELL)						\
	    $@.d;


clean:
	$(PROLOG);	\
	rm -rf $(_BUILD_DIR);


$(DFA_BUILD_DIR) $(LRSTAR_BUILD_DIR) $(LIBRARY_BUILD_DIR):
	$(PROLOG);	\
	mkdir -p $@;


build-directories:				\
	| $(DFA_BUILD_DIR)			\
	  $(LIBRARY_BUILD_DIR)		\
	  $(LRSTAR_BUILD_DIR)


# Show predefined preprocessor symbols for this compiler.  This is
# useful when looking for symbols that are defined by a particular
# compiler.  For example: determining if the compiler is big- or
# little-endian.
#
show-preprocessor-symbols:
	$(CC) -dM -E - </dev/null
