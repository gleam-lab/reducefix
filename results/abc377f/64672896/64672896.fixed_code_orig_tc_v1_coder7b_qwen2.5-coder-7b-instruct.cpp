#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    vector<array<int,2>> g(M);
    vector<i64> A, B, C, D;
    for (int i = 0; i < M; i++) {
        i64 a, b;
        cin >> a >> b;
        g[i] = {a, b};
        A.push_back(a + b);
        B.push_back(a - b);
        C.push_back(a);
        D.push_back(b);
    }

    sort(begin(A), end(A));
    A.erase(unique(begin(A), end(A)), end(A));
    sort(begin(B), end(B));
    B.erase(unique(begin(B), end(B)), end(B));
    sort(begin(C), end(C));
    C.erase(unique(begin(C), end(C)), end(C));
    sort(begin(D), end(D));
    D.erase(unique(begin(D), end(D)), end(D));

    auto count_in_line = [&](vector<int>& lines, int val) {
        int L = upper_bound(begin(lines), end(lines), val) - begin(lines);
        int R = lower_bound(begin(lines), end(lines), val) - begin(lines);
        return L - R;
    };

    set<array<int, 2>> occupied;
    for (auto [a, b] : g) {
        occupied.insert({a, b});
    }

    i64 res = 0;
    for (i64 i = 1; i <= N; ++i) {
        for (i64 j = 1; j <= N; ++j) {
            if (occupied.count({i, j})) continue;

            bool valid = true;
            for (auto& a : A) {
                if (i + j == a) {
                    valid = false;
                    break;
                }
            }
            for (auto& b : B) {
                if (i - j == b) {
                    valid = false;
                    break;
                }
            }
            for (auto& c : C) {
                if (i == c) {
                    valid = false;
                    break;
                }
            }
            for (auto& d : D) {
                if (j == d) {
                    valid = false;
                    break;
                }
            }

            if (valid) ++res;
        }
    }

    cout << res << '\n';

    return 0;
}