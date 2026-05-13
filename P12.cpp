#include<bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;

/*
Area = a => cạnh = sqrt(a)
=> b^2 + c^2 = a
*/

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a; cin >> a;
    bool ok = 0;
    for(int b = 0; b * b <= a; b++) {
        for(int c = 0; c * c <= a - b * b; c++) {
            if(b * b + c * c == a) {
                ok = 1;
                int x = 0;
                int y = 0;
                cout << x << " " << y << "\n";
                x += b;
                y += c;
                cout << x << " " << y << "\n";
                x += c;
                y -= b;
                cout << x << " " << y << "\n";
                x -= b;
                y -= c;
                cout << x << " " << y << "\n";
                ok = 1;
                break;
            }
        }
    }
    if(ok == 0) cout << "Impossible";
}
