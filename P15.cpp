#include<bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const double pi = acos(-1);

ii A, B;
int R;
/*
ANS = S(O1) + S(O2) - overlap

overlap = 2 phần quạt - 2 phần tam giác

*/

int kc(ii A, ii B) {
    int x = abs(A.fi - B.fi);
    int y = abs(A.se - B.se);
    return x * x + y * y;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> A.fi >> A.se >> B.fi >> B.se >> R;

    double ANS = 2.0 * pi * R * R;
    double overlap = 0;

    if(kc(A, B) < 4 * R * R) {
        double d = sqrt(kc(A, B));
        double alpha = acos(d/(2 * R));
        double S_quat = alpha * R * R;
        double IA = sqrt(R * R - d * d / 4);
        double S_tg = 0.5 * IA * d;
        overlap = 2.0 * (S_quat - S_tg);
    }
    else if(kc(A, B) == 0) {
        ANS /= 2;
    }
    ANS -= overlap;
    cout << setprecision(3) << fixed << ANS;
}
