#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<pair<long long, long long>> pieces(m);
    for (int i = 0; i < m; i++) {
        long long x, y;
        cin >> x >> y;
        pieces[i] = {x, y};
    }

    // Step 1: Find the maximum x, y, x-y, x+y that have pieces
    long long max_x = 0, max_y = 0, max_xy = 0, max_x_minus_y = 0, max_x_plus_y = 0;
    for (const auto& p : pieces) {
        max_x = max(max_x, p.first);
        max_y = max(max_y, p.second);
        max_xy = max(max_xy, p.first + p.second);
        max_x_minus_y = max(max_x_minus_y, abs(p.first - p.second));
        max_x_plus_y = max(max_x_plus_y, abs(p.first + p.second));
    }

    // Step 2: Calculate the number of captured squares
    long long captured = (n - max_x) * n + (n - max_y) * n + (n - max_x_minus_y) * (n - max_y) +
                         (n - max_x_plus_y) * (n - max_y) + (n - max_x_minus_y) * (n - max_x_plus_y);
    captured += (max_x + max_y - 1) * (max_x + max_y - 2) / 2; // Captured by x+y
    captured += (max_x_minus_y + max_y - 1) * (max_x_minus_y + max_y - 2) / 2; // Captured by x-y
    captured += (max_x_plus_y + max_y - 1) * (max_x_plus_y + max_y - 2) / 2; // Captured by x+y

    // Step 3: Calculate the total number of squares minus the captured ones
    long long total = n * n;
    long long safe_squares = total - captured;

    cout << safe_squares << endl;

    return 0;
}