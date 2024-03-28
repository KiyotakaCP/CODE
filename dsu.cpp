#include <bits/stdc++.h>
using namespace std;

struct STRUCT_DSU {
    vector<int> f, sz;
    void init(int n) {
        f.resize(n), sz.resize(n);
        for (int i = 0; i < n; i++) {
            f[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if (x == f[x]) return x;
        f[x] = find(f[x]);
        return find(f[x]);
    }

    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        if (sz[x] < sz[y])
            swap(x, y);
        sz[x] += sz[y];
        f[y] = x;
    }
};