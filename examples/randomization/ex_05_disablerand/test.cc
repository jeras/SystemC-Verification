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

int sc_main(int argc, char** argv) {
  scv_smart_ptr<data_t> data_p("data");

  //set the global seed to that results will be consistent
  scv_random::set_global_seed(100);

        // nbcode "disable" start
  //set the values of the array element
  for(unsigned i=0; i<5; ++i) data_p->payload[i] = i*i;

  //turn off randomization for the even array elements
  for(unsigned i=0; i<5; i+=2) 
    data_p->payload[i].disable_randomization();
  // nbcode "disable" end

  //randomize composit
  data_p->next();

  scv_out << "Random value for " << data_p->get_name() << ":" << endl;
  data_p->print(scv_out);

  return 0;
}


