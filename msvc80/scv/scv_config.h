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

#if defined(_MSC_VER)
// int/long are both 32-bit on Win32/Win64 (LLP64)
# if defined(WIN64) || defined(_WIN64)
#   define SIZEOF_INT    4
#   define SIZEOF_LONG   4
#   define SIZEOF_VOID_P 8
# else // Win32
#   define SIZEOF_INT    4
#   define SIZEOF_LONG   4
#   define SIZEOF_VOID_P 4
# endif // Win32/64
#endif // _MSC_VER
