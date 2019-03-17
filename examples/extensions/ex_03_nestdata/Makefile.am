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
	ex_03_nestdata

check_PROGRAMS = \
	ex_03_nestdata

ex_03_nestdata_SOURCES = \
	state.h \
	state_ext.h \
	test.cc

EXTRA_DIST = \
	README \
	checktest.sh \
	ex_03_nestdata.vcproj \
	test_reg.cc


if SCV_INSTALL_BUILDDIR
examplesdir=$(prefix)/examples
else
examplesdir=$(prefix)/examples/scv
endif
my_datadir = $(examplesdir)/extensions/ex_03_nestdata

if !SCV_INSTALL_SOURCEDIR # do not duplicate examples in source tree

my_data_DATA = \
	$(EXTRA_DIST) \
	$(ex_03_nestdata_SOURCES)

endif # !SCV_INSTALL_SOURCEDIR

ex_03_nestdata_CPPFLAGS = \
	-I$(SYSC_INC_PREFIX) \
	-I$(top_srcdir)/src

ex_03_nestdata_LDADD = \
	$(top_builddir)/src/scv/libscv.la -lsystemc

ex_03_nestdata_LDFLAGS = \
	-R$(SYSC_LIB_PREFIX)
