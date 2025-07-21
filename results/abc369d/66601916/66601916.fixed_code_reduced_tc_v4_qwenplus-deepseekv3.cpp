#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    long long max_sum = 0;
    long long max_gain = 0;
    long long current_sum = 0;

    for (int i = 0; i < n; ++i) {
        max_gain = max(max_gain, a[i]);
        current_sum += a[i];
    }

    max_sum = current_sum + max_gain;
    cout << max_sum << endl;

    return 0;
}