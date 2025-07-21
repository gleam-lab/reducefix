#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);

    // Read the array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        // Use a sliding window to calculate the sum of subarrays
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum % m == 0) {
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}