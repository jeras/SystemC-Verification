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

  // nbcode "seed" start
  //try to open the seed file to see if it exists
  FILE *seedfile = fopen("seedfile.txt", "r");

  if(seedfile) {
    //seedfile exists, use it
    scv_out << "Using seedfile.txt..." << endl;
    scv_random::seed_monitor_on(true, "seedfile.txt");
  } else {
    scv_out << "Saving seedfile.txt..." << endl;
    scv_random::seed_monitor_on(false, "seedfile.txt");
  }
  // nbcode "seed" end

  data_p->next();

  // nbcode "print" start
  scv_out << "Random value for data_p:" << endl;
  scv_out << data_p->field.get_name() << " = " << data_p->field << endl;
  scv_out << data_p->state.get_name() << " = " << data_p->state << endl;
  for(int i=0; i<5; ++i) {
    scv_out << data_p->payload[i].get_name() << " = "
            << data_p->payload[i] << endl;
  }
  // nbcode "print" end

  return 0;
}
