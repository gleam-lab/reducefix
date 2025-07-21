#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n-1);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n-1; ++i) cin >> b[i];

    // Sort both arrays to facilitate finding the minimum x
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Initialize the answer with the maximum element in 'a'
    long long ans = *max_element(a.begin(), a.end());

    // Iterate through each box size in 'b' and check if we can fit the largest toy in the current box
    for(int i = 0; i < n-1; ++i) {
        if(b[i] >= a[n-1]) {
            ans = min(ans, b[i]);
            break;
        }
        if(b[i] < a[n-1] && (i == n-2 || b[i+1] >= a[n-1])) {
            ans = min(ans, max(b[i], a[n-1]));
            break;
        }
    }

    // If no valid x is found, output -1
    if(ans == *max_element(a.begin(), a.end())) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}