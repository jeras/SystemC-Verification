//  -*- C++ -*- <this line is for emacs to recognize it as C++ code>
/*****************************************************************************

  Licensed to Accellera Systems Initiative Inc. (Accellera) 
  under one or more contributor license agreements.  See the 
  NOTICE file distributed with this work for additional 
  information regarding copyright ownership. Accellera licenses 
  this file to you under the Apache License, Version 2.0 (the
  "License"); you may not use this file except in compliance
  with the License.  You may obtain a copy of the License at
 
    http://www.apache.org/licenses/LICENSE-2.0
 
  Unless required by applicable law or agreed to in writing,
  software distributed under the License is distributed on an
  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
  KIND, either express or implied.  See the License for the
  specific language governing permissions and limitations
  under the License.

 *****************************************************************************/

/*****************************************************************************

  scv.h -- Top-level include file for the SystemC Verification Standard
  library.  Include this file before any other includes.

  Original Authors (Cadence Design Systems, Inc):
  Norris Ip, Dean Shea, John Rose, Jasvinder Singh, William Paulsen,
  John Pierce, Rachida Kebichi, Ted Elkind, David Bailey
  2002-09-23

 *****************************************************************************/

/*****************************************************************************

  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.

      Name, Affiliation, Date:
  Description of Modification:

 *****************************************************************************/

#ifndef SCV_H
#define SCV_H

#include "scv/scv_util.h"
#include "scv/scv_bag.h"
#include "scv/scv_constraint.h"
#include "scv/scv_constraint_range.h"
#include "scv/scv_debug.h"
#include "scv/scv_expression.h"
#include "scv/scv_introspection.h"
#include "scv/scv_report.h"
#include "scv/scv_object_if.h"
#include "scv/scv_random.h"
#include "scv/scv_shared_ptr.h"
#include "scv/scv_sparse_array.h"
#include "scv/scv_tr.h"
#include "scv/scv_kit_date.h"
#include "scv/scv_ver.h"

#endif

#if !defined(SCV_DISABLE_USING_NAMESPACES) && !defined(SCV_NAMESPACES_INCLUDED_)
#define SCV_NAMESPACES_INCLUDED_ // 2nd include guard
#include <systemc.h>             // for future SystemC name cleanup
using namespace std;             // bring back std:: names
#endif // SC_DISABLE_USING_NAMESPACES
