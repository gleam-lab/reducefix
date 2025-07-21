#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    long long dp[2] = {0, INT_MIN};
    
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(x > 0) {
            dp[0] += x * 2;
            dp[1] += x;
        } else {
            dp[1] += x;
            dp[0] = max(dp[0], dp[1]);
        }
    }
    
    cout << max(dp[0], dp[1]) << endl;
    return 0;
}