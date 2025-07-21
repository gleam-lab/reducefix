#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    vector<int> x(n + 1), p(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    // Build prefix sum of power
    vector<long long> prefix(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + p[i];
    }

    cin >> q;
    while(q--) {
        int L, R;
        cin >> L >> R;

        // Binary search to find the first index where x[i] >= L
        int left = 1, right = n;
        int start_idx = n + 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(x[mid] >= L) {
                start_idx = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // Binary search to find the last index where x[i] <= R
        left = 1, right = n;
        int end_idx = 0;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(x[mid] <= R) {
                end_idx = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if(start_idx > end_idx) {
            cout << 0 << endl;
        } else {
            cout << (prefix[end_idx] - prefix[start_idx - 1]) << endl;
        }
    }

    return 0;
}