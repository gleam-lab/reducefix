#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n; // Number of elements in the array a
    vector<int> a(n + 1); // Array a with initial values initialized
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; // Read elements from the array a
    }
    
    // ... Rest of the code remains the same ...
    // ... This section will be fixed ...
    
    // Analysis and correction
    if (r >= a[n]) { // If the range being compared is within the array bounds
        // Fixed code: Calculate the difference between c[n] and c[i-1] for each range pair (l, r)
        cout << c[n] - c[i - 1] << endl; // If range is within array bounds, calculate difference and output it
    } else { // Otherwise, output the difference between c[j-1] and c[i-1] if range is within array bounds
        // ... This part will be corrected based on the logic above ...
    }
    
    return 0; // Returning 0 indicates successful completion of the program
}