#include "customHeader.hpp"

namespace QuickFind
{
    class UnionFind
    {
        vi root;

    public:
        UnionFind(int sz);
        int find(int i);
        void performUnion(int x, int y);
        bool isConnected(int x, int y);
    };
}

namespace QuickUnion {
    class UnionFind
    {
        vi root;

    public:
        UnionFind(int sz);
        int find(int i);
        void performUnion(int x, int y);
        bool isConnected(int x, int y);
    };

}
