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
#include "packet.h"

SC_MODULE(sctop) {
  SC_CTOR(sctop);
};

// nbcode "decl" start
sctop::sctop(sc_module_name name) : sc_module(name)
{
  // Create a smart pointer for each packet type
  scv_smart_ptr<packetT1> p1;
  scv_smart_ptr<packetT2> p2;
  // nbcode "decl" end

  // nbcode "first" start
  p1->next();
  p2->next();

  scv_out << "\nPacket values after randomization:" << endl;
  scv_out << "p1: " << *p1 << endl;
  scv_out << "p2: " << *p2 << endl;
  // nbcode "first" end

  // nbcode "second" start
  p1->next();
  p2->next();
  scv_smart_ptr< sc_uint<16> > rand;
  rand->next(); (p2->get_instance())->set_src (rand->read());
  rand->next(); (p2->get_instance())->set_dest(rand->read());

  scv_out << "\nPacket values after randomization using rand:" << endl;
  scv_out << "p1: " << *p1 << endl;
  scv_out << "p2: " << *p2 << endl;
}
// nbcode "second" end

int sc_main(int argc, char** argv) {
  sctop top("top");  //for osci
  sc_start();
  return 0;
}
