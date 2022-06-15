#include "set.hpp"
using namespace std;

int main() {
  for (int i = 0; i < 11; ++i) {
    cout << i << ": " << Nat::from_int(i) << endl << endl;
  }
}
