#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    vector<long long> rows(MAXN + 1, 0);
    vector<long long> cols(MAXN + 1, 0);
    vector<long long> diags1(2 * MAXN + 1, 0);
    vector<long long> diags2(2 * MAXN + 1, 0);

    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        rows[a]++;
        cols[b]++;
        diags1[a + b]++;
        diags2[a - b + MAXN]++;
    }

    long long safe_positions = 0;

    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= n; ++j) {
            if (rows[i] == 0 && cols[j] == 0 && diags1[i + j] == 0 && diags2[i - j + MAXN] == 0) {
                safe_positions++;
            }
        }
    }

    cout << safe_positions << endl;

    return 0;
}