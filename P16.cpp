#include<bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const double pi = acos(-1);

/*
n <= 1000 thì bfs tìm khoảng cách giữa mọi cặp đỉnh là đc.

Nếu hỏi n = 1e5 thì đổi logic thành mỗi cạnh đóng góp vào bao nhiêu cặp đỉnh
    + thấy mỗi cạnh u - v sẽ chia cây thành 2 phần sz[v] và phần còn lại là (n - sz[v))
        => số cặp là sz[v] * (n - sz[v])
*/
int n;
vector<int> e[100005];
int kt[1005];

int sz[100005];

void dfs(int u, int p, int &res) {
    sz[u] = 1;
    for(auto v: e[u]) {
        if(v != p) {
            dfs(v, u, res);
            sz[u] += sz[v];
            res += sz[v] * (n - sz[v]);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if(n <= 1000) {
        int res = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) kt[j] = 0;
            queue<int> q;
            q.push(i);
            kt[i] = 1;
            while(q.size()) {
                int u = q.front();
                q.pop();
                for(auto v: e[u]) {
                    if(kt[v] == 0) {
                        kt[v] = kt[u] + 1;
                        res += (kt[v] - 1);
                        q.push(v);
                    }
                }
            }
        }
        cout << res / 2;
    }
    else {
        int res = 0;
        dfs(1, 1, res);
        cout << res;
    }

}
