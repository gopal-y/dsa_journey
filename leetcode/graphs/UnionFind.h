#include "customHeader.hpp"

class UnionFind
{
    vi root;

public:
    UnionFind(int sz);
    int find(int i);
    void performUnion(int x, int y);
    bool isConnected(int x, int y);
};