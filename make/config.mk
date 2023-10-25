# Copyright (c) 2023 Logic Magicians Software
# BSD 3 License

SHELL	:=	\
	bash

SPACE	:=
SPACE	:= $(SPACE) $(SPACE)
export SPACE

CC	:=	\
	g++
export CC

# HOSTOS must be in { LINUX, WINDOWS }.
HOSTOS	:=	\
	LINUX
export HOSTOS

ATSIGN	:=	\
	$(if $(VERBOSE),,@)
export ATSIGN

PROLOG	:=					\
	$(ATSIGN)set -o errexit;		\
	set -o pipefail;			\
	set -o nounset
export PROLOG

# Build Directory
#
#   Allow any build option change to have a unique build directory
#   reduces the burden on the developer to know when to perform a
#   clean build.  The build directory is created from the build type
#   and the build options.
#
#   This construction must be matched by 'lrstar-path' in
#   ${LRSTAR_DIR}/scripts/functions.
#
_OPTS		:= $(if $(LRSTAR_BUILD_OPTIONS),/$(subst $(SPACE),/,$(LRSTAR_BUILD_OPTIONS)))
export _OPTS
_BUILD_DIR	:= $(LRSTAR_BUILD_DIR)/$(LRSTAR_BUILD_TYPE)$(_OPTS)
export _BUILD_DIR

# Compiler Code Generation options.
#
PROFILE	:=							\
	$(if $(filter profile,$(LRSTAR_BUILD_OPTIONS)),-pg)
export PROFILE


DEBUG	:=							\
	$(if $(filter debug,$(LRSTAR_BUILD_TYPE)),-g)
export DEBUG


OPT	:=							\
	$(if $(filter release,$(LRSTAR_BUILD_TYPE)),-Os,-Og)	\
	-fdata-sections						\
	-ffunction-sections					\
	-fno-rtti						\
	-fno-exceptions						\
	$(if $(filter debug,$(LRSTAR_BUILD_TYPE)),,-fno-stack-protector)
export OPT


PREPROCESSOR	:=						\
	$(if $(filter debug,$(LRSTAR_BUILD_TYPE)),_DEBUG)	\
	LRSTAR_$(HOSTOS)
export PREPROCESSOR


ERROR_FORMAT	:=				\
	-fdiagnostics-color=never		\
	-fno-diagnostics-show-caret
export ERROR_FORMAT


INCLUDE	:=				\
	$(LRSTAR_DIR)/src/include
export INCLUDE


WARNINGS	:=				\
	--pedantic				\
	-Wall					\
	-Wconversion				\
	-Werror					\
	-Wno-switch				\
	-Wsign-conversion
export WARNINGS


CXXFLAGS	=					\
	-DBUILD_TYPE_$(LRSTAR_BUILD_TYPE)		\
	$(addprefix -D,$(PREPROCESSOR))			\
	$(addprefix -I,$(INCLUDE))			\
	$(OPT)						\
	$(PROFILE)					\
	$(DEBUG)					\
	-MMD						\
	$(if $(filter strict,$(LRSTAR_BUILD_OPTIONS)),	\
	  $(WARNINGS))					\
	$(ERROR_FORMAT)
export CXXFLAGS

LIBS	=
export LIBS
