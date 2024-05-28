#include "string_view.h"

StringView::StringView() : string_(nullptr), size_(0) {}

StringView::StringView(const char *string)
    : string_(string), size_(std::strlen(string)) {}

StringView::StringView(const char *string, size_t size)
    : string_(string), size_(size) {}

const char &StringView::operator[](size_t i) const{
  return string_[i];
}

const char &StringView::At(size_t i) const{
  if (i > size_ - 1) {
    throw StringViewOutOfRange{};
  }
  return string_[i];
}

const char &StringView::Front() const{
  return string_[0];
}

const char &StringView::Back() const{
  return string_[size_ - 1];
}

size_t StringView::Size() const{
  return size_;
}

size_t StringView::Length() const{
  return size_;
}

bool StringView::Empty() const{
  return size_ == 0;
}

const char *StringView::Data() const{
  return string_;
}

void StringView::Swap(StringView &rhs) {
  const char *temp = string_;
  string_ = rhs.string_;
  rhs.string_ = temp;

  size_t size_temp = size_;
  size_ = rhs.size_;
  rhs.size_ = size_temp;
}

void StringView::RemovePrefix(size_t prefix_size) {
  if (size_ < prefix_size) {
    throw StringViewOutOfRange{};
  }
  string_ += prefix_size;
  size_ -= prefix_size;

}

void StringView::RemoveSuffix(size_t suffix_size) {
  if (size_ < suffix_size) {
    throw StringViewOutOfRange{};
  }
  size_ -= suffix_size;
}

StringView StringView::Substr(size_t i, size_t count = -1) {
  if (size_ - 1 < i) {
    throw StringViewOutOfRange{};
  }
  StringView string = StringView(string_ + i, std::min(count, Size() - i));
  return string;
}