#! /bin/sh
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

LOGFILE1=$1
LOGFILE2=$2
GOLDENLOGPREFIX=$3

GOLDENLOGFILE1=${GOLDENLOGPREFIX}1.au
GOLDENLOGFILE2=${GOLDENLOGPREFIX}2.au
DIFFFILE="logfile.diff"
TMPFILE="logfile.grep"

if [ ! -f $LOGFILE1 ] || [ ! -f $LOGFILE2 ] || [ ! -f $GOLDENLOGFILE1 ] || [ ! -f $GOLDENLOGFILE2 ] ; then
    echo "fail - missing $LOGFILE1, $LOGFILE2, $GOLDENLOGFILE1 or $GOLDENLOGFILE2"
    exit
fi
grep "^%%REG: " $LOGFILE1 >$TMPFILE
if [ ! -f $TMPFILE ] ; then
    echo "fail - missing $TMPFILE"
    exit
fi
diff $TMPFILE $GOLDENLOGFILE1 >$DIFFFILE
rm $TMPFILE
if [ -s $DIFFFILE ] ; then
    echo "fail"
    exit
fi
grep "^%%REG: " $LOGFILE2 >$TMPFILE
if [ ! -f $TMPFILE ] ; then
    echo "fail - missing $TMPFILE"
    exit;
fi
diff $TMPFILE $GOLDENLOGFILE2 >$DIFFFILE
rm $TMPFILE
if [ -s $DIFFFILE ] ; then
    echo "fail"
else
    echo "passed"
fi
