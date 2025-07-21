#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    i64 N, M; cin >> N >> M;
    vector<array<i64,2>> g(M);
    vector<i64> A, B, C, D;
    for (int i = 0; i < M; i++) {
        i64 a, b; cin >> a >> b;
        g[i] = {a, b};
        A.push_back(a + b);
        B.push_back(a - b);
        C.push_back(a);
        D.push_back(b);
    }
    sort(A.begin(), A.end()); A.erase(unique(A.begin(), A.end()), A.end());
    sort(B.begin(), B.end()); B.erase(unique(B.begin(), B.end()), B.end());
    sort(C.begin(), C.end()); C.erase(unique(C.begin(), C.end()), C.end());
    sort(D.begin(), D.end()); D.erase(unique(D.begin(), D.end()), D.end());

    i64 ans = 0;
    for (auto &x : A) ans += N;
    for (auto &y : B) ans += N;
    for (auto &x : C) ans += N;
    for (auto &y : D) ans += N;

    set<pair<i64, i64>> S;
    for (auto &[a, b] : g) S.insert({a + b, a - b});

    for (auto [sum, diff] : S) {
        if (sum <= N && sum > 0) ans--;
        if (diff <= N && diff > 0) ans--;
    }

    cout << N * N - ans << '\n';
    return 0;
}