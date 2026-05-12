#include<bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;

int k;
// có thể làm ý tưởng khác là k con trỏ.

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> k;
    vector<int>val;

    string s;
    getline(cin, s); // để ăn dấu xuống dòng

    for(int i = 1; i <= k; i++) {
        getline(cin, s);
        stringstream ss(s);
        int x;
        while(ss >> x) {
            val.push_back(x);
        }
    }
    sort(val.begin(), val.end());
    for(auto x: val) cout << x << " ";
}
