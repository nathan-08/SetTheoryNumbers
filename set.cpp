#include "set.hpp"
#include <iostream>
using namespace std;

Set::Set() { };

Set::Set(std::initializer_list<Set*> l): s(l) {
  cout << "set({...})" << endl;
}

Set::Set(const Set& rhs) { cout << "copy" << endl; };

Set::Set(Set&& rhs) { cout << "move" << endl; };

bool Set::empty() {
  return s.empty();
}

size_t Set::size() const {
  return s.size();
}

Set* Set::copy() {
  Set* cpy = new Set();
  cpy->s = s;
  return cpy;
}

void Set::print(ostream& os) const {
  os << "{";
  for (Set* set: s) {
    set->print(os);
  }
  os << "}";
}

Nat::Nat() = default;

Nat& Nat::suc() {
  s.push_back(this->copy());
  return *this;
}

Nat Nat::zero() { return {}; }

Nat Nat::from_int(int num) {
  Nat n = zero();
  for (int i = 0; i < num; ++i) {
    n.suc();
  }
  return n;
}

