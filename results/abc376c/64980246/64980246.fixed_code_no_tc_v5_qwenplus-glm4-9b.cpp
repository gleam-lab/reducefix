#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    
    // Sort the toy sizes in descending order and the box sizes in descending order
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    
    // Find the minimum box size x that can fit the largest toy
    int x = a[0];
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > b[i]) {
            x = a[i];
        } else {
            break; // Since the boxes are sorted in descending order, no smaller box can fit the current toy
        }
    }
    
    // Check if x is the smallest box that can fit the largest toy
    bool isValid = true;
    for (int i = 0; i < n - 1; ++i) {
        if (b[i] == x) {
            isValid = false; // There exists a box of size x, so we cannot use x as the minimum size
            break;
        }
    }
    
    // Output the result
    if (isValid) {
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}