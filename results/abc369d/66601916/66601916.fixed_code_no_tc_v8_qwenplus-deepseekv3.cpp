#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define INF LONG_LONG_MIN

int main() {
    int n;
    cin >> n;
    
    long long dp0 = 0;         // Represents not taking the current element
    long long dp1 = INF;       // Represents taking the current element
    
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        
        long long new_dp0 = max(dp0, dp1 + x);  // Either continue not taking or take after previous take
        long long new_dp1 = max(dp1, dp0 - x);  // Either continue taking or take current after not taking
        
        dp0 = new_dp0;
        dp1 = new_dp1;
    }
    
    cout << max(dp0, dp1) << endl;
    return 0;
}