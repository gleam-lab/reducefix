#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n), b(n-1);
    
    // Read input sizes
    for(int i=0;i<n;++i) cin >> a[i];
    for(int i=0;i<n-1;++i) cin >> b[i];

    // Sort both arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Initialize variables
    int i = 0, j = 0;
    while(i < n && j < n-1) {
        // If current toy fits in the current box
        if(a[i] <= b[j]) {
            ++i;
        } 
        // If toy doesn't fit, try next box
        else {
            ++j;
        }
    }

    // Check if we've successfully placed all toys
    if(i == n) {
        cout << b[j] << '\n';
    } 
    else {
        cout << "-1\n";
    }

    return 0;
}