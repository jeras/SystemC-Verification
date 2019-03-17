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
##                               STMicroelectronics, 2012-04-27
##  Description of Modification: Revamp of autotool build system for 64-bit
##                               support, 32-bit compilation on 64-bit host
##
## ****************************************************************************

noinst_LTLIBRARIES = libmtr.la 

SUBDIRS = doc

EXTRA_DIST = \
	Makefile.sis \
	test.groups \
	testmtr.c

libmtr_la_SOURCES = \
	mtr.h \
	mtrInt.h \
	mtrBasic.c \
	mtrGroup.c 

libmtr_la_LDFLAGS = \
	$(LIBTOOL_LDFLAGS)

libmtr_la_CPPFLAGS = \
	-I${top_srcdir}/src/cudd/2.3.0/cudd \
	-I${top_srcdir}/src/cudd/2.3.0/util \
	-I${top_srcdir}/src \
	-I${top_builddir}/src
