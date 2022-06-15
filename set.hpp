#ifndef _SET_HPP
#define _SET_HPP
#include <vector>
#include <initializer_list>
#include <iostream>
#include <memory>

class Set {
private:
public:
  std::vector<std::shared_ptr<Set>> s;
  Set();
  Set(std::initializer_list<std::shared_ptr<Set>>);
  Set(const Set& rhs);
  Set(Set&& rhs);
  std::shared_ptr<Set> copy();
  bool empty();
  size_t size() const;
  bool operator==(const Set& rhs) const;
  bool has(const std::shared_ptr<Set>) const;
  void print(std::ostream& os) const;
  friend std::ostream& operator<<(std::ostream& os, const Set& s) {
    s.print(os);
    return os;
  }
};

class Nat : public Set {
private:
  Nat();
public:
  static Nat zero();
  static Nat from_int(int);
  Nat& suc();
};

#endif
