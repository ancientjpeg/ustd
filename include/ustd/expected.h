/**
 * @file expected.h
 * @author Jackson Kaplan (jackson@minimal.audio)
 * @date 2024-11-09
 * Copyright © 2024 Jackson Kaplan. All rights reserved.
 */

#ifndef USTD_EXPECTEd_H_
#define USTD_EXPECTEd_H_

#include <iostream>
#include <string>

namespace ustd {
struct unexpected {
  unexpected(std::string message) : msg(message)
  {
  }

  std::string msg;
};

class __expected_base {
public:
  virtual std::string message() const = 0;

  bool                ok() const
  {
    return success_;
  }

  operator bool() const
  {
    return ok();
  }

protected:
  __expected_base(bool success) : success_(success)
  {
  }

  bool success_;
};

template <typename T>
class expected final : public __expected_base {

public:
  using type = T;

  expected(T value)
      : __expected_base(true), value_(std::in_place_index<1>, value)
  {
  }

  expected(unexpected failure)
      : __expected_base(false), value_(std::in_place_index<0>, failure.msg)
  {
  }

  std::string message() const override
  {
    return value_.index() == 0 ? std::get<0>(value_) : "";
  }

  T &operator*()
  {
    return std::get<1>(value_);
  }

private:
  std::variant<std::string, T> value_;
};

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const expected<T> &result)
{
  const char *msg = result.ok() ? "Succeeded" : "Failed";
  os << msg;
  const auto message = result.message();
  if (!result.ok()) {
    if (!message.empty()) {
      os << " with message: " << message;
    }
    else {
      os << " with no message";
    }
  }
  return os;
}

using result = expected<void>;

} // namespace ustd
#endif