#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Position {
    long long x, y;
};

int main() {
    long long n, m;
    cin >> n >> m;
    vector<Position> pieces(m);
    
    for (long long i = 0; i < m; ++i) {
        cin >> pieces[i].x >> pieces[i].y;
    }
    
    // Sort the pieces based on their x and then y coordinates
    sort(pieces.begin(), pieces.end(), [](const Position& a, const Position& b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });
    
    // We will use a sweep line algorithm to find the maximum x-coordinate
    // where we can place a new piece without being captured.
    long long left = 1, right = n;
    while (left < right) {
        long long mid = left + (right - left) / 2;
        long long count = 0;
        
        // Count how many pieces can capture the middle row
        for (const Position& p : pieces) {
            if (p.x == mid) {
                count++;
            }
        }
        
        // If the number of pieces is less than or equal to half the number of columns,
        // it is possible to place a piece in the middle row without being captured.
        if (count <= mid / 2) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    // All columns to the left of the found column can be placed without being captured
    long long free_columns = left;
    
    // Output the number of available positions
    cout << (n * n) - m - free_columns << endl;
    
    return 0;
}