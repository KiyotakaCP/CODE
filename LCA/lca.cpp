#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int MAXN = 2e5 + 10;
int n, q;
int anc[MAXN][25], in[MAXN], out[MAXN];
vector<int> vec[MAXN];
int timing = 1;
void dfs(int cur, int fa) {
    anc[cur][0] = fa;
    in[cur] = timing++;
    for (int nex : vec[cur]) {
        if (nex == fa) continue;
        dfs(nex, cur);
    }
    out[cur] = timing++;
}
void init() {
    dfs(1, 0);
    for (int i = 1; i < 25; i++) {
        for (int cur = 1; cur <= n; cur++) {
            anc[cur][i] = anc[anc[cur][i - 1]][i - 1];
        }
    }
}
bool isanc(int u, int v) { return (in[u] <= in[v] && out[v] <= out[u]); }
int lca(int a, int b) {
    if (isanc(a, b)) return a;
    if (isanc(b, a)) return b;
    for (int i = 24; i >= 0; i--) {
        if (anc[a][i] == 0) continue;
        if (!isanc(anc[a][i], b)) a = anc[a][i];
    }

    return anc[a][0];
}
signed main() {
    fastio;
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        vec[u].pb(i);
    }
    init();

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}