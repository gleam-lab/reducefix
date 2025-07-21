#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

int main() {
    long long n, m;
    cin >> n >> m;

    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }

    set<int> rows, cols, diag1, diag2;

    for (auto& p : pieces) {
        rows.insert(p.first);
        cols.insert(p.second);
        diag1.insert(p.first - p.second);
        diag2.insert(p.first + p.second);
    }

    set<int> captured;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (rows.count(i) || cols.count(j) || diag1.count(i - j) || diag2.count(i + j)) {
                captured.insert(i * n + j);
            }
        }
    }

    cout << (n * n - captured.size()) << endl;

    return 0;
}