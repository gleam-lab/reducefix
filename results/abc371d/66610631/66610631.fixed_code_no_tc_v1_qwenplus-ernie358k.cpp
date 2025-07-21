#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = c[i - 1] + b[i];
    }
    
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        
        // Using lower_bound and upper_bound to find positions in sorted array a
        auto l_i = lower_bound(a.begin() + 1, a.end(), l) - a.begin();
        auto r_i = upper_bound(a.begin() + 1, a.end(), r) - a.begin();
        
        // Adjusting indices for 0-based access and handling edge cases
        if (l_i == 0 || r_i == n + 1) {
            // If either l or r is out of bounds of array a, output the total sum of b
            cout << c[n] << endl;
        } else {
            // Sum of b[a[l-1]..a[r-1]], adjusting for 1-based input and 0-based array
            cout << c[r_i - 1] - c[l_i - 1] << endl;
        }
    }
    
    return 0;
}