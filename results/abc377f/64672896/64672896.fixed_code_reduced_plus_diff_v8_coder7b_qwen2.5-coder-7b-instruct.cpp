#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<array<int, 2>> g(M);
    set<array<int, 2>> S;
    unordered_set<int> r, c, d1, d2;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        g[i] = {a, b};
        S.insert({a, b});
        r.insert(a);
        c.insert(b);
        d1.insert(a + b);
        d2.insert(a - b);
    }
    i64 ans = 0;
    for(i64 i = 1; i <= N; i++) {
        if(!r.count(i)) ans++;
        if(!c.count(i)) ans++;
        if(!d1.count(i)) ans++;
        if(!d2.count(i)) ans++;
    }
    cout << ans << '\n';
    return 0;
}