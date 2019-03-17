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
#include "scv.h"


// Simple example to show use of SCV constraint solver to find
// integer solutions to pythagorean theorem:
//   a*a + b*b == c*c

// create a constraint class

template <int N>
struct my_constraint : public scv_constraint_base {
  scv_smart_ptr<sc_uint<N> > a;
  scv_smart_ptr<sc_uint<N> > b;
  scv_smart_ptr<sc_uint<N+1> > c;

  SCV_CONSTRAINT_CTOR(my_constraint) {
    SCV_CONSTRAINT ( a() * a() + b() * b() == c() * c());
    SCV_CONSTRAINT( a() > 0 && b() > 0 );
  }
};

int sc_main (int argc, char** argv)
{
  int cnt = 30;

  if (argc > 1) cnt = atoi(argv[1]);

  if (cnt < 1) cnt = 1;

  if (cnt > 10000000) cnt = 10000000;

  cout << "count: " << cnt << endl;

  my_constraint<10> c("constraint");

  for (int i=0; i<cnt; ++i) {
    c.next();
    cout << "A: " << *(c.a)
       << "; B: " << *(c.b)
       << "; C: " << *(c.c)
       << endl;

    if (*(c.a) * *(c.a) + *(c.b) * *(c.b) != *(c.c) * *(c.c)) {
      cout << "Error!" << endl;
      return -1;
    }
  }

  return 0;
}

