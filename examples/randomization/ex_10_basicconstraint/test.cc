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

#include <iomanip>

// nbcode "def" start
//create a constraint class
struct addr_constraint : public scv_constraint_base {
  //create the objects that will be constrained
  scv_smart_ptr<int> row;
  scv_smart_ptr<int> col;

  SCV_CONSTRAINT_CTOR(addr_constraint) {
    //constraint row to be between 10 and 50 exclusive or 200 and 250
    //inclusive
    SCV_CONSTRAINT ( (row() > 10 && row() < 50)  || 
                    (row() >= 200 && row() <= 250) );

    //constraint col to be less than row+20 and greater than row-5
    //NOTE: if randomization is disabled on row, then row could be
    //any value. If row does not meet constraints an error
    //is generated.
    SCV_CONSTRAINT ( col() > ( row() - 5) );
    SCV_CONSTRAINT ( col() < ( row() + 20) );
  }
};
// nbcode "def" end

int sc_main (int argc, char** argv) {
  scv_random::set_global_seed(1023);

  // nbcode "decl" start
  //instantiate a constrained object
  addr_constraint addr("addr");
  // nbcode "decl" end

  //if you disable the constraint on row, col is still constrained
  //with respect to row. Uncommenting the following lines will
  //produce constraint errors because row does not satisfy the
  //constraints.
  //addr.row->disable_randomization();
  //*(addr.row) = 1000;

  // nbcode "print" start
  //randomize the object five times and print the values
  for(int i=0; i<5; ++i) {
    addr.next();
    scv_out << "Row: " << std::setw(3) << *(addr.row)
            << "; Col: " << std::setw(3) << *(addr.col) << endl;
  }
  scv_out << endl;
  // nbcode "print" end

  return 0;
}

