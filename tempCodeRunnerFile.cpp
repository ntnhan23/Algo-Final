#include<bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const double pi = acos(-1);

int n, T;
int a[100005];
int A[100005], sum_A[100005];
int B[100005], sum_B[100005];

// chặt nhị phân đáp án
/*
Vấn đề là bây giờ chọn 1 vị trí làm minn rồi check thì tốn O(n^2) khá chậm


giả sử vị trí chọn là min là pos => điều kiện cho bên trái là b[i] <= minn + (pos - i)
                                    => điều kiện cho bên phải là b[i] <= minn + (i - pos)
=> tông số coin tốn là SIGMA(max(0ll, a[i] - (minn + abs(i - pos))) nếu tồn tại 1 pos mà tổng này <= T thì tạo đc
=> tốn N^2

Tối ưu như thế nào???

Xét bên trái thì limit = minn + i - pos => a[i] > minn + pos - i thì cần đào xuống
                                       <=> a[i] + i > minn + pos

    Đặt A[i] = a[i] + i => điều kiện thành A[i] > minn + pos
    thấy rằng mảng ban đầu cho là chênh lệch tối đa 1 => cùng lắm là -1 => mảng A[i] sẽ ko giảm => chặt nhị phân trên mảng A[i] để tìm vị trí đầu tiên cần đào

    Tưởng tự với bên phải: a[i] > minn + i - pos <=> a[i] - i > minn - pos
                            B[i] = a[i] - i => B[] sẽ là mảng giảm (ko tăng)
*/
bool check(int minn) {

    for(int i = 1; i <= n; i++) {
        int need = 0;
        if(i > 1) {
            int pos = upper_bound(A + 1, A + n + 1, minn + i) - A;
            if(pos < i) {
                int dem = (i - 1) - pos + 1;
                need += sum_A[i - 1] - sum_A[pos - 1];
                need -= dem * (minn + i);
            }
        }
        if(i < n) {
            int l = 1, r = n, pos = 0;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(B[mid] > minn - i) {
                    l = mid + 1;
                    pos = mid;
                }
                else r = mid - 1;
            }
            //i + 1 -> pos
            if(pos > i) {
                int dem = pos - (i + 1) + 1;
                need += sum_B[pos] - sum_B[i];
                need -= dem * (minn - i);
            }
        }
        if(need <= T) {
            return 1;
        }
    }
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> T;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) {
        A[i] = a[i] + i;
        sum_A[i] = sum_A[i - 1] + A[i];
    }
    for(int i = n; i >= 1; i--) {
        B[i] = a[i] - i;
        sum_B[i] = sum_B[i + 1] + B[i];
    }

    int l = -1e16, r = 1e16, ans = l;
    for(int i = 1; i <= n; i++) {
        r = min(r, a[i]);
    }
    ans = r;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    cout << ans;

}
