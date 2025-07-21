#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum sum based on the given rules
ll maxSum(vector<int>& data) {
    int n = data.size();
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        // If it's an odd index, add the current element as is
        if (i % 2 == 0) {
            sum += data[i];
        } else {
            // For even indices, add twice the value of the next element if it exists
            if (i + 1 < n) {
                sum += 2 * data[i + 1];
                ++i; // Skip the next element as it's already counted
            }
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }
    
    // Calculate and print the maximum sum
    cout << maxSum(data) << endl;
    return 0;
}