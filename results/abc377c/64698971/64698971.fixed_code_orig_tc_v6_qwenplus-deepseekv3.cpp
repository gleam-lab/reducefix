#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    set<pair<long long, long long>> attacked;
    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        a--; b--; // Convert to 0-based index
        
        for (const auto& dir : directions) {
            long long new_a = a + dir.first;
            long long new_b = b + dir.second;
            
            if (new_a >= 0 && new_a < N && new_b >= 0 && new_b < N) {
                attacked.insert({new_a, new_b});
            }
        }
    }
    
    long long total = N * N;
    long long safe = total - (long long)attacked.size() - M;
    cout << safe << endl;
    
    return 0;
}