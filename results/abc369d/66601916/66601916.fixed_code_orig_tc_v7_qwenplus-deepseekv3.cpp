#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define INF LONG_LONG_MAX

int main() {
    int n;
    cin >> n;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    if (n == 1) {
        cout << max(0LL, nums[0]) << endl;
        return 0;
    }
    
    long long prev_prev_max = 0;
    long long prev_max = 0;
    long long curr_max = 0;
    
    for (int i = 0; i < n; i++) {
        curr_max = max(prev_prev_max + nums[i], prev_max);
        prev_prev_max = prev_max;
        prev_max = curr_max;
    }
    
    cout << curr_max << endl;
    return 0;
}