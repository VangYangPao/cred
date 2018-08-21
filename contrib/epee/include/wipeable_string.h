// Copyright (c) 2017-2018, The Cred Project
// 
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#pragma once

#include <stddef.h>
#include <vector>
#include <string>

namespace epee
{
  class wipeable_string
  {
  public:
    wipeable_string() {}
    wipeable_string(const wipeable_string &other);
    wipeable_string(wipeable_string &&other);
    wipeable_string(const std::string &other);
    wipeable_string(std::string &&other);
    wipeable_string(const char *s);
    ~wipeable_string();
    void wipe();
    void push_back(char c);
    void pop_back();
    const char *data() const noexcept { return buffer.data(); }
    size_t size() const noexcept { return buffer.size(); }
    bool empty() const noexcept { return buffer.empty(); }
    void resize(size_t sz);
    void reserve(size_t sz);
    void clear();
    bool operator==(const wipeable_string &other) const noexcept { return buffer == other.buffer; }
    bool operator!=(const wipeable_string &other) const noexcept { return buffer != other.buffer; }
    wipeable_string &operator=(wipeable_string &&other);
    wipeable_string &operator=(const wipeable_string &other);

  private:
    void grow(size_t sz, size_t reserved = 0);

  private:
    std::vector<char> buffer;
  };
}
