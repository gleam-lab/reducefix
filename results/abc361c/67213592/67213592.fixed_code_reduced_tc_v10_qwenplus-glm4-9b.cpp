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
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<int> remaining(n - k);
    for (int i = 0; i < n - k; ++i) {
        remaining[i] = v[i];
    }

    // Now find the minimum possible value of the maximum value minus the minimum value of the remaining sequence.
    int minVal = remaining.front();
    int maxVal = remaining.back();
    int result = maxVal - minVal;

    cout << result << endl;

    return 0;
}