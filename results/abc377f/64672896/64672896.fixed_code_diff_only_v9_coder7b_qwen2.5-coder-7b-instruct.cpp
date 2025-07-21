#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    i64 N, M;
    cin >> N >> M;
    vector<array<int, 2>> pieces(M);
    set<pair<int, int>> occupied;
    
    for(int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        occupied.insert({a, b});
        occupied.insert({a + b, a - b});
        occupied.insert({a + b, a + b});
        occupied.insert({a - b, a + b});
    }
    
    i64 count = 0;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(!occupied.count({i, j}) && !occupied.count({i + j, i - j}) && !occupied.count({i + j, i + j}) && !occupied.count({i - j, i + j})) {
                count++;
            }
        }
    }
    
    cout << count << '\n';
    return 0;
}