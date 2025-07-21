#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    set<pair<long long, long long>> unsafe;
    vector<pair<long long, long long>> pieces(M);
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        unsafe.insert({a, b});
    }
    
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    for (auto &p : pieces) {
        long long x = p.first;
        long long y = p.second;
        for (int k = 0; k < 8; ++k) {
            long long nx = x + dx[k];
            long long ny = y + dy[k];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                unsafe.insert({nx, ny});
            }
        }
    }
    
    long long unsafe_count = unsafe.size();
    long long total = N * N;
    long long safe = total - unsafe_count;
    
    cout << safe << endl;
    
    return 0;
}