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
    
    sort(v.begin(), v.end());

    // After removing k elements, we will have n-k elements left.
    // The smallest possible difference between max and min values of the new sequence
    // can be achieved by removing the largest k elements or the smallest k elements.
    // This way, the difference between the max and min values of the remaining elements
    // will be minimized.

    int result = min(v[n-k-1] - v[0], v[n-1] - v[k]);

    cout << result << endl;

    return 0;
}