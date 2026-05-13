#include<bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;

/*
Do là đa giác lồi rồi nên là có thể vừa duyệt vừa tính diện tích tam giác rồi cộng vào thôi.

Không chia 2 đỡ xử lý sai số
*/

ii a[1005];
int n;

ii Vec(ii A, ii B) {
    return {B.fi - A.fi, B.se - A.se};
}

int area(ii A, ii B, ii C) {
    ii AB = Vec(A, B);
    ii AC = Vec(A, C);
    return abs(AB.fi * AC.se - AB.se * AC.fi); 
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;

    int res = 1e18;
    int pos_a = -1, pos_b = -1;
    int S = 0;
    for(int i = 3; i <= n; i++) {
        S += area(a[1], a[i - 1], a[i]);
    }

    for(int i = 1; i <= n; i++) {
        int S1 = 0;
        for(int j = i + 2; j <= n; j++) {
            if(i == 1 && j == n) continue;
            S1 += area(a[i], a[j], a[j - 1]);
            if(abs(S - 2*S1) < res) {
                res = abs(S - 2 * S1);
                pos_a = i;
                pos_b = j;
            }
        }
    }
    cout << pos_a << " " << pos_b;


}
