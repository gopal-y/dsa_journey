#include "UnionFind.h"

namespace QuickFind
{
    UnionFind::UnionFind(int sz) : root(sz)
    {
        for (int i = 0; i < sz; i++)
        {
            root[i] = i;
        }
    }

    int UnionFind::find(int i)
    {
        return root[i];
    }

    void UnionFind::performUnion(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            for (int i = 0; i < root.size(); i++)
            {
                if (root[i] == rootY)
                {
                    root[i] == rootX;
                }
            }
        }
    }

    bool UnionFind::isConnected(int x, int y)
    {
        return find(x) == find(y);
    }
}

namespace QuickUnion
{
    UnionFind::UnionFind(int sz) : root(sz)
    {
        for (int i = 0; i < sz; i++)
        {
            root[i] = i;
        }
    }

    int UnionFind::find(int i)
    {
        while (i != root[i])
        {
            i = root[i];
        };

        return i;
    }

    void UnionFind::performUnion(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            root[rootY] = rootX;
        }
    }

    bool UnionFind::isConnected(int x, int y)
    {
        return find(x) == find(y);
    }
}
