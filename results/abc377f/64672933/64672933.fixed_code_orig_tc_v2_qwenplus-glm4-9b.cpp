#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    vector<pair<long long, long long>> pieces(M);
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }
    
    // Using sets to store unique rows, columns, and diagonals
    set<long long> rows, cols, diag1, diag2;
    
    for (auto& p : pieces) {
        rows.insert(p.first);
        cols.insert(p.second);
        diag1.insert(p.first + p.second);
        diag2.insert(p.first - p.second);
    }
    
    // Calculate the number of empty squares that can be placed
    long long total_empty = N * N;
    
    // Subtract squares in occupied rows and columns
    for (auto& r : rows) {
        total_empty -= N;
    }
    for (auto& c : cols) {
        total_empty -= N;
    }
    
    // Subtract squares in occupied diagonals
    for (auto& d : diag1) {
        if (d >= 2 && d <= 2 * N) {
            total_empty -= (d - 1);
        }
    }
    for (auto& d : diag2) {
        if (d >= 2 && d <= 2 * N) {
            total_empty -= (d - 1);
        }
    }
    
    cout << total_empty << endl;
    
    return 0;
}