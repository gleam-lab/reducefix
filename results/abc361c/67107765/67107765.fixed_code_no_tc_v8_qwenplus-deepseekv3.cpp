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
    
    // The problem reduces to finding the minimum difference between max and min
    // in any window of size (n - k) in the original sequence.
    int window_size = n - k;
    if (window_size == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    // To find the min (max - min) in any window of size window_size.
    // We can sort the array and check all possible windows of size window_size.
    vector<int> sorted_num = num;
    sort(sorted_num.begin(), sorted_num.end());
    
    int min_diff = INT_MAX;
    for (int i = 0; i + window_size - 1 < n; i++) {
        int current_diff = sorted_num[i + window_size - 1] - sorted_num[i];
        if (current_diff < min_diff) {
            min_diff = current_diff;
        }
    }
    cout << min_diff << endl;
    return 0;
}