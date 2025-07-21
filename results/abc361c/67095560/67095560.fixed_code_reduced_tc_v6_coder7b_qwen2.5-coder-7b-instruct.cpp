#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long result = LLONG_MAX;
    for (int i = 0; i <= n - k; ++i) {
        result = min(result, a[i + k - 1] - a[i]);
    }

    cout << result << endl;
    return 0;
}