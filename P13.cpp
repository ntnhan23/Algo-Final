#include<bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;

/*
Tổng hợp các kiến thức hình học cơ bản

1. Vector

Point: A, B
Vector AB = (xB - xA, yB - yA)

Vector: A, B
A = (u1, v1)
B = (u2, v2)
|A| = sqrt(u1^2 + v1^2)

A + B = (u1 + u2, v1 + v2)
A - B = A + (-B) = (u1 - u2, v1 - v2)

Dot product: AB = u1u2 + v1v2 = |A| * |B| * cos()
            => cos(alpha) = AB / (|A| * |B|)
            => alpha = arccos(AB / (|A| * |B|))

Cross product: thu được 1 vector mới vuông góc với 2 vector đã cho

            AxB = u1v2 - u2v1 = |A| * |B| * sin()
            => Hàm sin tương ứng trục y => 0 <= alpha <= 180 thì sin() > 0 => tích có hướng dương => quay trái
            => ngược lại tích có hướng ấm là quay phải.
            cross = 0 => cùng phương
                + dot > 0: cùng hướng
                + dot < 0: ngược hướng 

            => Diện tích tam giác: có 2 vector là AB và AC => S = 1/2 * cross(AB, AC)

Khoảng cách từ C -> đường thằng AB: diện tích tam giác / (1/2 cạnh đáy) = chiều cao
            => KC = abs(cross(AB, AC)) / |AB|
            
Khoảng cách từ C -> đoạn thằng AB: nếu chân đường vuông góc nằm ngoài thì lấy min đến 2 đầu mút
            0 -> 90 thì cos >= 0
            90 -> 180 thì cos <= 0
            vậy thì nếu tích vô hướng (dot product): dot(BA, BC) >= 0 và dot(AB, AC) >= 0 thì chân đường cao sẽ nằm trong đoạn AB => áp dụng công thức trên
            Ngược lại thì lấy min đến 2 đầu mút

Diện tích đa giác: 1/2(cross(P1, P2)....cross(Pn,P1)) với Pi là vector từ (0,0) -> P[i]

*/

int n;
ii a[1005];
//Do tính chất của bài => từ 1 điểm bất kỳ luôn tồn tại 1 điểm sao cho chia thành 2 nửa bằng nhau
// => cố định điểm 1 rồi sau đó duyệt mọi đỉnh còn lại.


// Giả sử ông thầy bảo tăng lên 1e6 thì làm kiểu gì???
/*
1. Tạo các vector Pi = vec(P1[i], P[i])
2. Sort các vector lại theo góc tăng dần, có 1 kiểu sort khá hay là:
    + Nếu như 2 thằng nằm ở khác mặt phẳng thì thằng ở mặt trên luôn trước thằng ở dưới.
    + cùng mặt phẳng thì mình sẽ sort để thằng trước quay trái sang thằng sau => cross > 0

3. Áp dụng 2 con trỏ vào là AC. do các vector nằm bên trái / bên phải sẽ nằm trên 1 đoạn liên tiếp rồi.
*/

ii Vec(ii A, ii B) {
    return {B.fi - A.fi, B.se - A.se};
}

int cross(ii A, ii B) {
    return A.fi * B.se - A.se * B.fi;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }

    for(int i = 2; i <= n; i++) {
        int dem = 0;
        for(int j = 2; j <= n; j++) {
            if(i != j) {
                if(cross(Vec(a[1], a[i]), Vec(a[1], a[j])) < 0) dem++;
            }
        }
        if(dem == n / 2 - 1) {
            cout << 1 << " " << i;
            break;
        }
    }
}
