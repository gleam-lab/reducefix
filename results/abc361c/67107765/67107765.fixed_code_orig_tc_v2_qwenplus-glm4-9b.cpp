#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<ll> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    
    // Case 1: Remove the first K elements
    ll min1 = num[k]; // Minimum of the remaining array
    ll max1 = num[n - 1]; // Maximum of the remaining array
    
    // Case 2: Remove the last K elements
    ll min2 = num[0]; // Minimum of the remaining array
    ll max2 = num[n - k - 1]; // Maximum of the remaining array
    
    // Output the minimum of the differences from both cases
    cout << min(abs(max1 - min1), abs(max2 - min2)) << endl;
}