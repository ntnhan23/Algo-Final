#include<bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;

int k, n, m;
struct nhan {
    int x, y, diff;
    nhan(int _x = 0, int _y = 0, int _diff = 0): x(_x), y(_y), diff(_diff) {}
    bool operator < (const nhan& other) const {
        return diff > other.diff;
    }
};
nhan a[1005];
int L[1005], R[1005];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(L, -0x3f, sizeof L);
    memset(R, -0x3f, sizeof R);

    cin >> k >> n >> m;
    for(int i = 1; i <= k; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].diff = a[i].x - a[i].y;
    }
    sort(a + 1, a + k + 1);
    priority_queue<int, vector<int>, greater<int> > pq;
    int sum = 0;
    for(int i = 1; i <= k; i++) {
        pq.push(a[i].x);
        sum += a[i].x;
        while(pq.size() > n) {
            sum -= pq.top();
            pq.pop();
        }
        if(pq.size() == n) L[i] = sum;
    }
    while(pq.size()) pq.pop();
    sum = 0;
    for(int i = k; i >= 1; i--) {
        pq.push(a[i].y);
        sum += a[i].y;
        while(pq.size() > m) {
            sum -= pq.top();
            pq.pop();
        }
        if(pq.size() == m) R[i] = sum;
    }
    int res = 0;
    for(int i = 0; i <= k; i++) {
        res = max(res, L[i] + R[i + 1]);
    }
    cout << res;
}
