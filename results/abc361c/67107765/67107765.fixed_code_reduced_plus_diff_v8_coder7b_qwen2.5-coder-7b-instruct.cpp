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

    // The optimal strategy is to remove the smallest K elements and largest K elements
    // This way, the difference between the max and min values of the remaining array is minimized
    int result = num[n - k] - num[k];

    cout << result << endl;

    return 0;
}