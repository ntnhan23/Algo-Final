#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
int ans[1005];
vector<int> prime;
bool kt[2005];

// n = 1e6 thì dùng FFT để giải.

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for(int i = 2; i * i <= 2000; i++) {
        if(kt[i] == 0) {
            for(int j = i * i; j <= 2000; j += i) {
                kt[j] = 1;
            }
        }
    }

    for(int i = 2; i <= 2000; i++) {
        if(kt[i] == 0) prime.push_back(i);
    }

    for(int i = 0; i < prime.size(); i++) {
        for(int j = i; j < prime.size(); j++) {
            int tmp = prime[i] + prime[j];
            if(tmp <= 2000 && tmp % 2 == 0) {
                ans[tmp / 2]++;
            }
        }
    }
    for(int i = 1; i <= 1000; i++) ans[i] += ans[i - 1];
    cin >> n;
    cout << ans[n];
}
