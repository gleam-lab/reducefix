#include <bits/stdc++.h>
using namespace std;

int main() {
    map<pair<long long, long long>, int> ex;
    long long n, m;
    cin >> n >> m;
    long long ans = 0;
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

    for (int i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        pair<int, int> p;
        p = make_pair(a, b);
        if (!ex.count(p)) {
            ex[p] = 1;
            ans++;
        }
        for (int i = 0; i < 8; i++) {
            long long x, y;
            x = a + dx[i];
            y = b + dy[i];
            p = make_pair(x, y);
            if (x > 0 && x <= n && y > 0 && y <= n) {
                if (!ex.count(p)) {
                    ex[p] = 1;
                    ans++;
                }
            }
        }
    }

    // Calculate the total number of valid positions
    long long total_positions = n * n;
    // Subtract the number of invalid positions (positions that would be captured)
    ans = total_positions - ans;

    // Since we have already counted each invalid position once, we need to divide by 2
    ans /= 2;

    cout << ans << endl;
    return 0;
}