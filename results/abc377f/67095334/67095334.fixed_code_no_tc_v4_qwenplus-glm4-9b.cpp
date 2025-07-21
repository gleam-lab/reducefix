#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    set<pair<int, int>> lines; // To store lines that are affected by pieces
    
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        // Add all lines affected by piece at (a, b)
        lines.insert({a, b});
        lines.insert({b, a});
        lines.insert({a + b, b});
        lines.insert({a - b, b});
    }
    
    // Calculate the number of affected squares
    long long affectedSquares = 0;
    for (const auto& line : lines) {
        int start = min(line.first, line.second);
        int end = max(line.first, line.second);
        affectedSquares += (end - start + 1);
    }
    
    // Total squares minus affected squares gives the number of valid squares
    long long totalSquares = N * N;
    long long validSquares = totalSquares - affectedSquares;
    
    cout << validSquares << endl;
    
    return 0;
}