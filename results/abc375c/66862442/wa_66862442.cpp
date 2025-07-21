#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long curX = 0, curY = 0;
    __int128 total = 0;          // 128bit なら安全

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        long long dx = curX - x;
        long long dy = curY - y;
        total += (__int128)dx * dx + (__int128)dy * dy;

        curX = x; curY = y;
    }
    total += (__int128)curX * curX + (__int128)curY * curY; // 原点へ戻る

    // 文字列化して誤差ゼロで出力
    string s;
    if (total == 0) s = "0";
    else {
        while (total) { s.push_back('0' + total % 10); total /= 10; }
        reverse(s.begin(), s.end());
    }
    cout << s << '\n';
}
