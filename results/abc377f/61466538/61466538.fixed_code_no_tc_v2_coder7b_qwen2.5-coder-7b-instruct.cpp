#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000000;

bool row[MAXN], col[MAXN], diag1[2 * MAXN], diag2[2 * MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));
    memset(diag1, false, sizeof(diag1));
    memset(diag2, false, sizeof(diag2));

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        row[a-1] = true;
        col[b-1] = true;
        diag1[a-1 + b-1] = true;
        diag2[a-1 - (b-1) + MAXN] = true;
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!row[i] && !col[j] && !diag1[i + j] && !diag2[i - j + MAXN]) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}