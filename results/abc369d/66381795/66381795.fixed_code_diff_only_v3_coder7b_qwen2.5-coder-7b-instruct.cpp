#include <bits/stdc++.h>
using namespace std;

// Function to calculate the sum based on the given conditions
ll calculateSum(vector<int>& data) {
    ll sum = 0;
    int n = data.size();
    
    // Iterate through the array
    for(int i = 0; i < n - 1; ++i) {
        // Check the condition and add to sum accordingly
        if(data[i + 1] * 2 > data[i] + data[i + 1]) {
            sum += data[i + 1] * 2;
            ++i; // Skip the next element as it's already considered
        } else {
            sum += data[i];
        }
    }
    
    // Add the last element if there is one
    if(n > 0) {
        sum += data[n - 1];
    }
    
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    
    // Input the elements of the array
    for(int i = 0; i < n; ++i) {
        cin >> data[i];
    }
    
    // Calculate and output the result
    cout << calculateSum(data) << endl;
    
    return 0;
}