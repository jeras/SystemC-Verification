## ****************************************************************************
##
##  Licensed to Accellera Systems Initiative Inc. (Accellera) 
##  under one or more contributor license agreements.  See the 
##  NOTICE file distributed with this work for additional 
##  information regarding copyright ownership. Accellera licenses 
##  this file to you under the Apache License, Version 2.0 (the
##  "License"); you may not use this file except in compliance
##  with the License.  You may obtain a copy of the License at
## 
##    http://www.apache.org/licenses/LICENSE-2.0
## 
##  Unless required by applicable law or agreed to in writing,
##  software distributed under the License is distributed on an
##  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
##  KIND, either express or implied.  See the License for the
##  specific language governing permissions and limitations
##  under the License.
##  
## ****************************************************************************
##
##  Makefile.am --
##  Process this file with automake to produce a Makefile.in file.
## 
## ****************************************************************************
##
##  Original Authors:
##  Norris Ip, Dean Shea, John Rose, Jasvinder Singh, William Paulsen,
##  John Pierce, Rachida Kebichi, Ted Elkind, David Bailey,
##  Cadence Design Systems, Inc., 2002-09-23
##
## ****************************************************************************
##  
##  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
##  changes you are making here.
##
##      Name, Affiliation, Date: Eric Paire, Jerome Cornet, 
##                               STMicroelectronics, 2012-03-27
##  Description of Modification: Revamp of autotool build system for 64-bit
##                               support, 32-bit compilation on 64-bit host
##
##      Name, Affiliation, Date: Torsten Maehne, 
##                               Universite Pierre et Marie Curie, 2013-05-03
##  Description of Modification: Remove manual definition of the
##                               SHELL variable in all Makefile.am files, as it
##                               is already properly initialized by automake to
##                               POSIX-compliant shell.
##                               Remove AUTOMAKE_OPTIONS from all Makefile.am,
##                               where it doesn't have an effect.
##                               Replace INCLUDES variables by per-target
##                               _CPPFLAGS variables in all Makefile.am files
##                               to fix deprecation warnings.
##
## ****************************************************************************

AUTOMAKE_OPTIONS = foreign

# support local addition of automake macros
ACLOCAL_AMFLAGS= -I config

SUBDIRS = \
	src \
	docs \
	examples

TEXTDOCS = LICENSE README AUTHORS NOTICE INSTALL NEWS RELEASENOTES
SCVDOCS  = $(TEXTDOCS:=.scv)

%.scv : %
	$(INSTALL_DATA) $< $@

# FIXME: handle $docdir and/or $docdatadir
scvdocsdir = $(prefix)

if SCV_INSTALL_NOTSELF    # install documentation in non-local tree
scvdocs_DATA = $(SCVDOCS)
else
if !SCV_INSTALL_SOURCEDIR # "install" documentation in build tree
noinst_DATA  = $(SCVDOCS)
endif
endif # SCV_INSTALL_NOTSELF

EXTRA_DIST = \
	${TEXTDOCS} \
	config/bootstrap \
	msvc80/cudd/cudd.vcproj \
	msvc80/mtr/mtr.vcproj \
	msvc80/st/st.vcproj \
	msvc80/dddmp/dddmp.vcproj \
	msvc80/obj/obj.vcproj \
	msvc80/util/util.vcproj \
	msvc80/README \
	msvc80/run_examples.bat \
	msvc80/scv/scv_config.h \
	msvc80/scv/scv.vcproj \
	msvc80/scv.sln \
	msvc80/scv-examples.sln

CLEANFILES = \
	$(SCVDOCS)

debug:
	$(MAKE) all CXXFLAGS="$(CXXFLAGS_DEBUG) $(CXXFLAGS)" CFLAGS="$(CFLAGS_DEBUG) $(CFLAGS)"

opt:
	$(MAKE) all CXXFLAGS="$(CXXFLAGS_OPT) $(CXXFLAGS)" CFLAGS="$(CFLAGS_OPT) $(CFLAGS)"
