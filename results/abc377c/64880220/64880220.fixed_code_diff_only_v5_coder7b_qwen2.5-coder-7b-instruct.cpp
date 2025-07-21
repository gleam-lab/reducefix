#include <bits/stdc++.h>
using namespace std;

int main() {
    map<pair<long long, long long>, int> ex;
    long long n, m;
    cin >> n >> m;
    long long ans = 0;
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

    // Store positions of all existing pieces
    for (int i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        pair<long long, long long> p;
        p = make_pair(a, b);
        if (!ex.count(p)) {
            ex[p] = 1;
            ans++;
        }
    }

    // Check each possible move from every existing piece
    for (auto& [pos, count] : ex) {
        for (int i = 0; i < 8; i++) {
            long long x, y;
            x = pos.first + dx[i];
            y = pos.second + dy[i];
            pair<long long, long long> p;
            p = make_pair(x, y);
            if (x > 0 && x <= n && y > 0 && y <= n) {
                if (!ex.count(p)) {
                    ex[p] = 1;
                    ans++;
                }
            }
        }
    }

    // Calculate the number of empty squares available
    cout << n * n - ans << endl;
}