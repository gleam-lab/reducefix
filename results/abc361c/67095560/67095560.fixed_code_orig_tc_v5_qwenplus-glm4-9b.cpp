#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    long long min_diff = a[n-1] - a[0];  // Initial difference with no removal

    // Try removing elements from both ends
    for (int i = 0; i <= min(k, n/2); ++i) {
        long long current_max = *max_element(a.begin() + i + 1, a.begin() + n - k + i);
        long long current_min = *min_element(a.begin() + n - k + i, a.begin() + n - i);
        min_diff = min(min_diff, current_max - current_min);
    }

    cout << min_diff;
    return 0;
}