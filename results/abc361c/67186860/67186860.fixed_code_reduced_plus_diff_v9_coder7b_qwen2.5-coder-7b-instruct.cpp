#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long long minVal = LLONG_MAX, maxVal = LLONG_MIN;
    for(int i = 0; i <= n-k; i++) {
        minVal = min(minVal, (long long)arr[i+k-1] - arr[i]);
    }

    cout << minVal << "\n";
    return 0;
}