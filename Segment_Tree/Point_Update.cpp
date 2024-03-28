#include <bits/stdc++.h>
using namespace std;

#define cl(x) (x << 1)
#define cr(x) (x << 1) + 1
struct SEG
{
    int n;
    vector<int> seg;
    vector<int> arr;
    void init(int a)
    {
        n = a;
        seg.resize(4 * n + 5);
        arr.resize(a + 5);
    }
    void pull(int id)
    {
        int a = seg[cl(id)];
        int b = seg[cr(id)];
        seg[id] = a + b;
    }
    void build(int id, int l, int r)
    {
        if (l == r)
        {
            seg[id] = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(cl(id), l, mid);
        build(cr(id), mid + 1, r);
        pull(id);
    }
    void update(int id, int l, int r, int x, int v)
    {
        if (l == r)
        {
            seg[id] = v;
            return;
        }
        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            update(cl(id), l, mid, x, v);
        }
        if (mid < x)
        {
            update(cr(id), mid + 1, r, x, v);
        }
        pull(id);
    }
    int query(int id, int l, int r, int sl, int sr)
    {
        if (sl <= l && r <= sr)
        { // 目前這個區間在查詢區間內
            return seg[id];
        }
        int mid = (l + r) >> 1;
        int ans1 = 0, ans2 = 0;
        if (sl <= mid)
        { // 左區間跟查詢區間有交集
            ans1 = query(cl(id), l, mid, sl, sr);
        }
        if (mid < sr)
        { // 右區間跟查詢區間有交集
            ans2 = query(cr(id), mid + 1, r, sl, sr);
        }
        return ans1 + ans2;
    }
};