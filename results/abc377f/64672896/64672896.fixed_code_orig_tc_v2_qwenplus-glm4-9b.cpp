#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    set<long long> row, col, diag1, diag2;
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        row.insert(a);
        col.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Calculate blocked squares
    long long blocked = 0;
    blocked += row.size() * N;
    blocked += col.size() * N;
    blocked += diag1.size() * N;
    blocked += diag2.size() * N;

    // Calculate unblocked squares
    long long unblocked = N * N - blocked;
    cout << unblocked << "\n";

    return 0;
}