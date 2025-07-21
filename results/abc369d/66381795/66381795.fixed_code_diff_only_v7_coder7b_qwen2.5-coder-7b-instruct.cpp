#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum sum based on the given rules
ll calculateMaxSum(vector<int>& data) {
    ll sum = 0;
    int n = data.size();
    for (int i = 0; i < n; ++i) {
        if ((i + 1 < n && data[i + 1] * 2 > data[i] + data[i + 1]) || (i == n - 1)) {
            sum += max(data[i], data[i + 1]);
            ++i; // Skip the next element as it is already considered
        } else {
            sum += data[i];
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
    
    // Calculate and output the result
    cout << calculateMaxSum(data) << endl;
    return 0;
}