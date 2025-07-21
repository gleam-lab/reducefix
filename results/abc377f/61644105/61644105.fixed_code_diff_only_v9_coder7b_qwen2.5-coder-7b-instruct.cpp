#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<long long> rows, cols, diags1, diags2;

    for (long long i = 0; i < M; ++i) {
        long long x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diags1.insert(x + y);
        diags2.insert(x - y);
    }

    long long valid_positions = 0;

    for (long long i = 1; i <= N; ++i) {
        for (long long j = 1; j <= N; ++j) {
            if (rows.find(i) == rows.end() && 
                cols.find(j) == cols.end() && 
                diags1.find(i + j) == diags1.end() && 
                diags2.find(i - j) == diags2.end()) {
                ++valid_positions;
            }
        }
    }

    cout << valid_positions << endl;

    return 0;
}