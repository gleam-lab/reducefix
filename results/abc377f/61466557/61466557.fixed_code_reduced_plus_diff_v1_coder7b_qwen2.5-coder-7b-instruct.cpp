#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    unordered_set<int> rows, cols, diags1, diags2;
    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diags1.insert(a - b);
        diags2.insert(a + b);
    }

    ll total_squares = (ll)n * n;
    ll occupied_squares = rows.size() + cols.size() + diags1.size() + diags2.size();

    // Remove intersections between rows, cols, and diags
    for(int a : rows) {
        for(int b : cols) {
            if(diags1.count(a - b) || diags2.count(a + b)) {
                --occupied_squares;
            }
        }
    }

    cout << total_squares - occupied_squares << '\n';

    return 0;
}