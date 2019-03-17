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
##  Process this file with automake to produce Makefile.in
##
## ****************************************************************************
##
##  Original Authors:
##  Eric Paire, Jerome Cornet
##  STMicroelectronics, 2012-04-27
##
## ****************************************************************************
##  
##  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
##  changes you are making here.
##
##      Name, Affiliation, Date: 
##  Description of Modification:
##
## ****************************************************************************

TESTS = \
	introspection1

check_PROGRAMS = \
	introspection1

introspection1_SOURCES = \
	test.cpp

EXTRA_DIST = \
	README \
	introspection1.vcproj


if SCV_INSTALL_BUILDDIR
examplesdir=$(prefix)/examples
else
examplesdir=$(prefix)/examples/scv
endif
my_datadir = $(examplesdir)/extensions/introspection1

if !SCV_INSTALL_SOURCEDIR # do not duplicate examples in source tree

my_data_DATA = \
	$(EXTRA_DIST) \
	$(introspection1_SOURCES)

endif # !SCV_INSTALL_SOURCEDIR

introspection1_CPPFLAGS = \
	-I$(SYSC_INC_PREFIX) \
	-I$(top_srcdir)/src

introspection1_LDADD = \
	$(top_builddir)/src/scv/libscv.la -lsystemc

introspection1_LDFLAGS = \
	-R$(SYSC_LIB_PREFIX)
