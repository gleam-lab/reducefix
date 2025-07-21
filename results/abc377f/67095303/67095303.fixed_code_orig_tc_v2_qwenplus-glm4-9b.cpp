#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

long long n, m;
int pieces[1000][2];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i][0] >> pieces[i][1];
    }

    set<int> captured_rows, captured_cols, captured_diag1, captured_diag2;

    // æè·ææè¡åå
    for (int i = 0; i < m; ++i) {
        captured_rows.insert(pieces[i][0]);
        captured_cols.insert(pieces[i][1]);
    }

    // æè·å¯¹è§çº¿
    for (int i = 0; i < m; ++i) {
        captured_diag1.insert(pieces[i][0] + pieces[i][1]);
        captured_diag2.insert(abs(pieces[i][0] - pieces[i][1]));
    }

    long long total_cap = (captured_rows.size() + captured_cols.size()) * n;

    // åå»éå¤è®¡ç®çå¯¹è§çº¿
    for (int i = 0; i < m; ++i) {
        if (captured_diag1.count(pieces[i][0] + pieces[i][1]) && captured_diag2.count(abs(pieces[i][0] - pieces[i][1]))) {
            total_cap--;
        }
    }

    cout << (n * n - m - total_cap) << endl;

    return 0;
}