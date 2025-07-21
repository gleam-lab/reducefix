#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

template<typename T>
void read_vector(vector<T>& v, int n) {
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

int main() {
    long long n, m;
    cin >> n >> m;

    vector<long long> a(m), b(m);
    read_vector(a, m);
    read_vector(b, m);

    long long total_squares = n * n;
    set<long long> rows, cols, sums, differences;

    for (int i = 0; i < m; ++i) {
        rows.insert(a[i]);
        cols.insert(b[i]);
        sums.insert(a[i] + b[i]);
        differences.insert(a[i] - b[i]);
    }

    // Calculate the number of squares that cannot be captured by any existing piece
    long long capturable = rows.size() * n + cols.size() * n +
                           sums.size() * n / 2 + differences.size() * n / 2;

    // Subtract the squares that are on the lines captured by the existing pieces
    capturable -= rows.size() * cols.size() / 2;
    capturable -= rows.size() * sums.size() / 4;
    capturable -= rows.size() * differences.size() / 4;
    capturable -= cols.size() * sums.size() / 4;
    capturable -= cols.size() * differences.size() / 4;

    cout << total_squares - capturable << endl;

    return 0;
}