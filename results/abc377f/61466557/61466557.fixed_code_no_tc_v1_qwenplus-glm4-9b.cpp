#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

ll n, m;
vector<pi> pieces;

bool inBounds(int a, int b) {
    return 1 <= a && a <= n && 1 <= b && b <= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    pieces.resize(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        pieces[i] = {x, y};
    }

    set<int> rows, cols, diag1, diag2;
    for (const auto& p : pieces) {
        rows.insert(p.first);
        cols.insert(p.second);
        diag1.insert(p.first - p.second);
        diag2.insert(p.first + p.second);
    }

    ll totalEmpty = n * n;
    totalEmpty -= rows.size() * n; // Subtract all squares in each row
    totalEmpty -= cols.size() * n; // Subtract all squares in each column
    totalEmpty += rows.size() * cols.size(); // Add squares that are not in any row or column

    set<pi> conflictPoints;
    for (int d : diag1) {
        int lower = max(1, 1 - d);
        int upper = min(n, n - d);
        for (int i = lower; i <= upper; ++i) {
            if (inBounds(i, abs(d - i))) {
                conflictPoints.insert({i, abs(d - i)});
            }
        }
    }

    for (int d : diag2) {
        int lower = max(1, min(d, n - d) - 1);
        int upper = min(n, min(n - d, d) + 1);
        for (int i = lower; i <= upper; ++i) {
            if (inBounds(i, d - i)) {
                conflictPoints.insert({i, d - i});
            }
        }
    }

    for (const auto& p : pieces) {
        if (conflictPoints.count(p)) {
            conflictPoints.erase(p);
        }
    }

    ll safeEmpty = n * n;
    safeEmpty -= rows.size() * n;
    safeEmpty -= cols.size() * n;
    safeEmpty += rows.size() * cols.size();
    safeEmpty -= conflictPoints.size();

    cout << safeEmpty << endl;

    return 0;
}