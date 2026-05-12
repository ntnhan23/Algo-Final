#include<bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;

vector<vector<int>> ans;
int m;

bool cot[20], c1[20], c2[20];
vector<int> a;
void trau(int hang) {
    if(hang == 5) {
        ans.push_back(a);
        return;
    }
    for(int i = 1; i <= m; i++) {
        if(cot[i] == 0 && c1[i + hang] == 0 && c2[i - hang + 9] == 0) {
            a.push_back(i);
            cot[i] = 1;
            c1[i + hang] = 1;
            c2[i - hang + 9] = 1;
            trau(hang + 1);
            a.pop_back();
            cot[i] = 0;
            c1[i + hang] = 0;
            c2[i - hang + 9] = 0;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> m;
    trau(1);

    cout << ans.size() << "\n";
    for(int t = 0; t < ans.size(); t++) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                if(j + 1 == ans[t][i]) cout << 'Q';
                else cout << '.';
            }
            cout << "\n";
        }
        cout << "\n";
    }
}
