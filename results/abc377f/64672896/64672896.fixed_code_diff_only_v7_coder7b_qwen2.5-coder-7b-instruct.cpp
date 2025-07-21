#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    i64 N, M;
    cin >> N >> M;
    
    vector<array<int, 2>> g(M);
    vector<i64> A, B, C, D;
    
    for(int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
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

    set<array<int, 2>> S;
    for(auto [a, b]: g) S.insert({a, b});

    i64 ans = 0;
    for(i64 i = 1; i <= N; ++i) {
        for(i64 j = 1; j <= N; ++j) {
            bool can_place = true;
            
            // Check row and column
            if(S.count({i, j})) continue;
            
            // Check diagonal sums
            if(S.count({i + j, j})) continue;
            if(S.count({i - j, j})) continue;
            
            // Check diagonal differences
            if(S.count({i, j + i - j})) continue;
            if(S.count({i, j + j - i})) continue;
            
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}