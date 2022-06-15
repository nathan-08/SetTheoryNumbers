#include "set.hpp"
using namespace std;

Set::Set() { };

Set::Set(std::initializer_list<shared_ptr<Set>> l): s(l) {
}

Set::Set(const Set& rhs) { cout << "copy" << endl; };

Set::Set(Set&& rhs) { cout << "move" << endl; };

bool Set::empty() {
  return s.empty();
}

size_t Set::size() const {
  return s.size();
}

bool Set::operator==(const Set& rhs) const {
  if (rhs.size() != size()) return false;
  for (const std::shared_ptr<Set> subset: s) {
    if (!rhs.has(subset)) return false;
  }
  return true;
}
bool Set::has(const shared_ptr<Set> subset) const {
  for (const std::shared_ptr<Set> this_set: s) {
    if (*this_set == *subset) return true;
  }
  return false;
}

shared_ptr<Set> Set::copy() {
  shared_ptr<Set> cpy = shared_ptr<Set>(new Set());
  cpy->s = s;
  return cpy;
}

void Set::print(ostream& os) const {
  os << "{";
  for (shared_ptr<Set> set: s) {
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

