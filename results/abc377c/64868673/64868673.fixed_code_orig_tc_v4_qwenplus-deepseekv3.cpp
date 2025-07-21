#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;
    
    unordered_set<long long> occupied;
    unordered_set<long long> attackable;
    
    vector<int> dx = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        long long pos = (a - 1) * N + (b - 1);
        occupied.insert(pos);
        
        for (int k = 0; k < 8; ++k) {
            long long x = a + dx[k];
            long long y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                long long new_pos = (x - 1) * N + (y - 1);
                if (occupied.find(new_pos) == occupied.end()) {
                    attackable.insert(new_pos);
                }
            }
        }
    }
    
    long long total_occupied_or_attackable = occupied.size() + attackable.size();
    long long safe_squares = N * N - total_occupied_or_attackable;
    
    cout << safe_squares << endl;
    
    return 0;
}