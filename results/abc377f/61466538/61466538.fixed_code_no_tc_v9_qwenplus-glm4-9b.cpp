#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> pieces(m);
    for (long long i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // Map to holds all occupied rows, columns, diagonal1 (i-j), and diagonal2 (i+j)
    vector<long long> occupied(2 * n + 2, 0); // 0 to 2n-1 for rows and columns, 2n for diagonal1, 2n+1 for diagonal2
    for (const auto& p : pieces) {
        occupied[p.first - 1]++;
        occupied[p.second - 1]++;
        occupied[p.first + p.second - 2]++;
        occupied[p.first - p.second + n - 1]++;
    }

    long long total_empty_squares = n * n;
    long long occupied_squares = 0;

    // Calculate total number of occupied squares
    for (long long i = 0; i < 2 * n + 2; ++i) {
        occupied_squares += occupied[i];
    }

    total_empty_squares -= occupied_squares;

    cout << total_empty_squares << endl;

    return 0;
}