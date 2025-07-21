#include <bits/stdc++.h>
using namespace std;

#define INF (long long)1e18

int main(){
    int n;
    long long dp0, dp1, x, temp;
    dp0 = 0;
    dp1 = -INF;
    cin >> n;

    for ( int i = 0; i < n; i++) {
        cin >> x;
        temp = dp0;
        if(i % 2 == 0){
            dp0 = max(dp1 + x, dp0); // No extra points for even-indexed monsters when they are defeated
            dp1 = max(temp + x + x, dp1); // Extra points for even-indexed monsters when they are defeated
        } else {
            dp0 = max(dp1 + x + x, dp0); // Extra points for odd-indexed monsters when they are defeated
            dp1 = max(temp + x, dp1); // No extra points for odd-indexed monsters when they are defeated
        }
    }

    cout << max( dp0,dp1) << endl;
    return 0;
}