#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, ans = 0, arr[200005];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += arr[(i + j) % n]; // Corrected the upper limit to n-1
            if (sum % m == 0) {
                ans++; // Move the condition inside the outer loop to check after each sum
            }
        }
    }
    cout << ans;
    return 0;
}