#include<bits/stdc++.h>
using namespace std;

// Hàm kiểm tra số thuận nghịch
bool isPalindromic(int n) {
    string s = to_string(n);
    string reversed_s = s;
    reverse(reversed_s.begin(), reversed_s.end());
    return s == reversed_s;
}

// Hàm đếm số lượng ước số nguyên tố khác nhau
int primeFactorsCount(int n) {
    set<int> primeFactors; // Sử dụng tập hợp để lưu các ước số nguyên tố duy nhất
    int factor = 2;
    
    while (factor * factor <= n) {
        while (n % factor == 0) {
            primeFactors.insert(factor);
            n /= factor;
        }
        factor++;
    }
    if (n > 1) { // Nếu còn lại n > 1, n là số nguyên tố
        primeFactors.insert(n);
    }
    return primeFactors.size();
}

// Hàm tìm và in các số đẹp trong đoạn [a, b]
void findBeautifulNumbers(int a, int b) {
    cout << "Cac so dep trong doan [" << a << ", " << b << "] la:\n";
    for (int num = a; num <= b; num++) {
        if (isPalindromic(num) && primeFactorsCount(num) >= 3) {
            cout << num << " ";
        }
    }
    cout << endl;
}

int main() {
    int a, b;
    cout << "Nhap so nguyen a: ";
    cin >> a;
    cout << "Nhap so nguyen b: ";
    cin >> b;

    findBeautifulNumbers(a, b);

    return 0;
}
