#include <bits/stdc++.h>
using namespace std;

#define INF (long long)1e18 + 8

int main(){
    int n;
    long long dp0 = 0, dp1 = -INF;
    cin >> n;

    for(int i = 0; i < n; ++i){
        long long x;
        cin >> x;
        dp0 = max(dp0, dp1 + x); // Defeat the current monster
        if(i % 2 == 0) dp1 = max(dp1, dp0 + x); // Add extra experience if it's an even-numbered defeated monster
        else dp1 = max(dp1, dp0); // Let the current monster go
    }

    cout << dp0 << endl; // Print the maximum total experience points
    return 0;
}