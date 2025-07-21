#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i <= (n); ++i)
#define all(c) begin(c), end(c)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    
    set<int> rows, cols, diag1, diag2;

    rep(i, M) {
        int a, b;
        cin >> a >> b;
        --a; --b; // Convert to zero-indexed

        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    int ans = N * N - rows.size() - cols.size() - diag1.size() - diag2.size();

    // Counting intersections (since they were counted twice)
    rep1(i, N) {
        rep1(j, N) {
            if (rows.count(i - 1) && cols.count(j - 1) &&
                diag1.count((i - 1) + (j - 1)) && diag2.count((i - 1) - (j - 1))) {
                ++ans;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}