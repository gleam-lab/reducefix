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
        pair<long long, long long> p;
        p = make_pair(a, b);

        // Check if the current position is already occupied
        if (!ex.count(p)) {
            ex[p] = 1;
            ans++;
        }

        // Check all possible positions a piece can attack from the current position
        for (int i = 0; i < 8; i++) {
            long long x, y;
            x = a + dx[i];
            y = b + dy[i];

            // Ensure the new position is within bounds
            if (x > 0 && x <= n && y > 0 && y <= n) {
                pair<long long, long long> q;
                q = make_pair(x, y);
                if (!ex.count(q)) {
                    ex[q] = 1;
                    ans++;
                }
            }
        }
    }

    // Calculate the number of empty squares available for placing a piece
    cout << n * n - ans << endl;
}