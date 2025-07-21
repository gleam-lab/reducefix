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

    // Sort pieces based on their positions
    sort(pieces.begin(), pieces.end());

    // Count unique positions in each dimension and diagonals
    vector<long long> rows(n+1), cols(n+1), ups(2*n+1), downs(2*n+1);
    for (const auto& p : pieces) {
        rows[p.first]++;
        cols[p.second]++;
        ups[p.first - p.second + n]++;
        downs[p.first + p.second]++;
    }

    // Calculate the number of valid positions
    long long valid_positions = n * n - m;

    for (long long i = 1; i <= n; ++i) {
        valid_positions -= rows[i] - 1 + cols[i] - 1;
    }
    for (long long i = 1; i <= 2 * n; ++i) {
        valid_positions -= ups[i] - 1 + downs[i] - 1;
    }

    cout << valid_positions << endl;

    return 0;
}