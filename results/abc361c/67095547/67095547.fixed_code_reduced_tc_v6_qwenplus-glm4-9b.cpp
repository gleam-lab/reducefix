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
    
    // Sort the array to make it easier to find the smallest k-sized subsequence
    sort(a.begin(), a.end());
    
    // We need to find the k-sized subsequence with the smallest range (max - min)
    vector<int> subsequence;
    int minDiff = INT_MAX;
    for (int left = 0; left <= n - k; ++left) {
        int minVal = a[left];
        int maxVal = a[left + k - 1];
        int diff = maxVal - minVal;
        
        // Update the subsequence if the current difference is smaller than the smallest difference found so far
        if (diff < minDiff) {
            minDiff = diff;
            subsequence = vector<int>(a.begin() + left, a.begin() + left + k);
        }
    }
    
    // Output the smallest difference found
    cout << minDiff << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}