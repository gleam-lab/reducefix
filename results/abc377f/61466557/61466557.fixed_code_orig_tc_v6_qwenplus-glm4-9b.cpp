#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    unordered_set<int> captured_rows, captured_cols, captured_d1, captured_d2;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--; // Convert to 0-based indexing
        captured_rows.insert(a);
        captured_cols.insert(b);
        captured_d1.insert(a + b);
        captured_d2.insert(a - b);
    }

    long long safe_count = N * N;

    // Subtract captured rows and columns
    for (int i = 0; i < N; i++) {
        if (captured_rows.count(i) || captured_cols.count(i)) {
            safe_count -= N;
        }
    }

    // Subtract captured diagonals
    safe_count -= captured_d1.size();
    safe_count -= captured_d2.size();

    cout << safe_count << endl;

    return 0;
}