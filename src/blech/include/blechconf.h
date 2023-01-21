/*
 Copyright (c) 2019 - for information on the respective copyright owner
 see the NOTICE file and/or the repository 
 https://github.com/blech-lang/blech.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#ifndef blechconf_h
#define blechconf_h

#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define BLC_VOID void 
#define BLC_BOOL bool

#define BLC_INT8 int8_t
#define BLC_INT16 int16_t
#define BLC_INT32 int32_t
#define BLC_INT64 int64_t

#define BLC_NAT8 uint8_t
#define BLC_NAT16 uint16_t
#define BLC_NAT32 uint32_t
#define BLC_NAT64 uint64_t

#define BLC_BITS8 uint8_t
#define BLC_BITS16 uint16_t
#define BLC_BITS32 uint32_t
#define BLC_BITS64 uint64_t

#define BLC_FLOAT32 float
#define BLC_FLOAT64 double

/* machine dependent unsigned integer type for programm counters
 * be careful on small machines
 */
#define BLC_PC_T uint32_t


#endif