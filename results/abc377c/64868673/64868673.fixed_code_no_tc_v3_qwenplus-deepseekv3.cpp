#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, m;
    cin >> n >> m;
    unordered_set<long long> forbidden;
    vector<pair<int, int>> pieces(m);
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        forbidden.insert((long long)a * (n + 1) + b); // Mark the piece's position as forbidden
    }
    
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};
    
    for (const auto& [a, b] : pieces) {
        for (int i = 0; i < 8; ++i) {
            long long x = a + dx[i];
            long long y = b + dy[i];
            if (x >= 1 && x <= n && y >= 1 && y <= n) {
                forbidden.insert(x * (n + 1) + y); // Mark the attackable position
            }
        }
    }
    
    long long total = n * n;
    long long forbidden_count = forbidden.size();
    cout << total - forbidden_count << endl;
    
    return 0;
}