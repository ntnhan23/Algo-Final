#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, k;
int a[1005];

int gcd(int a, int b) {
    if(a > b) swap(a, b);
    if(a == 0) return b;
    return gcd(b % a, a);
}

// n = 1e6 thì dùng sparse table để tìm GCD trên 1 đoạn liên tiếp nhanh.

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    int res = 0;

    for(int i = 1; i + k - 1 <= n; i++) {
        int tmp = a[i];
        for(int j = 1; j < k; j++) {
            tmp = gcd(tmp, a[i + j]);
        }
        res = max(res, tmp);
    }
    cout << res;
}
