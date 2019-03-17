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
 packet.cpp -- 
  
 Implementation for packet class. dump method shows the use of static extensions
 in the implementation of packet methods itself.
  
 *****************************************************************************/

#include "packet_ext.h"

// --------------------------------------------------------------
// constructors & copy assignment
packet::packet() {
  ptype = UNICAST;
};

packet::packet(const packet & src) : ptype(src.ptype), source(src.source), destination(src.destination) { };

const packet & packet::operator=(const packet & src) {
  ptype = src.ptype;
  source  = src.source;
  destination  = src.destination;
  return *this;
}; // packet & operator=

// --------------------------------------------------------------
//
// We could use print() (from the scv_extensions utility interface)
// in place of this function.  However, the interest in this function
// is not so much what it does, but to demonstrate how to access
// functions within classes from higher levels in the program.
//
void packet::dump(void) const {
  const scv_extensions<packet> p = scv_get_const_extensions(*this);
  cout << "  " << p.ptype.get_enum_string(p.ptype);

  cout << " " << source;
  cout << " " << destination << endl;
}
   


