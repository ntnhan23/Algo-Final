#include<bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const double pi = acos(-1);

int gt[21];
bool kt[21];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    gt[0] = 1;
    for(int i = 1; i <= 20; i++) gt[i] = gt[i - 1] * i;

    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<int> a;
    int x;
    while(ss >> x) {
        a.push_back(x);
    }

    int stt;
    cin >> stt;

    int ans_1 = 0;
    int n = a.size();
    for(int i = 0; i < a.size(); i++) {
        int dem = 0;
        for(int j = 1; j < a[i]; j++) {
            if(kt[j] == 0) dem++;
        }
        ans_1 += dem * gt[n - i - 1];
        kt[a[i]] = 1;
    }
    cout << ans_1 + 1 << "\n";

    for(int i = 1; i <= n; i++) kt[i] = 0;
    vector<int> ans_2;
    stt--;

    for(int i = 0; i < n; i++) {
        int val = gt[n - i - 1];
        int pos = stt / val + 1;
        stt %= val;
        for(int j = 1; j <= n; j++) {
            if(kt[j] == 0) {
                pos--;
                if(pos == 0) {
                    kt[j] = 1;
                    ans_2.push_back(j);
                    break;
                }
            }
        }
    }


    for(int i = 0; i < n; i++) cout << ans_2[i] << " ";




}
