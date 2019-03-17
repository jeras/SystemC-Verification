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

// nbcode "onehot" start
//enum for one hot coding
enum onehot_t {
  STATE_0 = 0, STATE_1 = 1, STATE_2 = 2, STATE_3 = 4,
  STATE_4 = 8, STATE_5 = 16, STATE_6 = 32 };
// nbcode "onehot" end

// nbcode "data" start
struct data_t {
  sc_uint<8> field;
  unsigned   payload[5];
  onehot_t   state;
};
// nbcode "data" end
