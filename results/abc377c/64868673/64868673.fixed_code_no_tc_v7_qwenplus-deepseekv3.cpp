#include <bits/stdc++.h>
using namespace std;

int main() {
    set<pair<long long, long long>> invalid;
    long long N, M;
    cin >> N >> M;
    
    vector<int> dx = {2, 2, -2, -2, 1, 1, -1, -1};
    vector<int> dy = {1, -1, 1, -1, 2, -2, 2, -2};
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        invalid.insert({a, b});
        
        for (int j = 0; j < 8; ++j) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                invalid.insert({x, y});
            }
        }
    }
    
    cout << N * N - invalid.size() << endl;
    return 0;
}