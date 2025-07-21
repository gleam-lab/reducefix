#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    long long dp0 = 0;           // not taking previous element
    long long dp1 = -1e18;       // taking previous element (initialized to -infinity)
    
    for (int i = 0; i < n; i++) {
        long long new_dp0 = max(dp0, dp1 + 2 * arr[i]);
        long long new_dp1 = max(dp1, dp0 - arr[i]);
        
        dp0 = new_dp0;
        dp1 = new_dp1;
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}