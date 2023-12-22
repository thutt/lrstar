# This makefile will build the 'JSON' parser.
#
# The working directory must be the same as this Makefile and the
# grammar files.  It is affected by using the default goal, and
# allowing the build process to take over.
#
#
# When using a development tree, invoke like this:
#
#  make \
#     LRSTAR_INSTALL_ROOT=${LRSTAR_BUILD_DIR}/${LRSTAR_BUILD_TYPE}/usr/local \
#     -f <path to directory of grammar>/<grammar>.make
#
#
# When using lrstar installed in /usr/local, invoke like this:
#
#  make \
#     -f <path to directory of grammar>/<grammar>.make
#
#
# This Makefile is generated by lrgen.
# lrgen will NOT overwrite this Makefile.
#
GRM		:= JSON
.DEFAULT_GOAL	:= recurse


# A development environment has files in $(LRSTAR_INSTALL_ROOT), post build.
# For a non-development environment, files should be installed in /usr/local.
#
INSTALL_ROOT	:=			\
	$(if $(LRSTAR_INSTALL_ROOT),$(LRSTAR_INSTALL_ROOT),/usr/local)


include $(INSTALL_ROOT)/make/sample.defs
GRMOPT	:= ast d
LGROPT	:= 


SOURCE	:=			\
	$(GRM)_Lexer.cpp	\
	$(GRM)_Main.cpp		\
	$(GRM)_Parser.cpp	\
	$(GRM)_user.cpp		\
	$(GRM)_user_main.cpp


OBJS	:=				\
	$(SOURCE:.cpp=.o)		\
	$(INSTALL_ROOT)/lib/lrstar.a


$(GRM).sentinel:	$(GRM).grm $(GRM).lgr
	$(LRGEN)			\
	  --directory $(GRM_DIR)	\
	  --grm $(GRM)			\
	  --grmopt "$(GRMOPT)"		\
	  --lgropt "$(LGROPT)";		\
	touch $@;


$(OBJS):	$(GRM).sentinel


$(GRM):	$(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS);


clean:
	rm $(OBJS) $(GRM);

-include $(SOURCE:.cpp=.d)
