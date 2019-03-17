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

noinst_LTLIBRARIES = libdddmp.la

SUBDIRS = doc

libdddmp_la_SOURCES = \
	dddmp.h \
	dddmpInt.h \
	dddmpDump.c \
	dddmpBinary.c \
	dddmpConvert.c \
	dddmpDbg.c \
	dddmpDdNode.c

libdddmp_la_LDFLAGS = \
	$(LIBTOOL_LDFLAGS)

libdddmp_la_CPPFLAGS = \
	-I${top_srcdir}/src/cudd/2.3.0/cudd \
	-I${top_srcdir}/src/cudd/2.3.0/util \
	-I${top_srcdir}/src/cudd/2.3.0/mtr \
	-I${top_srcdir}/src \
	-I${top_builddir}/src


EXTRA_DIST = \
	0.bdd \
	0or1.bdd \
	1.bdd \
	2.bdd \
	2and3.bdd \
	3.bdd \
	4.bdd \
	4xor5.bdd \
	5.bdd \
	README \
	README.test \
	composeids.txt \
	one.bdd \
	testdddmp.script \
	varauxids.ord \
	varnames.ord \
	zero.bdd 
