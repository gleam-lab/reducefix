#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define inf 1e18

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    set<int> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    int unsafe = 0;
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size();

    for (auto d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        int count = max_i - min_i + 1;
        unsafe += count;
    }

    for (auto d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        int count = max_i - min_i + 1;
        unsafe += count;
    }

    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            int i = (d1 + d2) / 2;
            int j = (d1 - d2) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                unsafe--;
            }
        }
    }

    for (auto r : rows) {
        for (auto d1 : diag1) {
            int j = d1 - r;
            if (j >= 1 && j <= N) {
                unsafe--;
            }
        }
        for (auto d2 : diag2) {
            int j = r - d2;
            if (j >= 1 && j <= N) {
                unsafe--;
            }
        }
    }

    for (auto c : cols) {
        for (auto d1 : diag1) {
            int i = d1 - c;
            if (i >= 1 && i <= N) {
                unsafe--;
            }
        }
        for (auto d2 : diag2) {
            int i = d2 + c;
            if (i >= 1 && i <= N) {
                unsafe--;
            }
        }
    }

    int total = N * N;
    int safe = total - unsafe;
    cout << safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    while (_--) {
        solve();
    }

    return 0;
}