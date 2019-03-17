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
 packet.h --
  
 Define the composite type "packet" used in the Transaction level testbench.

 *****************************************************************************/

#ifndef PKT_H
#define PKT_H

#include "scv.h"

enum packet_types_t { UNICAST, MULTICAST };

class packet {
public:
  packet_types_t  ptype;
  sc_uint<8>      source;
  sc_uint<8>      destination;

public:
  packet(); 
  packet(const packet & src); 
  const packet & operator=(const packet & src);
  void dump(void) const;
}; // class packet ..

#endif


