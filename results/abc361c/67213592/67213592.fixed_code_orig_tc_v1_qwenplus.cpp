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
    
    // We remove exactly K elements, so we keep (n - K) elements.
    // The optimal way is to choose a contiguous segment of length (n - K)
    // in the sorted array, because if the min and max are fixed, including
    // everything in between can't hurt and might allow more flexibility.
    int len = n - k;
    long long min_diff = v[len - 1] - v[0]; // Initialize with first window
    
    for (int i = 1; i + len - 1 < n; i++) {
        int j = i + len - 1;
        min_diff = min(min_diff, (long long)(v[j] - v[i]));
    }
    
    cout << min_diff << endl;
    
    return 0;
}