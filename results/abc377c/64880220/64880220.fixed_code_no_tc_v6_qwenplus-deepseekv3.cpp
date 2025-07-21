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
        unsafe.insert((a - 1) * N + b); // Encode (a, b) as a single number for efficiency
    }
    
    int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
    
    for (auto [a, b] : pieces) {
        for (int k = 0; k < 8; ++k) {
            long long x = a + dx[k];
            long long y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                unsafe.insert((x - 1) * N + y);
            }
        }
    }
    
    cout << N * N - unsafe.size() << endl;
    
    return 0;
}