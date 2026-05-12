#include<bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m;
ii a[100005], b[100005];

// 2 con trỏ, sum > 0 thì giảm thằng phải, sum < 0 thì tăng thằng trái, sum = 0 break luôn.

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i].fi;
        b[i].se = i;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    int maxx = 1e18;
    int ans_a, ans_b;
    int pos_a = 1, pos_b = m;
    while(pos_a <= n && pos_b >= 1) {
        int sum = a[pos_a].fi + b[pos_b].fi;
        if(abs(sum) < maxx) {
            maxx = abs(sum);
            ans_a = a[pos_a].se;
            ans_b = b[pos_b].se;
        }
        if(sum > 0) pos_b--;
        else if(sum == 0) break;
        else pos_a++;
    }
    cout << ans_a << " " << ans_b;
}
