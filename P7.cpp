#include<bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;

int n;
int a[100005], L[100005], R[100005];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    L[1] = a[1];
    for(int i = 2; i <= n; i++) L[i] = max(L[i - 1], a[i]);

    R[n] = a[n];
    for(int i = n - 1; i >= 1; i--) R[i] = max(R[i + 1], a[i]);
    int res = 0;
    for(int i = 2; i < n; i++) {
        int tmp = min(L[i - 1], R[i + 1]);
        res += max(0ll, tmp - a[i]);
    }
    cout << res;
}
