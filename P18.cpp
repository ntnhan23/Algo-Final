#include<bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const double pi = acos(-1);

// Bài này làm bằng BFS, do chỉ có tối đa n! trạng thái của các hoán vị
// => sẽ BFS từ trạng thái ban đầu đến trạng thái đề bài cho.

int n;
vector<int> a;
map<vector<int>, int>mp;
vector<int> rev(const vector<int>&a, int pos) {
    vector<int> tmp;
    for(int i = pos - 1; i >= 0; i--) tmp.push_back(a[i]);
    for(int i = pos; i < n; i++) tmp.push_back(a[i]);
    return tmp;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        a.push_back(x);
    }

    vector<int>st;
    for(int i = 1; i <= n; i++) st.push_back(i);
    mp[st] = 0;
    queue<vector<int>>q;
    q.push(st);
    while(q.size()) {
        vector<int> tmp = q.front();
        q.pop();
        for(int i = 2; i <= n; i++) {
            vector<int> x = rev(tmp, i);
            if(!mp.count(x)) {
                mp[x] = mp[tmp] + 1;
                q.push(x);
            }
        }
    }
    cout << mp[a];
}
