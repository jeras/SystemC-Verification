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

// nbcode "packet" start
struct packet_t {
  sc_uint<32> src_addr;
  sc_uint<32> dest_addr;
  sc_uint<16> msg_length;
  char        msg[1024];
};
// nbcode "packet" end

// nbcode "out" start
//define an ostream for a packet object
ostream& operator<<(ostream& os, const packet_t& p) {
  os << "{\n"
     << "   src_addr: " << p.src_addr << "\n"
     << "   dest_addr: " << p.dest_addr << "\n"
     << "   msg_length: " << p.msg_length << "\n"
     << "   msg {\n"
     << "     " << p.msg  << "\n"
     << "   }\n}" << endl;
  return os;
}
// nbcode "out" end

