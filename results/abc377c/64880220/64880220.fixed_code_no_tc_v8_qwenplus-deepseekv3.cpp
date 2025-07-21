#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N, M;
    cin >> N >> M;
    
    unordered_set<long long> attacked_or_occupied;
    vector<pair<long long, long long>> pieces(M);
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        attacked_or_occupied.insert((a - 1) * N + b); // Using a unique key for each square
    }
    
    int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
    
    for (auto &piece : pieces) {
        long long a = piece.first;
        long long b = piece.second;
        for (int i = 0; i < 8; ++i) {
            long long x = a + dx[i];
            long long y = b + dy[i];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked_or_occupied.insert((x - 1) * N + y);
            }
        }
    }
    
    cout << N * N - attacked_or_occupied.size() << endl;
    
    return 0;
}