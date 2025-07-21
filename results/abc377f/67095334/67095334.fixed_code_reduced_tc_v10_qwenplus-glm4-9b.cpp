#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> rows(M);
    vector<int> cols(M);
    set<int> diag1, diag2;

    for (int i = 0; i < M; ++i) {
        cin >> rows[i] >> cols[i];
        diag1.insert(rows[i] + cols[i]);
        diag2.insert(rows[i] - cols[i]);
    }

    int ans = N * N - M;
    for (int d = 1; d <= N * 2; ++d) {
        int len1 = max(0, min(N, d - 1));
        int len2 = max(0, min(N, N * 2 - d));
        ans -= len1 - (diag1.count(d) ? 1 : 0) - len2 - (diag2.count(d) ? 1 : 0);
        if (d < min(N, N * 2 - d) && diag1.count(d) && diag2.count(d)) {
            ans -= 1; // Adjust for double counting
        }
    }

    cout << ans << endl;
    return 0;
}