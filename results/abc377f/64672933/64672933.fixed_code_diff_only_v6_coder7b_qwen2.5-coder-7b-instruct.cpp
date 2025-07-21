#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<array<i64,2>> g(M);
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
    
    i64 ans = N * N - M;
    set<pair<i64, i64>> placed;
    for(auto& [a, b] : g) placed.emplace(a, b);

    for(auto a : A){
        if(!placed.count({a, 1})) ans++;
        if(!placed.count({a, N})) ans++;
    }

    for(auto b : B){
        if(!placed.count({1, b})) ans++;
        if(!placed.count({N, b})) ans++;
    }

    for(i64 i = 1; i <= N; i++){
        for(i64 j = 1; j <= N; j++){
            bool valid = true;
            for(auto a : A){
                if(abs(a - (i + j)) == 0 && !placed.count({i, j})) continue;
                if(abs(a - (i + j)) != 0 && !placed.count({i, j})) valid = false;
            }
            for(auto b : B){
                if(abs(b - (i - j)) == 0 && !placed.count({i, j})) continue;
                if(abs(b - (i - j)) != 0 && !placed.count({i, j})) valid = false;
            }
            if(valid) ans--;
        }
    }

    cout << ans << '\n';
    return 0;
}