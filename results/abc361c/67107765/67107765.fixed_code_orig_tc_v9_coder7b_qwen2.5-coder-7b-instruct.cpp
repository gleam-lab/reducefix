#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    
    // Read the array elements
    for(int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    // Sort the array
    sort(num.begin(), num.end());

    // Calculate the minimum possible value of the difference between the maximum and minimum values of B
    int ans = num[n-k-1] - num[k];

    // Output the result
    cout << ans << endl;

    return 0;
}