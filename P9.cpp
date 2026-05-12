#include<bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;

string s, p;
int dp[55][55];
/*

dp[i][j]: match đc s[1 -> i], p[1 -> j] ko?
3TH:
    + nếu trùng ký tự: dp[i][j] -> dp[i - 1][j - 1]
    + Gặp * mà ko lặp lại: dp[i][j] -> dp[i][j - 2]
    + gặp * mà match đc: dp[i][j] -> dp[i - 1][j]
*/

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s >> p;
    int n = s.size();
    int m = p.size();
    s = " " + s;
    p = " " + p;

    // nhớ thêm TH Base
    dp[0][0] = 1;
    for(int j = 2; j <= m; j++) {
        if(p[j] == '*') dp[0][j] |= dp[0][j - 2];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(p[j] == '.' || p[j] == s[i]) dp[i][j] |= dp[i - 1][j - 1];
            else if(p[j] == '*') {
                if(j >= 2) dp[i][j] |= dp[i][j - 2];
                if(s[i] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] |= dp[i - 1][j];
                }
            }
        }
    }
    if(dp[n][m]) cout << "true";
    else cout << "false";

}
