#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> positions(M);
    for (long long i = 0; i < M; ++i) {
        cin >> positions[i].first >> positions[i].second;
    }
    
    // Using bit sets to track attacked rows, columns, and diagonals
    bitset<1000000> row_attacked, col_attacked;
    bitset<2000000> diag_attacked1, diag_attacked2;
    
    for (auto& p : positions) {
        row_attacked.set(p.first - 1);  // 0-based index
        col_attacked.set(p.second - 1); // 0-based index
        diag_attacked1.set(p.first - 1 + p.second - 1); // (i-j) = (p.first-p.second)
        diag_attacked2.set(p.first - 1 - p.second + N); // (i+j) = (p.first+p.second)
    }
    
    long long total_squares = N * N;
    long long attacked_squares = (row_attacked.count() * N) + 
                                  (col_attacked.count() * N) + 
                                  (diag_attacked1.count() / 2 * N) + // Each diagonal entry counted twice
                                  (diag_attacked2.count() / 2 * N);    // Each diagonal entry counted twice
    
    cout << total_squares - attacked_squares << endl;
    
    return 0;
}