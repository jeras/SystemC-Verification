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
// nbcode "inc" start
#ifndef STATE_EXT_H
#define STATE_EXT_H

#include "scv.h"
#include "state.h"
// nbcode "inc" end

// nbcode "enum" start
template<>
class scv_extensions<state_t::onehot_t> : public scv_enum_base<state_t::onehot_t> {
public:

  SCV_ENUM_CTOR(state_t::onehot_t) {
    SCV_ENUM(state_t::STATE_0);
    SCV_ENUM(state_t::STATE_1);
    SCV_ENUM(state_t::STATE_2);
    SCV_ENUM(state_t::STATE_3);
    SCV_ENUM(state_t::STATE_4);
    SCV_ENUM(state_t::STATE_5);
    SCV_ENUM(state_t::STATE_6);
  }
};
// nbcode "enum" end

// nbcode "state" start
template<>
class scv_extensions<state_t> : public scv_extensions_base<state_t> {
public:
  scv_extensions<state_t::onehot_t > state;
  scv_extensions<int      > delay;
  scv_extensions<unsigned > data;

  SCV_EXTENSIONS_CTOR(state_t) {
    //must be in order
    SCV_FIELD(state);
    SCV_FIELD(delay);
    SCV_FIELD(data);
  }
};
// nbcode "state" end
#endif //STATE_EXT_H
