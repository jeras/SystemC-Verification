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
 constraints.h -- 
  
 Define a constraint class to illustrate notion of dependent variables
 and explain use_constraint() and next() on dependent object semantics.
  
 *****************************************************************************/

#ifndef _CONSTRAINT_H
#define _CONSTRAINT_H

class dependent_integer_constraints : public scv_constraint_base {
public:
  scv_smart_ptr<int> ivar;
  scv_smart_ptr<int> jvar;
public:
  SCV_CONSTRAINT_CTOR(dependent_integer_constraints) {
    SCV_CONSTRAINT(ivar() >= 3 && ivar() <= 12);
    SCV_CONSTRAINT(jvar() >= 3 && jvar() <= 12);
    SCV_SOFT_CONSTRAINT(ivar() > jvar() );
  }
};

inline void print_constraint(dependent_integer_constraints& c)
{
  cout << "  ivar: " << *c.ivar << " jvar: " << *c.jvar << endl;
}

#endif // _CONSTRAINT_H
