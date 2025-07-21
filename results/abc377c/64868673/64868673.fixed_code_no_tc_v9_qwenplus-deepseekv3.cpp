#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    set<pair<long long, long long>> forbidden;
    vector<int> dx = {2, 2, 1, 1, -1, -1, -2, -2};
    vector<int> dy = {1, -1, 2, -2, 2, -2, 1, -1};
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        forbidden.insert({a, b});
        for (int j = 0; j < 8; ++j) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                forbidden.insert({x, y});
            }
        }
    }
    
    cout << N * N - forbidden.size() << endl;
    return 0;
}