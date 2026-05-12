#include<bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;

int n;
ii a[100005];
int bit[100005];
void update(int pos) {
    for(int i = pos; i >= 1; i -= i&-i) {
        bit[i]++;
    }
}
int get(int pos) {
    int ans = 0;
    for(int i = pos; i <= n; i += i&-i) {
        ans += bit[i];
    }
    return ans;
}

// CTDL: BIT

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }

    int res = 0;
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        int pos = i;
        while(pos + 1 <= n && a[i].fi == a[pos + 1].fi) pos++;

        for(int j = i; j <= pos; j++) {
            res += get(a[j].se + 1);
        }
        for(int j = i; j <= pos; j++) {
            update(a[j].se);
        }
        i = pos;
    }
    cout << res;
}
