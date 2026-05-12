#include<bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;

// so khớp chuỗi KMP
string a, b;
int pi[2000005];


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> a >> b;
    string s = b + "#" + a;
    int pos = 0;
    for(int i = 1; i < s.size(); i++) {
        while(pos > 0 && s[pos] != s[i]) pos = pi[pos - 1];
        if(s[pos] == s[i]) pos++;
        pi[i] = pos;
    }
    int len = b.size();
    for(int i = len + 1; i < s.size(); i++) {
        if(pi[i] == len) cout << (i - len) - len + 1 << " ";
    }
}
