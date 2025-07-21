#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Set to store all squares that cannot be occupied
    set<pair<long long, long long>> invalid_squares;
    
    // Process each piece
    for (int i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        --a; --b; // Convert to zero-based index
        
        // Mark squares that can be captured by the current piece
        if (a + 2 < n && b + 1 < n) {
            invalid_squares.insert({a + 2, b + 1});
        }
        if (a + 2 < n && b - 1 >= 0) {
            invalid_squares.insert({a + 2, b - 1});
        }
        if (a + 1 < n && b + 2 < n) {
            invalid_squares.insert({a + 1, b + 2});
        }
        if (a + 1 < n && b - 2 >= 0) {
            invalid_squares.insert({a + 1, b - 2});
        }
        if (a - 2 >= 0 && b + 1 < n) {
            invalid_squares.insert({a - 2, b + 1});
        }
        if (a - 2 >= 0 && b - 1 >= 0) {
            invalid_squares.insert({a - 2, b - 1});
        }
        if (a - 1 >= 0 && b + 2 < n) {
            invalid_squares.insert({a - 1, b + 2});
        }
        if (a - 1 >= 0 && b - 2 >= 0) {
            invalid_squares.insert({a - 1, b - 2});
        }
    }
    
    // Calculate the number of valid squares
    cout << n * n - invalid_squares.size() << endl;
    
    return 0;
}