#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long dp_prev_0 = 0;       // Didn't take previous element
    long long dp_prev_1 = LLONG_MIN; // Took previous element
    
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        
        long long new_dp_0 = max(dp_prev_0, dp_prev_1 + x);
        long long new_dp_1 = max(dp_prev_0 + x, dp_prev_1);
        
        dp_prev_0 = new_dp_0;
        dp_prev_1 = new_dp_1;
    }
    
    cout << max(dp_prev_0, dp_prev_1) << endl;
    return 0;
}