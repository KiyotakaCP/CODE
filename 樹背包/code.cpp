#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 310;
int n, m;
int w[MAXN];
int dp[MAXN][MAXN];
vector<int> edge[MAXN];
int dfs(int cur, int fa) {
    int p = 1;
    for (int nex : edge[cur]) {
        if (nex == fa) continue;
        int siz = dfs(nex, cur);
        for (int i = min(p, m + 1); i >= 1; i--)
            for (int j = 1; j <= siz && i + j <= m + 1; j++)
                dp[cur][i + j] = max(dp[cur][i + j], dp[cur][i] + dp[nex][j]);
        p += siz;
    }
    return p;
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int k, s;
        cin >> k >> dp[i][1];
        edge[k].push_back(i);
        edge[i].push_back(k);
    }

    dfs(0, -1);
    cout << dp[0][m + 1] << '\n';
    return 0;
}