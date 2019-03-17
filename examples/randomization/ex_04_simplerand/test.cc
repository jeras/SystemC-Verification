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
#include "data_ext.h"

// nbcode "declare" start
int sc_main(int argc, char** argv) {
  scv_smart_ptr<data_t> data_p ("data");
  scv_smart_ptr<int>    addr("addr");
  // nbcode "declare" end

  // nbcode "seed" start
  //set the global seed so that results will be consistent
  scv_random::set_global_seed(100);
  // nbcode "seed" end

  // nbcode "keep" start
  //set simple keeponly/keepout range
  addr->keep_only(10, 1000);
  addr->keep_out(100, 300);
  addr->keep_out(600, 900);
  // nbcode "keep" end

  // nbcode "next" start
  //randomize a simple int
  addr->next();
  // nbcode "next" end

  // nbcode "keep2" start
  //set keeponly on payload
  for(int i=0; i<5; ++i) data_p->payload[i].keep_only(0, 0x1ff);
  // nbcode "keep2" end

  // nbcode "next2" start
  //randomize user-defined data type
  data_p->next();
  // nbcode "next2" end

  // nbcode "print" start
  //note the use of the * operator to get the value of addr
  scv_out << "Random value for " << addr->get_name() << "  = " << *addr << endl;

  scv_out << "Random value for " << data_p->get_name() << ":" << endl;
  data_p->print(scv_out, 0, 2);
  // nbcode "print" end

  return 0;
}

