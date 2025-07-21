#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long curX = 0, curY = 0;   // 現在位置（原点）
    __int128 total = 0;             // 総コスト (128bit)

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        long long dx = curX - x;
        long long dy = curY - y;
        total += (__int128)dx * dx + (__int128)dy * dy;  // √なし！

        curX = x; curY = y;
    }

    // 最後の点から原点へ戻る
    total += (__int128)curX * curX + (__int128)curY * curY;

    /* --- 出力 ---
       整数のまま文字列化して出力すれば誤差 0。 */
    string s;
    if (total == 0) s = "0";
    else {
        while (total) {
            s.push_back('0' + total % 10);
            total /= 10;
        }
        reverse(s.begin(), s.end());
    }
    cout << s << '\n';
    return 0;
}
