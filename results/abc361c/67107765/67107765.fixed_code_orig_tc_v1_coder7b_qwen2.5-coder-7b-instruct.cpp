#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<long long> num(n);
    for(int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    // Sort the array to facilitate finding the optimal removals
    sort(num.begin(), num.end());

    // The optimal strategy is to remove k smallest and largest elements
    // This minimizes the difference between the maximum and minimum of the remaining elements
    long long min_val = num[k], max_val = num[n-k-1];
    long long result = max_val - min_val;

    cout << result << endl;
    return 0;
}