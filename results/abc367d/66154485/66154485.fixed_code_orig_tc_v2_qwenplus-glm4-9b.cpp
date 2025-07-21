#include <iostream>
using namespace std;
int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    int arr[200005];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Iterate over all starting points for the groups
    for (int i = 0; i < n; i++) {
        int sum = 0;
        // Iterate over each group of m elements starting from index i
        for (int j = 0; j < m; j++) {
            sum += arr[(i + j) % n];
        }
        // Check if the sum of this group is divisible by m
        if (sum % m == 0) {
            ans++; // This group is valid, increment the count
        }
    }
    
    cout << ans;
    return 0;
}