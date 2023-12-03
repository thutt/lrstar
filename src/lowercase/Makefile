# Copyright (c) 2000, 2020-2023 Logic Magicians Software
MAKEFILE	:= $(lastword $(MAKEFILE_LIST))


SOURCE	:=					\
	lowercase.cpp				\


OBJ	= $(SOURCE:.cpp=.o)


$(OBJ):	$(LRSTAR_DIR)/make/config.mk $(MAKEFILE)


fail:
	$(PROLOG);							\
	echo "This Makefile must be used via $(LRSTAR_DIR)/Makefile";	\
	false;

$(LOWERCASE_LIB):	$(SOURCE)
	$(PROLOG);				\
	$(CC) -g $(PROFILE) -c -I$(LRSTAR_DIR)/src/include -o $@ $<;

$(LOWERCASE_LIB).d:	$(LOWERCASE_LIB)
	$(PROLOG);				\
	true;

-include $(SOURCE:.cpp=.d)
