/*
 * Copyright 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __WAVTYPES_H__
#define __WAVTYPES_H__

namespace wavlib {

typedef unsigned int RiffID;
typedef int RiffInt32;
typedef short RiffInt16;

typedef unsigned char byte;

inline RiffID makeRiffID(char a, char b, char c, char d) {
    return ((RiffID)d << 24) | ((RiffID)c << 16) | ((RiffID)b << 8) | (RiffID)a;
}

} // namespace wavlib

#endif /* __WAVTYPES_H__ */
