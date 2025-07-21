#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum sum based on given conditions
ll maxSum(vector<int>& data) {
    ll sum = 0;
    int n = data.size();
    bool isOddTurn = true;

    for(int i = 0; i < n - 1; ++i) {
        if(isOddTurn) {
            sum += max(data[i], data[i + 1]);
        } else {
            sum += min(data[i], data[i + 1]) * 2;
        }
        isOddTurn = !isOddTurn;
    }

    // Add the last element as it's not paired
    if(n % 2 != 0) {
        sum += data[n - 1];
    }

    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> data(n);

    rep(i, n) {
        cin >> data[i];
    }

    cout << maxSum(data) << endl;
    return 0;
}