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
 packet_constraints.h --
  
 Define three constraint class qualis_packet, default_packet and 
 intermediate_packet for later use by test writers

 Define an inline method 'constrain_packet' used by test writers to constrain
 a scv_smart_ptr<packet> object defined in the test.
 *****************************************************************************/

#ifndef PACKET_CONSTRAINTS_H
#define PACKET_CONSTRAINTS_H

#include "scv.h"
#include "packet.h"

enum packet_constraint_type {QUALIS_PACKET, DEFAULT_PACKET, INTERMEDIATE_PACKET};

class qualis_packet : virtual public scv_constraint_base {
public:
  scv_smart_ptr<packet> sp;

  SCV_CONSTRAINT_CTOR(qualis_packet) {
    sp->ptype.keep_only(UNICAST);
    SCV_SOFT_CONSTRAINT(sp->source() <= 0xf);
  }
};

class default_packet : virtual public scv_constraint_base {
public:
  scv_smart_ptr<packet> sp;
public:
  SCV_CONSTRAINT_CTOR(default_packet) {
    SCV_CONSTRAINT(sp->source() <= 0x3);
    SCV_CONSTRAINT(sp->destination() <= 0x3);
    SCV_SOFT_CONSTRAINT(sp->source() != sp->destination());
  } 
};

class intermediate_packet : virtual public scv_constraint_base {
public:
  scv_smart_ptr<packet> sp;
public:
  SCV_CONSTRAINT_CTOR(intermediate_packet) {
    SCV_CONSTRAINT(sp->source() <= 0xf);
    SCV_CONSTRAINT(sp->destination() <= 0xf);
    SCV_SOFT_CONSTRAINT(sp->source() >= sp->destination());
  }
};

inline void constrain_packet(scv_smart_ptr<packet>& sp, packet_constraint_type t)
{
  switch(t) {
  case QUALIS_PACKET: {
    qualis_packet qp("qp");
    sp->use_constraint(qp.sp);
    break;
  }
  case DEFAULT_PACKET: {
    default_packet dp("dp");
    sp->use_constraint(dp.sp);
    break;
  }
  case INTERMEDIATE_PACKET: {
    intermediate_packet ip("ip");
    sp->use_constraint(ip.sp);
    break;
  }
  default:
    break;
  }
}

#endif
