#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    i64 N, M;
    cin >> N >> M;
    
    vector<array<int,2>> pieces(M);
    set<pair<int,int>> occupied;
    
    for(int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        occupied.insert({a, b});
    }
    
    unordered_set<int> rows, cols, diagonals1, diagonals2;
    
    for(auto [a, b] : pieces) {
        rows.insert(a);
        cols.insert(b);
        diagonals1.insert(a + b);
        diagonals2.insert(a - b);
    }
    
    i64 count = 0;
    
    for(i64 i = 1; i <= N; ++i) {
        for(i64 j = 1; j <= N; ++j) {
            if(!rows.count(i) && !cols.count(j) && !diagonals1.count(i + j) && !diagonals2.count(i - j)) {
                count++;
            }
        }
    }
    
    cout << count << '\n';
    
    return 0;
}