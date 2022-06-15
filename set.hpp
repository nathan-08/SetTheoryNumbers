#ifndef _SET_HPP
#define _SET_HPP
#include <vector>
#include <initializer_list>
#include <iostream>

class Set {
private:
public:
  std::vector<Set*> s;
  Set();
  Set(std::initializer_list<Set*>);
  Set(const Set& rhs);
  Set(Set&& rhs);
  Set* copy();
  bool empty();
  size_t size() const;
  bool operator==(const Set& rhs) const {
    if (rhs.size() != size()) return false;
    for (const Set* subset: s) {
      if (!rhs.has(subset)) return false;
    }
    return true;
  }
  bool has(const Set* subset) const {
    for (const Set* this_set: s) {
      if (*this_set == *subset) return true;
    }
    return false;
  }
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
