#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<long long> attacked;
    long long n, m;
    cin >> n >> m;
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};
    
    for (int i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        attacked.insert((a - 1) * n + b - 1); // Mark the piece's position
        for (int j = 0; j < 8; ++j) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x >= 1 && x <= n && y >= 1 && y <= n) {
                attacked.insert((x - 1) * n + y - 1); // Mark attacked positions
            }
        }
    }
    cout << n * n - attacked.size() << endl;
    return 0;
}