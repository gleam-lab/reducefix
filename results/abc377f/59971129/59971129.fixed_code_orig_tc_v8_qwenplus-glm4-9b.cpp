#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    set<int> rows, cols, diag1, diag2;

    for (long long i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(abs(a - b));
    }

    map<int, int> row_count, col_count, diag1_count, diag2_count;

    for (int i = 1; i <= n; ++i) {
        row_count[i] = rows.count(i) ? rows.count(i) : 0;
        col_count[i] = cols.count(i) ? cols.count(i) : 0;
        diag1_count[i] = diag1.count(i) ? diag1.count(i) : 0;
        diag2_count[i] = diag2.count(i) ? diag2.count(i) : 0;
    }

    long long total_attacked = 0;
    for (auto& p : row_count) total_attacked += p.second;
    for (auto& p : col_count) total_attacked += p.second;
    for (auto& p : diag1_count) total_attacked += p.second;
    for (auto& p : diag2_count) total_attacked += p.second;

    long long total_squares = n * n;
    cout << (total_squares - total_attacked) << endl;

    return 0;
}