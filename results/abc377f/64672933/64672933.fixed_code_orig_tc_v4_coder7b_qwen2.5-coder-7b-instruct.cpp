#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    i64 N, M; cin >> N >> M;
    vector<pair<i64, i64>> g(M);
    unordered_set<i64> lines_a, lines_b, lines_c, lines_d;
    for(i64 i = 0; i < M; ++i){
        i64 a, b; cin >> a >> b;
        g[i] = {a, b};
        lines_a.insert(a + b);
        lines_b.insert(a - b);
        lines_c.insert(a);
        lines_d.insert(b);
    }
    
    i64 ans = 0;
    for(auto &a : lines_a){
        i64 L = max(1LL, a - N + 1), R = min(a, N);
        ans -= R - L + 1;
    }

    for(auto &b : lines_b){
        i64 L = max(1LL, b - N + 1), R = min(b, N);
        ans -= R - L + 1;
    }

    for(auto &a : lines_c){
        ans -= N;
    }

    for(auto &b : lines_d){
        ans -= N;
    }

    for(auto [a, b] : g){
        if(!lines_c.count(a) && !lines_d.count(b)){
            if(lines_a.count(a + b) || lines_b.count(a - b)){
                ans++;
            }
        }
    }

    cout << N * N + ans << '\n';

    return 0;
}