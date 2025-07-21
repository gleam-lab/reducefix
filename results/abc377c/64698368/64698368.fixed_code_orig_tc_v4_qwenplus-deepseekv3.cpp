#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    set<pair<long long, long long>> attacked;
    vector<pair<long long, long long>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        
        for (auto dir : directions) {
            long long new_a = a + dir.first;
            long long new_b = b + dir.second;
            
            if (new_a >= 1 && new_a <= N && new_b >= 1 && new_b <= N) {
                attacked.insert({new_a, new_b});
            }
        }
    }
    
    long long total = N * N;
    long long unsafe = attacked.size() + M; // attacked squares plus existing pieces
    long long safe = total - unsafe;
    
    cout << safe << endl;
    
    return 0;
}