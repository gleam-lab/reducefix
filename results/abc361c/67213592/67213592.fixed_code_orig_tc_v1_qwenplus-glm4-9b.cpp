#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    // Remove K elements from the sequence
    sort(v.begin(), v.end());
    vector<int> newV;
    for (int i = 0; i < n; ++i) {
        if (k > 0 && (i == 0 || v[i] != v[i - 1])) {
            newV.push_back(v[i]);
        } else {
            --k;
        }
    }

    // Now newV has n-k elements, find the minimum and maximum
    int minVal = *min_element(newV.begin(), newV.end());
    int maxVal = *max_element(newV.begin(), newV.end());

    // Output the result
    cout << maxVal - minVal << endl;

    return 0;
}