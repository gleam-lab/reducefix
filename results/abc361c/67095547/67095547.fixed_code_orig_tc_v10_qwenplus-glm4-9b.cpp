#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Sort the array
    sort(arr.begin(), arr.end());

    // Find the minimum difference between the maximum and minimum of the window of size n-k
    long long min_diff = arr[n - k] - arr[k - 1];

    for (int i = 0; i <= k - 1; ++i) {
        min_diff = min(min_diff, arr[n - k - 1] - arr[i]);
    }

    cout << min_diff << endl;

    return 0;
}