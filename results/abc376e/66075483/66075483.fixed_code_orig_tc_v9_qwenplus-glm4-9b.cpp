#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i].first;
        b[i].second = i;
    }

    // Sort A by value descending, sort B by value ascending
    sort(a.begin(), a.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
        return x.first > y.first;
    });
    sort(b.begin(), b.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
        return x.first < y.first;
    });

    long long min_value = LLONG_MAX;
    // Calculate the minimum value for each possible subset starting from each A_i
    for (int i = 0; i < n - k + 1; ++i) {
        long long sum_b = 0;
        // Add the smallest k-1 values of B corresponding to the current starting index i
        for (int j = i; j < i + k - 1; ++j) {
            sum_b += b[j].first;
        }
        // Update the minimum value
        min_value = min(min_value, (long long)a[i].first * sum_b);
    }

    cout << min_value << endl;
    return 0;
}