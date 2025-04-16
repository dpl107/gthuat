
# 1. Kadane 2D (Dồn Hàng)

## Ý tưởng tổng quát

**Chọn cặp hàng**  
Duyệt cặp hàng trên (`top`) và dưới (`bottom`) với `top = 0..m-1`, `bottom = top..m-1`.

Với mỗi cặp `(top, bottom)`, nén ma trận theo cột thành mảng 1 chiều `temp[]` có độ dài `n`:

```
temp[j] = ∑ a[i][j] với i từ top đến bottom
```

**Áp dụng Kadane trên mảng 1D**  
Dùng thuật toán Kadane trên `temp[]` để tìm đoạn con liên tiếp (các cột) có tổng lớn nhất. Đồng thời lưu tọa độ cột trái và phải.

**Cập nhật kết quả**  
Nếu tổng mới lớn hơn tổng lớn nhất hiện tại, cập nhật kết quả và lưu tọa độ:

- Hàng trên (`top`), hàng dưới (`bottom`)
- Cột trái (`left`), cột phải (`right`)

## Độ phức tạp

- Duyệt cặp hàng: `O(m²)`
- Mỗi cặp duyệt cột và chạy Kadane: `O(n)`
- Tổng: `O(m² · n)`

---

## Code: Kadane 2D

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)

int main() {
    fast;
    ll m, n;
    cin >> m >> n;
    ll a[101][101];
    for (ll i = 0; i < m; i++)
        for (ll j = 0; j < n; j++)
            cin >> a[i][j];

    ll maxSum = LLONG_MIN;
    ll finalTop = 0, finalBottom = 0, finalLeft = 0, finalRight = 0;

    for (ll top = 0; top < m; top++) {
        ll temp[101] = {0};
        for (ll bottom = top; bottom < m; bottom++) {
            for (ll j = 0; j < n; j++)
                temp[j] += a[bottom][j];

            ll sum = 0, localMax = LLONG_MIN;
            ll start = 0, localLeft = 0, localRight = 0;
            for (ll j = 0; j < n; j++) {
                if (sum <= 0) {
                    sum = temp[j];
                    start = j;
                } else {
                    sum += temp[j];
                }
                if (sum > localMax) {
                    localMax = sum;
                    localLeft = start;
                    localRight = j;
                }
            }

            if (localMax > maxSum) {
                maxSum = localMax;
                finalTop = top;
                finalBottom = bottom;
                finalLeft = localLeft;
                finalRight = localRight;
            }
        }
    }

    cout << maxSum << "\n";
    cout << finalTop << " " << finalLeft << " " << finalBottom << " " << finalRight << "\n";
    return 0;
}
```

---

## Giải thích chi tiết

- **Top & Bottom**: Duyệt từng cặp hàng.
- **Temp[]**: Dồn dữ liệu cột theo hàng `top` đến `bottom`.
- **Kadane**: Tìm tổng lớn nhất liên tiếp trong temp.
- **Kết quả**: Nếu tìm được tổng lớn hơn, cập nhật tọa độ hình chữ nhật.

---

# 2. Tổng Tiền Tố 2D (Prefix Sum 2D)

## Ý tưởng tổng quát

**Xây dựng mảng tổng tiền tố `ps`**  
Tạo mảng `ps[m+1][n+1]` sao cho:

```
ps[i+1][j+1] = a[i][j] + ps[i][j+1] + ps[i+1][j] - ps[i][j]
```

Tính tổng hình chữ nhật từ `(i1, j1)` đến `(i2, j2)`:

```
S = ps[i2+1][j2+1] - ps[i1][j2+1] - ps[i2+1][j1] + ps[i1][j1]
```

**Duyệt tất cả các hình chữ nhật con**  
Với mọi tổ hợp `(i1, j1)` và `(i2, j2)` sao cho `i1 ≤ i2`, `j1 ≤ j2`, áp dụng công thức trên để tính tổng và cập nhật kết quả nếu cần.

## Độ phức tạp

- Duyệt tất cả hình chữ nhật: `O(m² × n²)`
- Với `m, n ≤ 100`: khoảng 10⁸ phép tính

---

## Code: Prefix Sum 2D

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)

int main() {
    fast;
    ll m, n;
    cin >> m >> n;
    ll a[101][101];
    for (ll i = 0; i < m; i++)
        for (ll j = 0; j < n; j++)
            cin >> a[i][j];

    ll ps[102][102] = {0};
    for (ll i = 0; i < m; i++)
        for (ll j = 0; j < n; j++)
            ps[i+1][j+1] = a[i][j] + ps[i][j+1] + ps[i+1][j] - ps[i][j];

    ll maxSum = LLONG_MIN;
    ll finalTop = 0, finalLeft = 0, finalBottom = 0, finalRight = 0;

    for (ll i1 = 0; i1 < m; i1++)
        for (ll j1 = 0; j1 < n; j1++)
            for (ll i2 = i1; i2 < m; i2++)
                for (ll j2 = j1; j2 < n; j2++) {
                    ll sum = ps[i2+1][j2+1] - ps[i1][j2+1] - ps[i2+1][j1] + ps[i1][j1];
                    if (sum > maxSum) {
                        maxSum = sum;
                        finalTop = i1;
                        finalLeft = j1;
                        finalBottom = i2;
                        finalRight = j2;
                    }
                }

    cout << maxSum << "\n";
    cout << finalTop << " " << finalLeft << " " << finalBottom << " " << finalRight << "\n";
    return 0;
}
```

---

## Giải thích chi tiết

- **Prefix Sum**: `ps[i+1][j+1]` là tổng từ `(0,0)` đến `(i,j)`
- **Công thức tổng vùng**: Cho phép tính tổng O(1) cho mọi hình chữ nhật.
- **Duyệt 4 vòng**: Xét mọi hình chữ nhật con để cập nhật tổng lớn nhất.

---

## Kết luận So sánh

| Thuật toán     | Độ phức tạp       | Ưu điểm                          | Nhược điểm                       |
|----------------|--------------------|----------------------------------|----------------------------------|
| Kadane 2D      | O(m² · n)          | Nhanh hơn, hiệu quả với m lớn    | Phức tạp hơn một chút            |
| Prefix Sum 2D  | O(m² · n²)         | Dễ hiểu, tính tổng nhanh         | Chậm hơn nếu dữ liệu lớn         |

**→ Với `m, n ≤ 100`, cả hai đều dùng được. Tuy nhiên, Kadane 2D thường được ưu tiên hơn.**
