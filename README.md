# Project Contents

This repository is a container for Paul Mann's lrstar & dfa parser
generator system.  The most notable thing about Paul's system is that
it works with EBNF grammers and generates the smallest and fastest
parsers with automatic AST generation.

The main thrust of this repository is to port the original Windows
code to compile & run on standard Linux systems, and to provide
comprehensive documentation so that everyone can learn about this
great parser generator.

Paul's website is:

  http://lrstar.cc/

And his version of the code can be downloaded from here:

  https://sourceforge.net/projects/lrstar/

Paul has been working on this technology for, literally, decades.  It
has been used in commercial software, and if you find this parser
generator useful, why don't you drop a line or some cash to Paul at
his website.  This would be especially nice if you are using his tools
in a business setting.

Paul has given his approval for this repository and the changes to
make it build & run well on Linux.

Included in this repository are sample grammars for the following languages:

  + ALGOL60
  + ANTLR
  + Ada
  + C11
  + CICS
  + COBOL
  + CPP5
  + Dbase
  + Fortran
  + Java1
  + Java9
  + Kotlin
  + Modula2
  + NCSA
  + PL1
  + PLM
  + PLSQL
  + Pascal
  + Python
  + SQL
  + Vba
  + XPL
  + YACC
  + Zeus
  + delphi
  + verilog

And sample projects for:

  + C       : Creates AST for preprocessed C.
  + Calc    : Simple calculator that generates pseudo-assembly.
  + JSON    : Reads JSON files into a data structure and prints data.
  + LRK     : Example showing LR(*) parsing.
  + Typedef : Handling context-sensitive grammars with 'typedef' example.


# Getting Started


To get started, you must have the following installed:

    make
    g++
    pdflatex
    texlive-latex-base   (Debian package)
    texlive-latex-extra  (Debian package)

You must also set up an environment by sourcing the setup
file into your Bash environment, like so:

    git clone https://github.com/thutt/lrstar.git
    cd lrstar
    git checkout linux-port
    source ./scripts/setup --build-type release --bod /tmp/lrstar
    LRSTAR_DIR          : '/tmp/x/lrstar'
    LRSTAR_ARCHITECTURE : ''
    LRSTAR_BUILD_OPTIONS: ''
    LRSTAR_BUILD_DIR    : '/tmp/lrstar'

    Build types         : debug release
    Build options       : profile strict

Sourcing `./scrtips/setup` sets several environment variables that are
used by the build process and the shell functions in
'${LRSTAR_DIR}/scripts/functions.

To build:

  lrstar-build -j20

The exported build artifacts will be placed in:

   ${LRSTAR_BUILD_DIR}/${LRSTAR_BUILD_TYPE}/usr/local


The software is known to build & run on x86-based Ubuntu 22.04 and
Arm64-based Ubuntu 23.10.


# Processing grammars

The shell environment set up when loading `./scripts/setup` updates
the `PATH` variable to include the `scripts` directory.  It also adds
several Bash functions that make using the tooling easier.
Specifically, `lrstar` and `dfa` are both shell wrappers to the
respective executables created by the build process.  They can be
directly executed from the shell to easily invoke the tooling on
grammars that you have created.  To see all the functions that are
added, see `./scripts/functions`.

Importantly, `./scripts/lrgen` servces as a one-stop shop to generate
all the grammar files by executing one tool.  See `./scripts/lrgen
--help` for details on how to use this tool.
