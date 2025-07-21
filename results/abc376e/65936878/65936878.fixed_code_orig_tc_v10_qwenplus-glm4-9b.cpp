#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        
        // Reverse both arrays to get the smallest A_i and the largest B_i easily
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        // Calculate the expression using the smallest A_i and the largest B_i - 1
        int ans = a[0] * (b[k-1] + b[k-2] + ... + b[0]);
        cout << ans << '\n';
    }
    return 0;
}