#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    int m = n - k; // number of remaining elements
    int min_diff = a[m - 1] - a[0]; // initial window [0, m-1]
    
    // Slide the window of size m over the sorted array
    for (int i = 1; i + m - 1 < n; i++) {
        int diff = a[i + m - 1] - a[i];
        min_diff = min(min_diff, diff);
    }
    
    cout << min_diff << endl;
    return 0;
}