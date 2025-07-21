#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    vector<pair<i64, i64>> pieces(M);
    unordered_set<i64> cols, diag1, diag2;
    
    for(i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    i64 count = 0;

    for(i64 i = 1; i <= N; ++i) {
        if(cols.find(i) != cols.end()) continue;

        bool diag1_captured = false, diag2_captured = false;
        for(auto& [ai, bi] : pieces) {
            if(ai + bi == i + i) diag1_captured = true;
            if(ai - bi == i - i) diag2_captured = true;
        }

        if(!diag1_captured && !diag2_captured) {
            ++count;
        }
    }

    cout << count << '\n';
    return 0;
}