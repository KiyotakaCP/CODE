#include <bits/stdc++.h>
using namespace std;

#define cl(x) (x << 1)
#define cr(x) (x << 1) + 1
struct SEG2
{
    int n;
    vector<int> seg;
    vector<int> arr, tag;
    void init(int a)
    {
        n = a;
        seg.resize(4 * n + 5, 0);
        tag.resize(4 * n + 5, 0);
        arr.resize(a + 1, 0);
    }
    void push(int id, int l, int r) // 把懶人標記往下推
    {
        if (tag[id])
        {
            seg[id] += tag[id] * (r - l + 1);
            if (l != r)
            {
                tag[cl(id)] += tag[id];
                tag[cr(id)] += tag[id];
            }
            tag[id] = 0;
        }
    }
    void pull(int id, int l, int r)
    {
        int mid = (l + r) >> 1;
        push(cl(id), l, mid);
        push(cr(id), mid + 1, r);
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
        pull(id, l, r);
    }
    void update(int id, int l, int r, int ql, int qr, int v)
    {
        push(id, l, r);
        if (ql <= l && r <= qr)
        {
            tag[id] += v;
            return;
        }
        int mid = (l + r) >> 1;
        if (ql <= mid)
            update(cl(id), l, mid, ql, qr, v);
        if (qr > mid)
            update(cr(id), mid + 1, r, ql, qr, v);
        pull(id, l, r);
    }
    int query(int id, int l, int r, int ql, int qr)
    {
        push(id, l, r);
        if (ql <= l && r <= qr)
        {
            return seg[id];
        }
        int mid = (l + r) >> 1;
        int ret = 0;
        if (ql <= mid)
            ret += query(cl(id), l, mid, ql, qr);
        if (qr > mid)
            ret += query(cr(id), mid + 1, r, ql, qr);
        return ret;
    }
    void build()
    {
        build(1, 1, n);
    }
    int query(int ql, int qr)
    {
        return query(1, 1, n, ql, qr);
    }
    void update(int ql, int qr, int val)
    {
        query(1, 1, n, ql, qr);
    }
};