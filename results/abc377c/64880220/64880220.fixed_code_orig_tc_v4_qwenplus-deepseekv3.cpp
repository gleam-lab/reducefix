#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    unordered_set<long long> occupied;
    unordered_set<long long> threatened;
    
    vector<int> dx = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert((a - 1) * N + (b - 1)); // Using 0-based or 1-based indexing
        
        for (int k = 0; k < 8; ++k) {
            long long x = a + dx[k];
            long long y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                threatened.insert((x - 1) * N + (y - 1));
            }
        }
    }
    
    long long total = N * N;
    long long occupied_or_threatened = occupied.size();
    for (long long pos : threatened) {
        if (occupied.find(pos) == occupied.end()) {
            occupied_or_threatened++;
        }
    }
    
    cout << total - occupied_or_threatened << endl;
    
    return 0;
}