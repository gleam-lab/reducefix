#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pii> positions(m);
    vector<unordered_set<int>> row capturedByRow(n + 1), col capturedByCol(n + 1);
    vector<unordered_set<int>> d1 capturedByD1(2 * n + 1), d2 capturedByD2(2 * n + 1);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        positions[i] = {x, y};
        capturedByRow[x].insert(y);
        capturedByCol[y].insert(x);
        d1[x - y + n].insert(i);
        d2[x + y].insert(i);
    }

    ll emptySquares = n * n;
    for (int r = 1; r <= n; ++r) {
        emptySquares -= capturedByRow[r].size();
    }
    for (int c = 1; c <= n; ++c) {
        emptySquares -= capturedByCol[c].size();
    }
    for (int d = -n + 1; d <= n - 1; ++d) {
        emptySquares -= capturedByD1[d + n].size();
    }
    for (int d = 1; d <= 2 * n; ++d) {
        emptySquares -= capturedByD2[d].size();
    }

    cout << emptySquares;
    return 0;
}