#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 1001;

int n, m;
vector<int> rows[MAX_N], cols[MAX_N], diag1[MAX_N * 2], diag2[MAX_N * 2];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        rows[a].push_back(b);
        cols[b].push_back(a);
        diag1[a + b].push_back(a); // a+b diagonal
        diag2[a - b + n - 1].push_back(a); // a-b diagonal
    }

    for (int i = 0; i < n; i++) {
        // Sort the vectors to make counting easier
        sort(rows[i].begin(), rows[i].end());
        sort(cols[i].begin(), cols[i].end());
        sort(diag1[i].begin(), diag1[i].end());
        sort(diag2[i].begin(), diag2[i].end());
    }

    long long total = n * n;
    long long covered = 0;

    // Count covered positions
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        // Count covered by rows
        covered += rows[a].size() + cols[b].size();
        // Count covered by diagonals
        covered += upper_bound(diag1[a + b].begin(), diag1[a + b].end(), b) - diag1[a + b].begin();
        covered += upper_bound(diag2[a - b + n - 1].begin(), diag2[a - b + n - 1].end(), b) - diag2[a - b + n - 1].begin();
    }

    cout << total - covered << endl;
    return 0;
}