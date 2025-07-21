#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    set<long long> h, v, d1, d2;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        h.insert(a);
        v.insert(b);
        d1.insert(a + b);
        d2.insert(a - b);
    }

    // Step 1: Count safe squares not in any dangerous row or column
    long long ans = (N - h.size()) * (N - v.size());

    // Step 2: Subtract intersections with d1 (i + j = k)
    for (long long diag : d1) {
        long long len;
        if (diag <= N + 1) {
            len = diag - 1;
        } else {
            len = 2 * N + 1 - diag;
        }
        set<long long> covered_rows;

        for (long long x : h) {
            long long y = diag - x;
            if (1 <= y && y <= N) {
                covered_rows.insert(x);
            }
        }

        for (long long y : v) {
            long long x = diag - y;
            if (1 <= x && x <= N) {
                covered_rows.insert(x);
            }
        }

        ans -= (len - covered_rows.size());
    }

    // Step 3: Subtract intersections with d2 (i - j = k)
    for (long long diag : d2) {
        long long len;
        if (diag >= 0) {
            len = N - diag;
        } else {
            len = N + diag;
        }

        set<long long> covered_rows;

        for (long long x : h) {
            long long y = x - diag;
            if (1 <= y && y <= N) {
                covered_rows.insert(x);
            }
        }

        for (long long y : v) {
            long long x = y + diag;
            if (1 <= x && x <= N) {
                covered_rows.insert(x);
            }
        }

        ans -= (len - covered_rows.size());
    }

    cout << ans << endl;

    return 0;
}