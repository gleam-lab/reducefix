#line 1 "/workspaces/proconenv/lib/tools/util.hpp"



// To see the details of my library, visit my GitHub Pages.
// https://anqooqie.github.io/proconlib/

#ifdef LOCAL
  #ifndef _GLIBCXX_DEBUG
    #define _GLIBCXX_DEBUG
  #endif
#else
  #ifndef NDEBUG
    #define NDEBUG
  #endif
#endif

#include <bits/stdc++.h>
#line 1 "/workspaces/proconenv/lib/tools/resize.hpp"



#line 8 "/workspaces/proconenv/lib/tools/resize.hpp"

namespace tools {
  template <class T, class Allocator, typename Head>
  void resize(::std::vector<T, Allocator>& vector, const Head& head) {
    vector.resize(head);
  }
  template <class T, ::std::size_t N, typename Head>
  void resize([[maybe_unused]] ::std::array<T, N>& array, [[maybe_unused]] const Head& head) {
    assert(array.size() == static_cast<::std::size_t>(head));
  }

  template <class T, class Allocator, typename Head, typename... Tail>
  void resize(::std::vector<T, Allocator>& vector, const Head& head, const Tail&... tail);
  template <class T, ::std::size_t N, typename Head, typename... Tail>
  void resize(::std::array<T, N>& array, const Head& head, const Tail&... tail);

  template <class T, class Allocator, typename Head, typename... Tail>
  void resize(::std::vector<T, Allocator>& vector, const Head& head, const Tail&... tail) {
    vector.resize(head);
    for (auto& child : vector) {
      ::tools::resize(child, tail...);
    }
  }
  template <class T, ::std::size_t N, typename Head, typename... Tail>
  void resize(::std::array<T, N>& array, [[maybe_unused]] const Head& head, const Tail&... tail) {
    assert(array.size() == static_cast<::std::size_t>(head));
    for (auto& child : array) {
      ::tools::resize(child, tail...);
    }
  }
}


#line 1 "/workspaces/proconenv/lib/tools/fill.hpp"



#include <type_traits>
#line 1 "/workspaces/proconenv/lib/tools/is_range.hpp"



#line 7 "/workspaces/proconenv/lib/tools/is_range.hpp"

namespace tools {
  template <typename T, typename = ::std::void_t<>>
  struct is_range : ::std::false_type {};

  template <typename T>
  struct is_range<T, ::std::void_t<decltype(::std::begin(::std::declval<T>()), ::std::end(::std::declval<T>()))>> : ::std::true_type {};

  template <typename T>
  inline constexpr bool is_range_v = ::tools::is_range<T>::value;
}


#line 11 "/workspaces/proconenv/lib/tools/fill.hpp"

namespace tools {
  template <class T, class Allocator, typename V>
  ::std::enable_if_t<!::tools::is_range_v<T>, void> fill(::std::vector<T, Allocator>& vector, const V& value) {
    ::std::fill(::std::begin(vector), ::std::end(vector), value);
  }
  template <class T, ::std::size_t N, typename V>
  ::std::enable_if_t<!::tools::is_range_v<T>, void> fill(::std::array<T, N>& array, const V& value) {
    ::std::fill(::std::begin(array), ::std::end(array), value);
  }

  template <class T, class Allocator, typename V>
  ::std::enable_if_t<::tools::is_range_v<T>, void> fill(::std::vector<T, Allocator>& vector, const V& value);
  template <class T, ::std::size_t N, typename V>
  ::std::enable_if_t<::tools::is_range_v<T>, void> fill(::std::array<T, N>& array, const V& value);

  template <class T, class Allocator, typename V>
  ::std::enable_if_t<::tools::is_range_v<T>, void> fill(::std::vector<T, Allocator>& vector, const V& value) {
    for (auto& child : vector) {
      ::tools::fill(child, value);
    }
  }
  template <class T, ::std::size_t N, typename V>
  ::std::enable_if_t<::tools::is_range_v<T>, void> fill(::std::array<T, N>& array, const V& value) {
    for (auto& child : array) {
      ::tools::fill(child, value);
    }
  }
}


#line 1 "/workspaces/proconenv/lib/tools/extend_input.hpp"



// WARNING:
// This file adds functions to std namespace for convenience.
// Strictly speaking, it is not allowed in C++.
// It makes the program ill-formed to include this file, and may cause undefined behavior.

#line 1 "/workspaces/proconenv/lib/tools/has_mod.hpp"



#line 6 "/workspaces/proconenv/lib/tools/has_mod.hpp"

namespace tools {
  template <typename T, typename = ::std::void_t<>>
  struct has_mod : ::std::false_type {};

  template <typename T>
  struct has_mod<T, ::std::void_t<decltype(::std::declval<T>().mod())>> : ::std::true_type {};

  template <typename T>
  inline constexpr bool has_mod_v = ::tools::has_mod<T>::value;
}


#line 16 "/workspaces/proconenv/lib/tools/extend_input.hpp"

namespace tools {
  namespace detail {
    namespace extend_input {
      template <typename T>
      ::std::istream& read(::std::istream& is, T& container) {
        for (auto& v : container) {
          is >> v;
        }
        return is;
      }
    }
  }
}

namespace std {
  template <class T, ::std::size_t N>
  ::std::istream& operator>>(::std::istream& is, ::std::array<T, N>& array) {
    return ::tools::detail::extend_input::read(is, array);
  }

  template <class T1, class T2>
  ::std::istream& operator>>(::std::istream& is, ::std::pair<T1, T2>& pair) {
    return is >> pair.first >> pair.second;
  }

  template <int I = 0, typename... Args>
  ::std::istream& operator>>(::std::istream& is, ::std::tuple<Args...>& tuple) {
    if constexpr (I < int(sizeof...(Args))) {
        is >> ::std::get<I>(tuple);
        return operator>><I + 1>(is, tuple);
      } else {
      return is;
    }
  }

  template <class T, class Allocator>
  ::std::istream& operator>>(::std::istream& is, ::std::vector<T, Allocator>& vector) {
    return ::tools::detail::extend_input::read(is, vector);
  }

  template <typename T>
  ::std::enable_if_t<::tools::has_mod_v<T>, ::std::istream&> operator>>(::std::istream& is, T& x) {
    long long n;
    is >> n;
    x = T(n);
    return is;
  }
}


#line 1 "/workspaces/proconenv/lib/tools/extend_output.hpp"



// WARNING:
// This file adds functions to std namespace for convenience.
// Strictly speaking, it is not allowed in C++.
// It makes the program ill-formed to include this file, and may cause undefined behavior.

#line 12 "/workspaces/proconenv/lib/tools/extend_output.hpp"
#include <optional>
#line 24 "/workspaces/proconenv/lib/tools/extend_output.hpp"

namespace tools {
  namespace detail {
    namespace extend_output {
      template <typename T>
      ::std::ostream& debug_print(::std::ostream& os, const T& container) {
        ::std::string delimiter = "";
        os << '[';
        for (const auto& v : container) {
          os << delimiter << v;
          delimiter = ", ";
        }
        os << ']';
        return os;
      }
    }
  }
}

namespace std {
  template <class T, ::std::size_t N>
  ::std::ostream& operator<<(::std::ostream& os, const ::std::array<T, N>& array) {
    return ::tools::detail::extend_output::debug_print(os, array);
  }
  
  template <class Key, class T, class Compare, class Allocator>
  ::std::ostream& operator<<(::std::ostream& os, const ::std::map<Key, T, Compare, Allocator>& map) {
    return ::tools::detail::extend_output::debug_print(os, map);
  }

  template <typename T>
  ::std::ostream& operator<<(::std::ostream& os, const ::std::optional<T>& optional) {
    if (optional) {
      return os << *optional;
    } else {
      return os << "null";
    }
  }
  
  template <class T1, class T2>
  ::std::ostream& operator<<(::std::ostream& os, const ::std::pair<T1, T2>& pair) {
    return os << '[' << pair.first << ", " << pair.second << ']';
  }
  
  template <class T, class Container>
  ::std::ostream& operator<<(::std::ostream& os, ::std::queue<T, Container>& queue) {
    ::std::queue<T, Container> other = queue;
    ::std::string delimiter = "";
    os << '[';
    while (!queue.empty()) {
      os << delimiter << queue.front();
      delimiter = ", ";
      queue.pop();
    }
    os << ']';
  
    queue = ::std::move(other);
    return os;
  }
  
  template <class Key, class Compare, class Allocator>
  ::std::ostream& operator<<(::std::ostream& os, const ::std::set<Key, Compare, Allocator>& set) {
    return ::tools::detail::extend_output::debug_print(os, set);
  }

  template <class T, class Container>
  ::std::ostream& operator<<(::std::ostream& os, ::std::stack<T, Container>& stack) {
    ::std::stack<T, Container> other;
    while (!stack.empty()) {
      other.push(stack.top());
      stack.pop();
    }
  
    ::std::string delimiter = "";
    os << '[';
    while (!other.empty()) {
      os << delimiter << other.top();
      delimiter = ", ";
      stack.push(other.top());
      other.pop();
    }
    os << ']';
  
    return os;
  }
  
  template <int I = -1, typename... Args>
  ::std::ostream& operator<<(::std::ostream& os, const ::std::tuple<Args...>& tuple) {
    if constexpr (I == -1) {
      os << '[';
    } else if constexpr (I == int(sizeof...(Args))) {
      os << ']';
    } else if constexpr (I == 0) {
      os << ::std::get<I>(tuple);
    } else {
      os << ", " << ::std::get<I>(tuple);
    }
  
    if constexpr (I < int(sizeof...(Args))) {
      return operator<<<I + 1>(os, tuple);
    } else {
      return os;
    }
  }
  
  template <class Key, class T, class Hash, class Pred, class Allocator>
  ::std::ostream& operator<<(::std::ostream& os, const ::std::unordered_map<Key, T, Hash, Pred, Allocator>& unordered_map) {
    return ::tools::detail::extend_output::debug_print(os, unordered_map);
  }
  
  template <class Key, class Hash, class Pred, class Allocator>
  ::std::ostream& operator<<(::std::ostream& os, const ::std::unordered_set<Key, Hash, Pred, Allocator>& unordered_set) {
    return ::tools::detail::extend_output::debug_print(os, unordered_set);
  }
  
  template <class T, class Allocator>
  ::std::ostream& operator<<(::std::ostream& os, const ::std::vector<T, Allocator>& vector) {
    return ::tools::detail::extend_output::debug_print(os, vector);
  }
  
  template <typename T>
  ::std::enable_if_t<::tools::has_mod_v<T>, ::std::ostream&> operator<<(::std::ostream& os, const T& x) {
    return os << x.val();
  }
}


#line 1 "/workspaces/proconenv/lib/tools/extend_hash.hpp"



// WARNING:
// This file adds partial specializations for classes in std namespace, for convenience.
// Strictly speaking, it is not allowed in C++.
// It makes the program ill-formed to include this file, and may cause undefined behavior.

#line 1 "/workspaces/proconenv/lib/tools/tuple_hash.hpp"



#line 1 "/workspaces/proconenv/lib/tools/now.hpp"



#line 5 "/workspaces/proconenv/lib/tools/now.hpp"

namespace tools {
  inline long long now() {
    return ::std::chrono::duration_cast<::std::chrono::nanoseconds>(::std::chrono::high_resolution_clock::now().time_since_epoch()).count();
  }
}


#line 1 "/workspaces/proconenv/lib/tools/hash_combine.hpp"



#line 6 "/workspaces/proconenv/lib/tools/hash_combine.hpp"

// Source: https://github.com/google/cityhash/blob/f5dc54147fcce12cefd16548c8e760d68ac04226/src/city.h
// License: MIT
// Author: Google Inc.

// Copyright (c) 2011 Google, Inc.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

namespace tools {
  template <typename T>
  void hash_combine(::std::size_t& seed, const T& v) {
    static const ::std::hash<T> hasher;
    static constexpr ::std::size_t k_mul = 0x9ddfea08eb382d69ULL;
    ::std::size_t a = (hasher(v) ^ seed) * k_mul;
    a ^= (a >> 47);
    ::std::size_t b = (seed ^ a) * k_mul;
    b ^= (b >> 47);
    seed = b * k_mul;
  }
}


#line 11 "/workspaces/proconenv/lib/tools/tuple_hash.hpp"

namespace tools {
  template <typename... Ts>
  struct tuple_hash {
    template <::std::size_t I = sizeof...(Ts) - 1>
    ::std::size_t operator()(const ::std::tuple<Ts...>& key) const {
      if constexpr (I == ::std::numeric_limits<::std::size_t>::max()) {
        static const ::std::size_t seed = ::tools::now();
        return seed;
      } else {
        ::std::size_t seed = this->operator()<I - 1>(key);
        ::tools::hash_combine(seed, ::std::get<I>(key));
        return seed;
      }
    }
  };
}


#line 14 "/workspaces/proconenv/lib/tools/extend_hash.hpp"

namespace std {
  template <class T1, class T2>
  struct hash<::std::pair<T1, T2>> {
    ::std::size_t operator()(const ::std::pair<T1, T2>& key) const {
      static const ::tools::tuple_hash<T1, T2> hasher;
      return hasher(::std::make_tuple(key.first, key.second));
    }
  };

  template <class... Args>
  struct hash<::std::tuple<Args...>> {
    ::std::size_t operator()(const ::std::tuple<Args...>& key) const {
      static const ::tools::tuple_hash<Args...> hasher;
      return hasher(key);
    }
  };
}


#line 23 "/workspaces/proconenv/lib/tools/util.hpp"

using ll = long long;
using ull = unsigned long long;
using i32 = ::std::int32_t;
using u32 = ::std::uint32_t;
using i64 = ::std::int64_t;
using u64 = ::std::uint64_t;

#define ALL(x) ::std::begin(x), ::std::end(x)
#define REP(i, n) for (long long i = 0, i##_len = static_cast<long long>(n); i < i##_len; ++i)


#line 1 "/workspaces/proconenv/lib/tools/popcount.hpp"



#include <bit>
#line 1 "/workspaces/proconenv/lib/tools/is_integral.hpp"



#line 5 "/workspaces/proconenv/lib/tools/is_integral.hpp"

namespace tools {
  template <typename T>
  struct is_integral : ::std::is_integral<T> {};

  template <typename T>
  inline constexpr bool is_integral_v = ::tools::is_integral<T>::value;
}


#line 1 "/workspaces/proconenv/lib/tools/is_signed.hpp"



#line 5 "/workspaces/proconenv/lib/tools/is_signed.hpp"

namespace tools {
  template <typename T>
  struct is_signed : ::std::is_signed<T> {};

  template <typename T>
  inline constexpr bool is_signed_v = ::tools::is_signed<T>::value;
}


#line 1 "/workspaces/proconenv/lib/tools/make_unsigned.hpp"



#line 5 "/workspaces/proconenv/lib/tools/make_unsigned.hpp"

namespace tools {
  template <typename T>
  struct make_unsigned : ::std::make_unsigned<T> {};

  template <typename T>
  using make_unsigned_t = typename ::tools::make_unsigned<T>::type;
}


#line 1 "/workspaces/proconenv/lib/tools/uint128_t.hpp"



#line 1 "/workspaces/proconenv/lib/tools/detail/int128_t.hpp"



#line 12 "/workspaces/proconenv/lib/tools/detail/int128_t.hpp"
#include <string_view>
#line 1 "/workspaces/proconenv/lib/tools/abs.hpp"



namespace tools {
  constexpr float abs(const float x) {
    return x < 0 ? -x : x;
  }
  constexpr double abs(const double x) {
    return x < 0 ? -x : x;
  }
  constexpr long double abs(const long double x) {
    return x < 0 ? -x : x;
  }
  constexpr int abs(const int x) {
    return x < 0 ? -x : x;
  }
  constexpr long abs(const long x) {
    return x < 0 ? -x : x;
  }
  constexpr long long abs(const long long x) {
    return x < 0 ? -x : x;
  }
  constexpr unsigned int abs(const unsigned int x) {
    return x;
  }
  constexpr unsigned long abs(const unsigned long x) {
    return x;
  }
  constexpr unsigned long long abs(const unsigned long long x) {
    return x;
  }
}


#line 1 "/workspaces/proconenv/lib/tools/bit_ceil.hpp"



#line 10 "/workspaces/proconenv/lib/tools/bit_ceil.hpp"

namespace tools {
  template <typename T>
  constexpr T bit_ceil(T) noexcept;

  template <typename T>
  constexpr T bit_ceil(const T x) noexcept {
    static_assert(::tools::is_integral_v<T> && !::std::is_same_v<::std::remove_cv_t<T>, bool>);
    if constexpr (::tools::is_signed_v<T>) {
      assert(x >= 0);
      return ::tools::bit_ceil<::tools::make_unsigned_t<T>>(x);
    } else {
      return ::std::bit_ceil(x);
    }
  }
}


#line 1 "/workspaces/proconenv/lib/tools/bit_floor.hpp"



#line 10 "/workspaces/proconenv/lib/tools/bit_floor.hpp"

namespace tools {
  template <typename T>
  constexpr T bit_floor(T) noexcept;

  template <typename T>
  constexpr T bit_floor(const T x) noexcept {
    static_assert(::tools::is_integral_v<T> && !::std::is_same_v<::std::remove_cv_t<T>, bool>);
    if constexpr (::tools::is_signed_v<T>) {
      assert(x >= 0);
      return ::tools::bit_floor<::tools::make_unsigned_t<T>>(x);
    } else {
      return ::std::bit_floor(x);
    }
  }
}


#line 1 "/workspaces/proconenv/lib/tools/bit_width.hpp"



#line 10 "/workspaces/proconenv/lib/tools/bit_width.hpp"

namespace tools {
  template <typename T>
  constexpr int bit_width(T) noexcept;

  template <typename T>
  constexpr int bit_width(const T x) noexcept {
    static_assert(::tools::is_integral_v<T> && !::std::is_same_v<::std::remove_cv_t<T>, bool>);
    if constexpr (::tools::is_signed_v<T>) {
      assert(x >= 0);
      return ::tools::bit_width<::tools::make_unsigned_t<T>>(x);
    } else {
      return ::std::bit_width(x);
    }
  }
}


#line 1 "/workspaces/proconenv/lib/tools/countr_zero.hpp"



#line 12 "/workspaces/proconenv/lib/tools/countr_zero.hpp"

namespace tools {
  template <typename T>
  constexpr int countr_zero(const T x) noexcept {
    static_assert(::tools::is_integral_v<T> && !::std::is_same_v<::std::remove_cv_t<T>, bool>);
    if constexpr (::tools::is_signed_v<T>) {
      assert(x >= 0);
      return ::std::min(::tools::countr_zero<::tools::make_unsigned_t<T>>(x), ::std::numeric_limits<T>::digits);
    } else {
      return ::std::countr_zero(x);
    }
  }
}


#line 1 "/workspaces/proconenv/lib/tools/is_unsigned.hpp"



#line 5 "/workspaces/proconenv/lib/tools/is_unsigned.hpp"

namespace tools {
  template <typename T>
  struct is_unsigned : ::std::is_unsigned<T> {};

  template <typename T>
  inline constexpr bool is_unsigned_v = ::tools::is_unsigned<T>::value;
}


#line 1 "/workspaces/proconenv/lib/tools/make_signed.hpp"



#line 5 "/workspaces/proconenv/lib/tools/make_signed.hpp"

namespace tools {
  template <typename T>
  struct make_signed : ::std::make_signed<T> {};

  template <typename T>
  using make_signed_t = typename ::tools::make_signed<T>::type;
}


#line 25 "/workspaces/proconenv/lib/tools/detail/int128_t.hpp"

namespace tools {
  using uint128_t = unsigned __int128;
  using int128_t = __int128;

  namespace detail {
    namespace int128_t {
      constexpr ::tools::uint128_t parse_unsigned(const ::std::string_view s) noexcept {
        assert(!s.empty());
        ::tools::uint128_t x = 0;
        ::std::size_t i = s[0] == '+';
        if (i + 1 < s.size() && s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X')) {
          for (i += 2; i < s.size(); ++i) {
            assert(('0' <= s[i] && s[i] <= '9') || ('a' <= s[i] && s[i] <= 'f') || ('A' <= s[i] && s[i] <= 'F'));
            x <<= 4;
            if ('0' <= s[i] && s[i] <= '9') {
              x |= s[i] - '0';
            } else if ('a' <= s[i] && s[i] <= 'f') {
              x |= s[i] - 'a' + 10;
            } else {
              x |= s[i] - 'A' + 10;
            }
          }
        } else {
          for (; i < s.size(); ++i) {
            assert('0' <= s[i] && s[i] <= '9');
            x *= 10;
            x += s[i] - '0';
          }
        }
        return x;
      }

      constexpr ::tools::int128_t parse_signed(const ::std::string_view s) noexcept {
        assert(!s.empty());
        ::tools::int128_t x = 0;
        if (s[0] == '-') {
          ::std::size_t i = 1;
          if (i + 1 < s.size() && s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X')) {
            for (i += 2; i < s.size(); ++i) {
              assert(('0' <= s[i] && s[i] <= '9') || ('a' <= s[i] && s[i] <= 'f') || ('A' <= s[i] && s[i] <= 'F'));
              x *= 16;
              if ('0' <= s[i] && s[i] <= '9') {
                x -= s[i] - '0';
              } else if ('a' <= s[i] && s[i] <= 'f') {
                x -= s[i] - 'a' + 10;
              } else {
                x -= s[i] - 'A' + 10;
              }
            }
          } else {
            for (; i < s.size(); ++i) {
              assert('0' <= s[i] && s[i] <= '9');
              x *= 10;
              x -= s[i] - '0';
            }
          }
        } else {
          ::std::size_t i = s[0] == '+';
          if (i + 1 < s.size() && s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X')) {
            for (i += 2; i < s.size(); ++i) {
              assert(('0' <= s[i] && s[i] <= '9') || ('a' <= s[i] && s[i] <= 'f') || ('A' <= s[i] && s[i] <= 'F'));
              x <<= 4;
              if ('0' <= s[i] && s[i] <= '9') {
                x |= s[i] - '0';
              } else if ('a' <= s[i] && s[i] <= 'f') {
                x |= s[i] - 'a' + 10;
              } else {
                x |= s[i] - 'A' + 10;
              }
            }
          } else {
            for (; i < s.size(); ++i) {
              assert('0' <= s[i] && s[i] <= '9');
              x *= 10;
              x += s[i] - '0';
            }
          }
        }
        return x;
      }
    }
  }

  constexpr ::tools::uint128_t abs(const ::tools::uint128_t& x) noexcept {
    return x;
  }
  constexpr ::tools::int128_t abs(const ::tools::int128_t& x) {
    return x >= 0 ? x : -x;
  }
}

#define UINT128_C(c) ::tools::detail::int128_t::parse_unsigned(#c)
#define INT128_C(c) ::tools::detail::int128_t::parse_signed(#c)

inline ::std::istream& operator>>(::std::istream& is, ::tools::uint128_t& x) {
  ::std::string s;
  is >> s;
  x = ::tools::detail::int128_t::parse_unsigned(s);
  return is;
}
inline ::std::istream& operator>>(::std::istream& is, ::tools::int128_t& x) {
  ::std::string s;
  is >> s;
  x = ::tools::detail::int128_t::parse_signed(s);
  return is;
}

inline ::std::ostream& operator<<(::std::ostream& os, ::tools::uint128_t x) {
  ::std::string s;
  if (x > 0) {
    while (x > 0) {
      s.push_back('0' + x % 10);
      x /= 10;
    }
  } else {
    s.push_back('0');
  }

  ::std::ranges::reverse(s);
  return os << s;
}
inline ::std::ostream& operator<<(::std::ostream& os, ::tools::int128_t x) {
  ::std::string s;
  if (x > 0) {
    while (x > 0) {
      s.push_back('0' + x % 10);
      x /= 10;
    }
  } else if (x < 0) {
    while (x < 0) {
      s.push_back('0' + (-(x % 10)));
      x /= 10;
    }
    s.push_back('-');
  } else {
    s.push_back('0');
  }

  ::std::ranges::reverse(s);
  return os << s;
}

#if defined(__GLIBCXX__) && defined(__STRICT_ANSI__)
namespace std {
  template <>
  struct hash<::tools::uint128_t> {
    ::std::size_t operator()(const ::tools::uint128_t& x) const {
      static const ::std::size_t seed = ::tools::now();

      ::std::size_t hash = seed;
      ::tools::hash_combine(hash, static_cast<::std::uint64_t>(x >> 64));
      ::tools::hash_combine(hash, static_cast<::std::uint64_t>(x & ((UINT128_C(1) << 64) - 1)));
      return hash;
    }
  };
  template <>
  struct hash<::tools::int128_t> {
    ::std::size_t operator()(const ::tools::int128_t& x) const {
      static ::std::hash<::tools::uint128_t> hasher;
      return hasher(static_cast<::tools::uint128_t>(x));
    }
  };
}
#endif

namespace tools {
  template <>
  struct is_integral<::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_integral<::tools::uint128_t> : ::std::true_type {};
  template <>
  struct is_integral<const ::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_integral<const ::tools::uint128_t> : ::std::true_type {};
  template <>
  struct is_integral<volatile ::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_integral<volatile ::tools::uint128_t> : ::std::true_type {};
  template <>
  struct is_integral<const volatile ::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_integral<const volatile ::tools::uint128_t> : ::std::true_type {};

  template <>
  struct is_signed<::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_signed<::tools::uint128_t> : ::std::false_type {};
  template <>
  struct is_signed<const ::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_signed<const ::tools::uint128_t> : ::std::false_type {};
  template <>
  struct is_signed<volatile ::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_signed<volatile ::tools::uint128_t> : ::std::false_type {};
  template <>
  struct is_signed<const volatile ::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_signed<const volatile ::tools::uint128_t> : ::std::false_type {};

  template <>
  struct is_unsigned<::tools::int128_t> : ::std::false_type {};
  template <>
  struct is_unsigned<::tools::uint128_t> : ::std::true_type {};
  template <>
  struct is_unsigned<const ::tools::int128_t> : ::std::false_type {};
  template <>
  struct is_unsigned<const ::tools::uint128_t> : ::std::true_type {};
  template <>
  struct is_unsigned<volatile ::tools::int128_t> : ::std::false_type {};
  template <>
  struct is_unsigned<volatile ::tools::uint128_t> : ::std::true_type {};
  template <>
  struct is_unsigned<const volatile ::tools::int128_t> : ::std::false_type {};
  template <>
  struct is_unsigned<const volatile ::tools::uint128_t> : ::std::true_type {};

  template <>
  struct make_signed<::tools::int128_t> {
    using type = ::tools::int128_t;
  };
  template <>
  struct make_signed<::tools::uint128_t> {
    using type = ::tools::int128_t;
  };
  template <>
  struct make_signed<const ::tools::int128_t> {
    using type = const ::tools::int128_t;
  };
  template <>
  struct make_signed<const ::tools::uint128_t> {
    using type = const ::tools::int128_t;
  };
  template <>
  struct make_signed<volatile ::tools::int128_t> {
    using type = volatile ::tools::int128_t;
  };
  template <>
  struct make_signed<volatile ::tools::uint128_t> {
    using type = volatile ::tools::int128_t;
  };
  template <>
  struct make_signed<const volatile ::tools::int128_t> {
    using type = const volatile ::tools::int128_t;
  };
  template <>
  struct make_signed<const volatile ::tools::uint128_t> {
    using type = const volatile ::tools::int128_t;
  };

  template <>
  struct make_unsigned<::tools::int128_t> {
    using type = ::tools::uint128_t;
  };
  template <>
  struct make_unsigned<::tools::uint128_t> {
    using type = ::tools::uint128_t;
  };
  template <>
  struct make_unsigned<const ::tools::int128_t> {
    using type = const ::tools::uint128_t;
  };
  template <>
  struct make_unsigned<const ::tools::uint128_t> {
    using type = const ::tools::uint128_t;
  };
  template <>
  struct make_unsigned<volatile ::tools::int128_t> {
    using type = volatile ::tools::uint128_t;
  };
  template <>
  struct make_unsigned<volatile ::tools::uint128_t> {
    using type = volatile ::tools::uint128_t;
  };
  template <>
  struct make_unsigned<const volatile ::tools::int128_t> {
    using type = const volatile ::tools::uint128_t;
  };
  template <>
  struct make_unsigned<const volatile ::tools::uint128_t> {
    using type = const volatile ::tools::uint128_t;
  };

#if defined(__GLIBCXX__) && defined(__STRICT_ANSI__)
  template <>
  constexpr ::tools::uint128_t bit_ceil<::tools::uint128_t>(::tools::uint128_t x) noexcept {
    if (x <= 1) return 1;
    --x;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 32;
    x |= x >> 64;
    return ++x;
  }

  template <>
  constexpr ::tools::uint128_t bit_floor<::tools::uint128_t>(::tools::uint128_t x) noexcept {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 32;
    x |= x >> 64;
    return x & ~(x >> 1);
  }

  template <>
  constexpr int bit_width<::tools::uint128_t>(::tools::uint128_t x) noexcept {
    int w = 0;
    if (x & UINT128_C(0xffffffffffffffff0000000000000000)) {
      x >>= 64;
      w += 64;
    }
    if (x & UINT128_C(0xffffffff00000000)) {
      x >>= 32;
      w += 32;
    }
    if (x & UINT128_C(0xffff0000)) {
      x >>= 16;
      w += 16;
    }
    if (x & UINT128_C(0xff00)) {
      x >>= 8;
      w += 8;
    }
    if (x & UINT128_C(0xf0)) {
      x >>= 4;
      w += 4;
    }
    if (x & UINT128_C(0xc)) {
      x >>= 2;
      w += 2;
    }
    if (x & UINT128_C(0x2)) {
      x >>= 1;
      w += 1;
    }
    w += x;
    return w;
  }

  namespace detail {
    namespace countr_zero {
      template <::std::size_t N>
      struct ntz_traits;

      template <>
      struct ntz_traits<128> {
        using type = ::tools::uint128_t;
        static constexpr int shift = 120;
        static constexpr type magic = UINT128_C(0x01061438916347932a5cd9d3ead7b77f);
        static constexpr int ntz_table[255] = {
          128,   0,   1,  -1,   2,  -1,   8,  -1,   3,  -1,  15,  -1,   9,  -1,  22,  -1,
            4,  -1,  29,  -1,  16,  -1,  36,  -1,  10,  -1,  43,  -1,  23,  -1,  50,  -1,
            5,  -1,  33,  -1,  30,  -1,  57,  -1,  17,  -1,  64,  -1,  37,  -1,  71,  -1,
           11,  -1,  60,  -1,  44,  -1,  78,  -1,  24,  -1,  85,  -1,  51,  -1,  92,  -1,
           -1,   6,  -1,  20,  -1,  34,  -1,  48,  31,  -1,  -1,  69,  58,  -1,  -1,  90,
           18,  -1,  67,  -1,  65,  -1,  99,  -1,  38,  -1, 101,  -1,  72,  -1, 106,  -1,
           -1,  12,  -1,  40,  -1,  61,  -1,  82,  45,  -1,  -1, 103,  79,  -1, 113,  -1,
           -1,  25,  -1,  74,  86,  -1,  -1, 116,  -1,  52,  -1, 108,  -1,  93,  -1, 120,
          127,  -1,  -1,   7,  -1,  14,  -1,  21,  -1,  28,  -1,  35,  -1,  42,  -1,  49,
           -1,  32,  -1,  56,  -1,  63,  -1,  70,  -1,  59,  -1,  77,  -1,  84,  -1,  91,
           -1,  19,  -1,  47,  -1,  68,  -1,  89,  -1,  66,  -1,  98,  -1, 100,  -1, 105,
           -1,  39,  -1,  81,  -1, 102,  -1, 112,  -1,  73,  -1, 115,  -1, 107,  -1, 119,
          126,  -1,  13,  -1,  27,  -1,  41,  -1,  -1,  55,  62,  -1,  -1,  76,  83,  -1,
           -1,  46,  -1,  88,  -1,  97,  -1, 104,  -1,  80,  -1, 111,  -1, 114,  -1, 118,
          125,  -1,  26,  -1,  54,  -1,  75,  -1,  -1,  87,  96,  -1,  -1, 110,  -1, 117,
          124,  -1,  53,  -1,  -1,  95, 109,  -1, 123,  -1,  94,  -1, 122,  -1, 121
        };
      };

      template <typename T>
      constexpr int impl(const T x) noexcept {
        using tr = ::tools::detail::countr_zero::ntz_traits<::std::numeric_limits<T>::digits>;
        using type = typename tr::type;
        return tr::ntz_table[static_cast<type>(tr::magic * static_cast<type>(x & -x)) >> tr::shift];
      }
    }
  }

  template <>
  constexpr int countr_zero<::tools::uint128_t>(const ::tools::uint128_t x) noexcept {
    return ::tools::detail::countr_zero::impl(x);
  }
#endif
}


#line 5 "/workspaces/proconenv/lib/tools/uint128_t.hpp"


#line 11 "/workspaces/proconenv/lib/tools/popcount.hpp"

namespace tools {
  template <typename T>
  constexpr int popcount(T) noexcept;

  template <typename T>
  constexpr int popcount(const T x) noexcept {
    static_assert(::tools::is_integral_v<T> && !::std::is_same_v<::std::remove_cv_t<T>, bool>);
    if constexpr (::tools::is_signed_v<T>) {
      assert(x >= 0);
      return ::tools::popcount<::tools::make_unsigned_t<T>>(x);
    } else {
      return ::std::popcount(x);
    }
  }

#if defined(__GLIBCXX__) && defined(__STRICT_ANSI__)
  template <>
  constexpr int popcount<::tools::uint128_t>(::tools::uint128_t x) noexcept {
    x = (x & UINT128_C(0x55555555555555555555555555555555)) + (x >> 1 & UINT128_C(0x55555555555555555555555555555555));
    x = (x & UINT128_C(0x33333333333333333333333333333333)) + (x >> 2 & UINT128_C(0x33333333333333333333333333333333));
    x = (x & UINT128_C(0x0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f)) + (x >> 4 & UINT128_C(0x0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f));
    x = (x & UINT128_C(0x00ff00ff00ff00ff00ff00ff00ff00ff)) + (x >> 8 & UINT128_C(0x00ff00ff00ff00ff00ff00ff00ff00ff));
    x = (x & UINT128_C(0x0000ffff0000ffff0000ffff0000ffff)) + (x >> 16 & UINT128_C(0x0000ffff0000ffff0000ffff0000ffff));
    x = (x & UINT128_C(0x00000000ffffffff00000000ffffffff)) + (x >> 32 & UINT128_C(0x00000000ffffffff00000000ffffffff));
    x = (x & UINT128_C(0x0000000000000000ffffffffffffffff)) + (x >> 64 & UINT128_C(0x0000000000000000ffffffffffffffff));
    return x;
  }
#endif
}


#line 3 "main.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, M;
  std::cin >> N >> M;
  std::vector<ll> a(M), b(M);
  REP(i, M) {
    std::cin >> a[i] >> b[i];
    --a[i], --b[i];
  }

  std::unordered_set<ll> horizontal, vertical, orthogonal1, orthogonal2;
  REP(i, M) {
    horizontal.insert(a[i]);
    vertical.insert(b[i]);
    orthogonal1.insert(-a[i] + b[i]);
    orthogonal2.insert(a[i] + b[i]);
  }

  std::unordered_map<std::pair<ll, ll>, std::int8_t> crosses;
  for (const auto i : horizontal) {
    for (const auto j : vertical) {
      if (0 <= i && i < N && 0 <= j && j < N) {
        crosses[std::make_pair(i, j)] |= 0b1100;
      }
    }
    for (const auto j : orthogonal1) {
      if (0 <= i && i < N && 0 <= i + j && i + j < N) {
        crosses[std::make_pair(i, i + j)] |= 0b1010;
      }
    }
    for (const auto j : orthogonal2) {
      if (0 <= i && i < N && 0 <= -i + j && -i + j < N) {
        crosses[std::make_pair(i, -i + j)] |= 0b1001;
      }
    }
  }
  for (const auto i : vertical) {
    for (const auto j : orthogonal1) {
      if (0 <= i - j && i - j < N && 0 <= i && i < N) {
        crosses[std::make_pair(i - j, i)] |= 0b0110;
      }
    }
    for (const auto j : orthogonal2) {
      if (0 <= -i + j && -i + j < N && 0 <= i && i < N) {
        crosses[std::make_pair(-i + j, i)] |= 0b0101;
      }
    }
  }
  for (const auto i : orthogonal1) {
    for (const auto j : orthogonal2) {
      if ((i + j) % 2 == 0 && 0 <= (-i + j) / 2 && (-i + j) / 2 < N && 0 <= (i + j) / 2 && (i + j) / 2< N) {
        crosses[std::make_pair((-i + j) / 2, (i + j) / 2)] |= 0b0011;
      }
    }
  }

  ll answer = 0;
  answer += horizontal.size() * N;
  answer += vertical.size() * N;
  for (const auto i : orthogonal1) {
    answer += N - std::abs(i);
  }
  for (const auto i : orthogonal2) {
    answer += N - std::abs(N - 1 - i);
  }
  for (const auto& [p, mask] : crosses) {
    answer -= tools::popcount(mask);
  }
  answer += crosses.size();
  answer = N * N - answer;

  std::cout << answer << '\n';
  return 0;
}
