#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

class Counter {
public:
    set<int> rows, cols, diag1, diag2;
    int total, row_capture, col_capture, diag1_capture, diag2_capture;

    void add_row(int r) { rows.insert(r); }
    void add_col(int c) { cols.insert(c); }
    void add_diag1(int d) { diag1.insert(d); }
    void add_diag2(int d) { diag2.insert(d); }

    void count() {
        row_capture = rows.size();
        col_capture = cols.size();
        diag1_capture = diag1.size();
        diag2_capture = diag2.size();

        // Calculate the total number of captured squares
        total = row_capture * N + col_capture * N + diag1_capture + diag2_capture;

        // Subtract double-counted intersections
        for (int r : rows) {
            if (diag1.count(r)) total--;
            if (diag2.count(r)) total--;
        }
        for (int c : cols) {
            if (diag1.count(N + c)) total--;
            if (diag2.count(c)) total--;
        }
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    Counter counter;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        counter.add_row(a);
        counter.add_col(b);
        counter.add_diag1(a + b);
        counter.add_diag2(a - b);
    }

    counter.count();

    // Total squares minus captured squares
    int free_squares = (long long)N * N - counter.total;
    cout << free_squares << endl;

    return 0;
}