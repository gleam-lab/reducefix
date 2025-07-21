#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N ((int) 1e9)

int main() {
    long long n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b; // Convert to 0-based index
        pieces[i] = {a, b};
    }
    
    sort(pieces.begin(), pieces.end());
    
    long long total_empty = n * n;
    long long invalid = 0;
    
    // Check for all rows
    invalid += 2; // Exclude the first and last row
    for (int i = 0; i < m; ++i) {
        invalid += pieces[i].first == 0; // Captures row 1
        invalid += pieces[i].first == n - 1; // Captures row n
    }
    
    // Check for all columns
    invalid += 2; // Exclude the first and last column
    for (int i = 0; i < m; ++i) {
        invalid += pieces[i].second == 0; // Captures column 1
        invalid += pieces[i].second == n - 1; // Captures column n
    }
    
    // Check for diagonals and anti-diagonals
    for (int i = 0; i < m; ++i) {
        int x = pieces[i].first;
        int y = pieces[i].second;
        invalid += (x + y == n - 1) || (x - y == n - 1); // Captures diagonal or anti-diagonal
    }
    
    cout << (total_empty - invalid) << endl;
    return 0;
}