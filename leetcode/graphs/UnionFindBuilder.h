#include "UnionFind.h"

namespace UB{
  template <class T>
  class UnionFindBuilder
  {
    T *unionFindInstance;

  public:
    UnionFindBuilder(int sz, bool isQuickFind = true);
    T getInstance();
};
}