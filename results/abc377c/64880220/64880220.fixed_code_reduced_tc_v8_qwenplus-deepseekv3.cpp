#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N, M;
    cin >> N >> M;
    
    unordered_set<long long> unsafe;
    vector<pair<long long, long long>> pieces(M);
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        unsafe.insert((a - 1) * N + b); // Using a unique identifier for each coordinate
    }
    
    vector<int> dx = {2, 2, -2, -2, 1, 1, -1, -1};
    vector<int> dy = {1, -1, 1, -1, 2, -2, 2, -2};
    
    for (auto &piece : pieces) {
        long long a = piece.first;
        long long b = piece.second;
        for (int k = 0; k < 8; ++k) {
            long long x = a + dx[k];
            long long y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                unsafe.insert((x - 1) * N + y);
            }
        }
    }
    
    long long safe = N * N - unsafe.size();
    cout << safe << endl;
    
    return 0;
}