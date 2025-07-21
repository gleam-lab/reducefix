#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> A(n), B(n);
        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int i = 0; i < n; ++i) cin >> B[i];

        // Create pairs of (A[i], i)
        vector<pii> AB(n);
        for (int i = 0; i < n; ++i) AB[i] = {A[i], i};

        // Sort the pairs by A[i]
        sort(AB.begin(), AB.end());

        // Select the first K elements
        int max_A = 0, sum_B = 0;
        for (int i = 0; i < k; ++i) {
            max_A = max(max_A, A[AB[i].second]);
            sum_B += B[AB[i].second];
        }

        // Calculate the result
        cout << max_A * sum_B << '\n';
    }

    return 0;
}