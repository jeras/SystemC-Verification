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

// nbcode "decl" start
class my_constraint : public scv_constraint_base {
  protected:
    sc_signal<unsigned> *sig_;
    scv_smart_ptr<unsigned> val;

  public:
    scv_smart_ptr<unsigned> rval;
    // nbcode "decl" end

    // nbcode "ctor" start
    SCV_CONSTRAINT_CTOR(my_constraint) {
      val->disable_randomization();
      *val = 5;
      sig_ = NULL;
      SCV_CONSTRAINT( rval() < (val() + 5) );
      SCV_CONSTRAINT( rval() > (val() - 5) );
      SCV_CONSTRAINT( rval() != val() );
    }
    // nbcode "ctor" end

    // nbcode "methods" start
  public:
    void set_sig (sc_signal<unsigned>* sigp) { sig_ = sigp; }
    virtual void next() {
      if(sig_ != NULL) {
        *val = sig_->read();
      }
      scv_constraint_base::next();
    }
    // nbcode "methods" end
};
