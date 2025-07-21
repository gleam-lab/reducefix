#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    i64 K;
    cin >> N >> M >> K;
    
    vector<i64> A(N);
    for (auto &a : A) {
        cin >> a;
    }
    
    if (N == M) {
        for (int i = 0; i < N; ++i) {
            cout << 0 << " ";
        }
        cout << "\n";
        return 0;
    }
    
    vector<i64> B = A;
    sort(B.begin(), B.end());
    vector<i64> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + B[i];
    }
    
    auto check = [&](i64 x, i64 d) -> bool {
        i64 total = x + d;
        int pos = upper_bound(B.begin(), B.end(), total) - B.begin();
        int cnt = N - pos;
        if (cnt >= M) {
            return false;
        }
        int needed = M - cnt;
        if (needed <= 0) {
            return true;
        }
        i64 sum = prefix[pos] - prefix[pos - needed];
        return (total + 1) * needed - sum <= K - d;
    };
    
    for (int i = 0; i < N; ++i) {
        i64 l = 0, r = K, ans = -1;
        while (l <= r) {
            i64 mid = (l + r) / 2;
            if (check(A[i], mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << " ";
    }
    cout << "\n";
    
    return 0;
}