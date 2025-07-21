#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<long long> dangerous;
    long long N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
    
    for (const auto &p : pieces) {
        int a = p.first, b = p.second;
        dangerous.insert((long long)(a-1) * N + (b-1)); // Using 0-based or 1-based indexing carefully
        
        for (int i = 0; i < 8; ++i) {
            long long x = a + dx[i];
            long long y = b + dy[i];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                dangerous.insert((long long)(x-1) * N + (y-1));
            }
        }
    }
    
    cout << N * N - dangerous.size() << endl;
    
    return 0;
}