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
 packet_ext.h --
  
 File created using tb_wizard from the "packet" data type defined in packet.h 

 *****************************************************************************/

#ifndef PKT_EXT_H
#define PKT_EXT_H

#include "packet.h"

SCV_ENUM_EXTENSIONS(packet_types_t) {
 public:
  SCV_ENUM_CTOR(packet_types_t) {
    SCV_ENUM(UNICAST);
    SCV_ENUM(MULTICAST);
  };
};

SCV_EXTENSIONS(packet) {
 public:
    scv_extensions< packet_types_t > ptype;
    scv_extensions< sc_uint<8> > source;
    scv_extensions< sc_uint<8> > destination;

  SCV_EXTENSIONS_CTOR(packet) {
    SCV_FIELD(ptype);
    SCV_FIELD(source);
    SCV_FIELD(destination);
  }

};

#endif // PKT_EXT_H


