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
    
    // Read the array elements
    for (auto &val : v) {
        cin >> val;
    }
    
    // Sort the array
    sort(v.begin(), v.end());

    // The optimal strategy is to remove the smallest k elements or the largest k elements
    // This way, the difference between the max and min values of the resulting array is minimized
    // We choose the smaller of these two differences
    int result = min(v[n-k-1] - v[0], v[n-1] - v[k]);

    cout << result << endl;

    return 0;
}