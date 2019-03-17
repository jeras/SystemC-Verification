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
  // Create a sparse packet array
  packetT defaultPacket;
  sc_int<64> upper_bound = ( ( (unsigned long long) 1 ) << 63 ) - 1;
  const sc_int<64> lower_bound = -(upper_bound+1);
  scv_sparse_array< sc_int<64>, packetT >
    packets("packets", defaultPacket,
            lower_bound, upper_bound);
  // nbcode "decl" end

  // nbcode "index" start
  // Create an index to the sparse packet array
  scv_smart_ptr< sc_int<64> > index;
  const sc_int<64> low = sc_int<64>(-1e3);
  const sc_int<64> high = sc_int<64>(-1e2);
  index->keep_only(low, high);  // Only 901 possible values
  // nbcode "index" end

  // nbcode "create" start
  // Create packets and copy into array
  scv_smart_ptr<packetT> packet;
  packet->length.keep_only(10,1024);
  for (unsigned int i=0; i<10; ++i) {
    packet->src.next();
    packet->dest.next();
    packet->length.next();
    for(unsigned int j=0; j<packet->length; j++) {
      packet->payload[j].next();
    }
    index->next();
    packets[index->read()] = *packet;  // Uses equal operator
  }
  // nbcode "create" end
      
  // nbcode "histo" start
  // Iterate through the range looking for packets in the
  // sparse array
  const unsigned int packetsPerLine = 50;
  unsigned int count = 0;
  for (sc_int<64> i=low; i<=high; i++) {
    if (count == 0) {
      scv_out << std::setw(6) << i << ": ";
    }
    if (packets[i] == defaultPacket) { // uses packetT == operator
      scv_out << ".";
    } else {
      scv_out << "*";
    }
    if (++count == packetsPerLine) {
      scv_out << endl;
      count = 0;
    }
  }
  // nbcode "histo" end

  // nbcode "contents" start
  // Iterate through again, this time printing each packet
  scv_out << endl << endl;
  for (sc_int<64> i=low; i<=high; i++) {
    if (packets[i] != defaultPacket) { // uses packetT == operator
      // Uses output operator
      scv_out << std::setw(6) << i << ": " << packets[i] << endl;
    }
  }
  scv_out << endl;
}
// nbcode "contents" end

int sc_main(int argc, char** argv) {
  sctop top("top");  //for osci
  sc_start();
  return 0;
}
