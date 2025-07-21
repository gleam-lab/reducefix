#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += arr[(i + j) % n];
            // If sum is divisible by m, increment the count of valid subarrays
            if (sum % m == 0) {
                ans++;
                // If sum is zero after adding an element, break to avoid counting subarrays that should be zero
                if (sum == 0) {
                    break;
                }
            }
        }
    }

    cout << ans;
    return 0;
}