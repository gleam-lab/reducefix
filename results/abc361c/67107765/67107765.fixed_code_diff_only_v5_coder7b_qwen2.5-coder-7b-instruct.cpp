#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    // The optimal strategy is to remove the smallest 'k' elements or the largest 'k' elements
    // to minimize the difference between the maximum and minimum values of the resulting array.
    // Removing the smallest 'k' elements will give us the smallest possible maximum value,
    // and removing the largest 'k' elements will give us the smallest possible minimum value.
    int min_val = num[k]; // Minimum value after removing 'k' smallest elements
    int max_val = num[n - k - 1]; // Maximum value after removing 'k' largest elements
    cout << max_val - min_val << endl;
    return 0;
}