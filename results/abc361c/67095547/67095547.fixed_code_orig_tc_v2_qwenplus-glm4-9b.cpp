#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    // We're looking at two potential 'cut points' depending on whether k is odd or even
    int i = 0, j = n - 1;
    if (k % 2 == 1) {
        // If k is odd, we can consider removing the middle element of the remaining n-k elements
        j += (n - k) / 2;
    }

    // Calculate the maximum and minimum for the two cases
    int max1 = a[j], min1 = a[i];
    int max2 = a[j - 1], min2 = a[i + 1]; // Since j is now after the middle, j-1 is the largest in the left half

    // The minimum possible value of the difference between the maximum and minimum
    cout << min(max1 - min1, max2 - min2) << endl;

    return 0;
}