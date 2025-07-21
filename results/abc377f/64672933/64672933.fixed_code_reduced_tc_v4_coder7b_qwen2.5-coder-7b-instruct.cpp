#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<array<i64, 2>> g(M);
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
    sort(begin(A), end(A)); A.erase(unique(begin(A), end(A)), end(A));
    sort(begin(B), end(B)); B.erase(unique(begin(B), end(B)), end(B));
    sort(begin(C), end(C)); C.erase(unique(begin(C), end(C)), end(C));
    sort(begin(D), end(D)); D.erase(unique(begin(D), end(D)), end(D));

    set<i64> occupied_x, occupied_y, occupied_d1, occupied_d2;

    for (auto [a, b] : g) {
        occupied_x.insert(a);
        occupied_y.insert(b);
        occupied_d1.insert(a + b);
        occupied_d2.insert(a - b);
    }

    i64 ans = 0;

    for (i64 x = 1; x <= N; x++) {
        if (!occupied_x.count(x)) {
            ans++;
        }
    }

    for (i64 y = 1; y <= N; y++) {
        if (!occupied_y.count(y)) {
            ans++;
        }
    }

    for (i64 d1 = 2; d1 <= 2 * N; d1++) {
        if (!occupied_d1.count(d1)) {
            ans++;
        }
    }

    for (i64 d2 = -N + 2; d2 <= N - 2; d2++) {
        if (!occupied_d2.count(d2)) {
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}