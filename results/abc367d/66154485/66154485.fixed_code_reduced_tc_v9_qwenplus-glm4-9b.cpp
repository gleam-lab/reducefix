#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[200005];

    // Reading the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    int sum = 0;

    // Calculate prefix sums and check for each prefix sum if it is divisible by m
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum % m == 0) {
            ans++;
        }

        // Check all subarrays ending at i with sum divisible by m
        for (int j = 0; j < i; j++) {
            sum -= arr[j];
            if (sum % m == 0) {
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}