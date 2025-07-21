#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the array to easily find the largest and smallest elements
    sort(a.begin(), a.end());

    // Calculate the number of elements to remove
    int numToRemove = k / 2;

    // Remove the largest numToRemove elements and the smallest numToRemove elements
    vector<int> remaining;
    for (int i = numToRemove; i < n - numToRemove; ++i) {
        remaining.push_back(a[i]);
    }

    // Find the minimum and maximum of the remaining elements
    int minVal = *min_element(remaining.begin(), remaining.end());
    int maxVal = *max_element(remaining.begin(), remaining.end());

    // Calculate and print the minimum possible range
    cout << maxVal - minVal << endl;
}

int main() {
    solve();
    return 0;
}