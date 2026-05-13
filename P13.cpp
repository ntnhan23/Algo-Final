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

*/

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

}
