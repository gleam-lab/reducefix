#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

int max_element_in_range(vector<int>& arr, int start, int end) {
    return *max_element(arr.begin() + start, arr.begin() + end + 1);
}

int sum_of_elements_in_range(vector<int>& arr, int start, int end) {
    return accumulate(arr.begin() + start, arr.begin() + end + 1, 0LL);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> A(n), B(n);
        for(int i=0;i<n;i++) cin >> A[i];
        for(int i=0;i<n;i++) cin >> B[i];

        // Sort indices based on A_i values
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j){ return A[i] < A[j]; });

        int best_sum = 0, best_max = 0;
        for(int i=0;i<k;i++) {
            best_sum += B[idx[i]];
            best_max = A[idx[i]];
        }

        int ans = best_max * best_sum;

        for(int i=k;i<n;i++) {
            int current_max = A[idx[i]];
            int current_sum = best_sum - B[idx[i-k]] + B[idx[i]];

            if(current_max * current_sum < ans) {
                ans = current_max * current_sum;
                best_max = current_max;
                best_sum = current_sum;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}