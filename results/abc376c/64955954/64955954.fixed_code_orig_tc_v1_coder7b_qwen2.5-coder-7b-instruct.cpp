#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    for (int i = 0; i < n - 1; ++i)
        cin >> b[i];

    sort(a.begin(), a.end()); // Sort toy sizes
    sort(b.begin(), b.end()); // Sort box sizes
    
    int j = 0; // Pointer for toy array
    for (int i = 0; i < n - 1 && j < n; ++i) {
        while (j < n && b[j] < a[i]) // Find the smallest box >= current toy size
            ++j;
        
        if (j == n) { // No suitable box found
            cout << -1 << '\n';
            return 0;
        }
        ++j; // Move to the next toy
    }

    cout << a[n - 1] << '\n'; // The largest toy determines the minimum box size needed
    return 0;
}