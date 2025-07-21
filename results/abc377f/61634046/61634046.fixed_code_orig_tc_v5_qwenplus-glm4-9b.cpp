#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> points;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        points.emplace_back(a, b);
    }
    
    // Calculate the total number of squares minus the number of squares occupied by pieces
    long long total_squares = N * N - M;
    
    // For each piece, calculate the number of squares it can capture
    for (const auto& p : points) {
        int a = p.first;
        int b = p.second;
        
        // Count the number of squares it can capture on the same row
        int count_row = N - max(0, min(a - 1, b));
        int count_col = N - max(0, min(b - 1, a));
        int count_d1 = N - max(0, min(a - b - 1, N - 2));
        int count_d2 = N - max(0, min(a + b - 2, N - 1));
        
        // Subtract the number of capture points from the total
        total_squares -= (count_row + count_col + count_d1 + count_d2);
    }
    
    // Output the number of safe squares
    cout << total_squares << endl;
    
    return 0;
}