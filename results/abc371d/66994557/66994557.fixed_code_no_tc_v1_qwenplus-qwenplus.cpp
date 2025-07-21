#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n;
    vector<int> x(n + 1), p(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    // Prefix sum of p
    vector<int> prefixSum(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + p[i];
    }

    cin >> q;
    while(q--) {
        int L, R;
        cin >> L >> R;

        // Find first index where x[i] >= L
        int left = lower_bound(x.begin() + 1, x.end(), L) - x.begin();
        
        // Find first index where x[i] > R
        int right = upper_bound(x.begin() + 1, x.end(), R) - x.begin();

        if (left <= right - 1) {
            cout << prefixSum[right - 1] - prefixSum[left - 1] << endl;
        } else {
            cout << 0 << endl; // No elements in range
        }
    }

    return 0;
}