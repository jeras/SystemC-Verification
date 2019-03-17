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
#ifndef DATA_EXT_H
#define DATA_EXT_H

#include "scv.h"
#include "data.h"


//declarations below this point are due to the --EXTEND_ALL option

template<>
class scv_extensions<data_t> : public scv_extensions_base<data_t> {
public:
  scv_extensions<int         > field_1;
  scv_extensions<sc_uint<8>  > field_2;
  scv_extensions<unsigned[5] > payload;
  scv_extensions<std::string > str;

  SCV_EXTENSIONS_CTOR(data_t) {
    //must be in order
    SCV_FIELD(field_1);
    SCV_FIELD(field_2);
    SCV_FIELD(payload);
    SCV_FIELD(str);
  }
};
#endif //DATA_EXT_H
