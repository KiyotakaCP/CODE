#include <bits/stdc++.h>
using namespace std;


template<class Container = std::vector<int>> class DisjointSetUnion {
public:
    using value_type = typename Container::value_type;
    using reference = typename Container::reference;
    using const_reference = typename Container::const_reference;
    using size_type = typename Container::size_type;
    using container_type = Container;
    using allocator_type = typename Container::allocator_type;
    static_assert(std::is_signed_v<value_type>, "DisjointSetUnion / Container::value_type must be signed.");
    int parent[200000];
    size_type counter = 0;
    value_type find(value_type n) noexcept {
        if (parent[n] < 0) return n;
        return parent[n] = root(parent[n]);
    }
    bool same(size_type a, size_type b) {
        return root(static_cast<value_type>(a)) == root(static_cast<value_type>(b));
    }
    void merge(size_type a, size_type b) {
        value_type ar = root(static_cast<value_type>(a)), br = root(static_cast<value_type>(b));
        if (ar == br) return;
        if (parent[ar] < parent[br]) {
            parent[ar] += parent[br];
            parent[br] = ar;
        } else {
            parent[br] += parent[ar];
            parent[ar] = br;
        }
        return;
    }
};

