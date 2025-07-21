#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto& val : v) {
        cin >> val;
    }

    // Sort the array to easily find the minimum and maximum values after removing k elements
    sort(v.begin(), v.end());

    // The optimal strategy is to remove the smallest k elements or the largest k elements
    // to minimize the difference between the maximum and minimum values of the remaining array
    int result = min(v[n-k-1] - v[0], v[n-1] - v[k]);

    cout << result << endl;

    return 0;
}