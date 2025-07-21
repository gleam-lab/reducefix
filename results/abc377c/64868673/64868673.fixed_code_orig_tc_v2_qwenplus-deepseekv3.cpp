#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    set<pair<long long, long long>> attacked;
    set<pair<long long, long long>> pieces;
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        attacked.insert({a, b});
    }
    
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    for (auto p : pieces) {
        long long a = p.first;
        long long b = p.second;
        for (int i = 0; i < 8; ++i) {
            long long x = a + dx[i];
            long long y = b + dy[i];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.insert({x, y});
            }
        }
    }
    
    cout << N * N - attacked.size() << endl;
}