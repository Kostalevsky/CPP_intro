#ifndef IS_SORTED_UNTIL_H
#define IS_SORTED_UNTIL_H

template <typename T>
T *IsSortedUntil(T *begin, T *end) {
  if (begin == end) {
    return end;
  }
  for (T *i = begin + 1; i != end; i++) {
    if (*i < *(i - 1)) {
      return i;
    }
  }

  return end;
}

#endif

