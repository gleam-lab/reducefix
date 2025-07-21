#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n - 1; ++i) cin >> b[i];
    
    // Sort the toy sizes and box sizes
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    // Initialize two pointers
    int i = 0, j = 0;
    // Variable to keep track of the maximum box size needed
    int max_box_size = -1;
    
    // Traverse both arrays using the two-pointer technique
    while(i < n && j < n - 1) {
        if(a[i] <= b[j]) {
            // Assign toy to the current box
            max_box_size = max(max_box_size, b[j]);
            i++;
        } else {
            // Move to the next larger box
            j++;
        }
    }
    
    // Check if all toys could be assigned to some box
    if(i != n) {
        cout << "-1" << endl;
    } else {
        cout << max_box_size << endl;
    }
}

int main() {
    solve();
    return 0;
}