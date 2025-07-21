#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int MAXN = 1e9 + 5;
int n, m;
vector<pair<int, int>> pieces;

unordered_set<int> attacked_rows, attacked_cols;
unordered_set<int> attacked_diag1, attacked_diag2; // i+j and i-j

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        pieces.emplace_back(a, b);
        attacked_rows.insert(a);
        attacked_cols.insert(b);
        attacked_diag1.insert(a + b);
        attacked_diag2.insert(a - b);
    }

    // ...
}