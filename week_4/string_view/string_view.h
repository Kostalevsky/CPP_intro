#include <iostream>
#include <stdexcept>
#include <cstring>

#ifndef STRING_VIEW_H
#define STRING_VIEW_H

class StringViewOutOfRange : public std::out_of_range {
public:
  StringViewOutOfRange() : std::out_of_range("StringViewOutOfRange") {}
};

class StringView {
public:
  StringView();
  StringView(const char *string); // NOLINT
  StringView(const char *string, size_t size);

  const char &operator[](size_t i) const;
  const char &At(size_t i) const;
  const char &Front() const;
  const char &Back() const;
  size_t Size() const;
  size_t Length() const;
  bool Empty() const;
  const char *Data() const;
  void Swap(StringView &rhs);
  void RemovePrefix(size_t prefix_size);
  void RemoveSuffix(size_t suffix_size);
  StringView Substr(size_t i, size_t count);

private:
  const char *string_;
  size_t size_;
};

#endif