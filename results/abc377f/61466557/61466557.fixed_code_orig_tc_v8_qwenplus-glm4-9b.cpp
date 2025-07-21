#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    unordered_set<int> rows, cols, main_diags, secondary_diags;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        main_diags.insert(a - b);
        secondary_diags.insert(a + b);
    }

    long long captured_rows = rows.size();
    long long captured_cols = cols.size();
    long long captured_main_diags = main_diags.size();
    long long captured_secondary_diags = secondary_diags.size();

    long long safe_squares = N * N - captured_rows * N - captured_cols * N + captured_rows * captured_cols;

    cout << safe_squares << endl;

    return 0;
}