#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N, M;
    cin >> N >> M;
    
    unordered_set<long long> threatened;
    vector<pair<long long, long long>> pieces(M);
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }
    
    // Directions: 8 possible moves
    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
    
    for (auto &p : pieces) {
        long long a = p.first;
        long long b = p.second;
        for (int k = 0; k < 8; ++k) {
            long long x = a + dx[k];
            long long y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                threatened.insert(x * N + y);
            }
        }
    }
    
    // Also mark the existing pieces as threatened (since they are occupied)
    for (auto &p : pieces) {
        threatened.insert(p.first * N + p.second);
    }
    
    cout << N * N - threatened.size() << endl;
    
    return 0;
}