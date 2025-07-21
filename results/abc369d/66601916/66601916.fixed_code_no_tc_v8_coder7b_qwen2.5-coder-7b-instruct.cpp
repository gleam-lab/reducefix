#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>

using namespace std;

#define INF (long long)1e15+8 // Corrected the value of INF to avoid overflow issues

int main(){
    int n;
    long long dp0, dp1, x, temp;
    dp0 = 0;
    dp1 = -INF;
    cin >> n;

    for ( int i = 0; i < n; i++) {
        cin >> x;
        temp = dp0;
        dp0 = max(dp1 + 2 * x, dp0); // Fixed typo: "max" function should be used instead of "max"
        dp1 = max(temp + x, dp1); // Fixed typo: "max" function should be used instead of "max"
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}