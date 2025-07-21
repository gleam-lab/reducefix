#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll(i) = 0; (i) < (n); ++(i))

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    // dp_odd[i]: 最大経験値、i体目まで倒し、i体目を奇数回倒したとき
    // dp_even[i]: 最大経験値、i体目まで倒し、i体目を偶数回倒したとき
    vector<ll> dp_odd(n, 0), dp_even(n, 0);

    dp_odd[0] = a[0];
    dp_even[0] = 0;

    for (int i = 1; i < n; ++i) {
        // i体目を奇数回倒す場合: 前回は偶数回倒して、今回は1回倒す or 前前回から直接2回以上倒す（これは状態遷移で扱われる）
        dp_odd[i] = dp_even[i - 1] + a[i];

        // i体目を偶数回倒す場合: 前回は奇数回倒して、今回はもう1回倒す
        dp_even[i] = dp_odd[i - 1] + a[i];

        // 遷移が可能なら、前の同じ状態からの継続も考慮
        if (i >= 2) {
            dp_odd[i] = max(dp_odd[i], dp_odd[i - 2] + a[i]);
            dp_even[i] = max(dp_even[i], dp_even[i - 2] + a[i]);
        }
    }

    cout << max(dp_odd[n - 1], dp_even[n - 1]) << endl;

    return 0;
}