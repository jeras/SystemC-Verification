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
#include "packet_constraint.h"

// nbcode "constraint" start
//create additional constraints
struct packet_hier_constraint : public packet_base_constraint {
  //add config variable
  scv_smart_ptr<sc_uint<32> > dest_min;
  scv_smart_ptr<sc_uint<32> > dest_max;
  
  SCV_CONSTRAINT_CTOR(packet_hier_constraint) {
    //use the base constraint
    SCV_BASE_CONSTRAINT(packet_base_constraint);

    //add extra constraints
    SCV_CONSTRAINT ((packet->dest_addr() > dest_min()) &&
                   (packet->dest_addr() < dest_max()) );
    SCV_CONSTRAINT (
      ((packet->src_addr() > (packet->dest_addr() + 0x100000) ) && 
       (packet->src_addr() < (packet->dest_addr() + 0x200000) ) ) || 
      ((packet->src_addr() < (packet->dest_addr() - 0x10000) ) &&
       (packet->src_addr() > (packet->dest_addr() - 0xfffff) )) );
  }
};
// nbcode "constraint" end

int sc_main(int argc, char** argv) {
  scv_random::set_global_seed(10);

  // nbcode "def" start
  //instatiate global constraints
  packet_hier_constraint pkt("Constrained Packet");

  pkt.dest_min->disable_randomization();
  pkt.dest_max->disable_randomization();
  *pkt.dest_min = 0x100000;
  *pkt.dest_max = 0x800000;
  // nbcode "def" end

  // nbcode "out" start
  for(int i=0; i<5; ++i) {
    pkt.next();
    pkt.packet->msg[(int)pkt.packet->msg_length] = '\0';
    scv_out << pkt.packet->get_name() << *(pkt.packet) << endl;
  }
  scv_out << endl;
  // nbcode "out" end

  return (0);
}


