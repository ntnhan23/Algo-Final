#include<bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const double pi = acos(-1);

/*
Khớp cầu cơ bản.

Lưu ý bài này ko bảo đồ thị ban đầu liên thông => phải code trường hợp tổng quát
nếu ko phải cầu đáp án là 0.
*/

int n, m;
vector<ii> e[100005];
int num[100005], low[100005], kt[100005], cnt;
int sz[100005], boss[100005];
int par[100005];
bool cau[100005];
ii canh[100005];

void dfs(int u, int x) {
    num[u] = low[u] = ++cnt;
    sz[u] = 1;
    boss[u] = x;
    for(auto [v, id]: e[u]) {
        if(kt[id] == 0) {
            kt[id] = 1;
            if(num[v] == 0) {
                dfs(v, x);
                sz[u] += sz[v];
                par[v] = u;
                low[u] = min(low[u], low[v]);
                if(low[v] == num[v]) cau[id] = 1;
            }
            else {
                low[u] = min(low[u], num[v]);
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back({v, i});
        e[v].push_back({u, i});
        canh[i].fi = u;
        canh[i].se = v;
    }

    for(int i = 1; i <= n; i++) {
        if(num[i] == 0) {
            dfs(i, i);
        }
    }

    for(int i = 1; i <= m; i++) {
        if(cau[i]) {
            int u = canh[i].fi;
            int v = canh[i].se;
            if(par[v] != u) swap(u, v);
            int cha = boss[v];
            int ans = sz[v] * (sz[cha] - sz[v]);
            cout << ans << "\n";
        }
        else cout << 0 << "\n";
    }
}
