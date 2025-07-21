#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

using i64 = long long;

int main() {
    i64 N, M;
    cin >> N >> M;
    vector<i64> rows(M), cols(M);
    
    for (i64 i = 0; i < M; ++i) {
        cin >> rows[i] >> cols[i];
    }
    
    // Sort rows and columns to facilitate range queries
    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());
    
    // Use a hash set for fast lookup
    unordered_set<i64> used_positions;
    for (i64 i = 0; i < M; ++i) {
        used_positions.insert(rows[i] * N + cols[i]);
    }
    
    // Calculate the number of safe positions
    i64 safe_positions = 0;
    for (i64 i = 1; i <= N; ++i) {
        // Check rows
        for (i64 j = 1; j <= N; ++j) {
            i64 pos = i * N + j;
            if (used_positions.find(pos) == used_positions.end() &&
                !used_positions.count(i * N + j - i) &&
                !used_positions.count(i + j - 1) &&
                !used_positions.count(2 * i - j + 1)) {
                safe_positions++;
            }
        }
    }
    
    cout << safe_positions << endl;
    
    return 0;
}