#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[200005];

    // Read the input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 0;

    // Calculate the number of subarrays with sum divisible by m
    for (int i = 0; i < n; i++) {
        int sum = 0;
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