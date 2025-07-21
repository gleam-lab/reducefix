#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    ll answer = LLONG_MAX;
    // The maximum element in the sequence
    ll mx = A[n - 1];
    // The minimum element in the sequence
    ll mn = A[0];

    // Initialize two pointers
    int lp = 0, rp = n - 1;
    // Temporary storage for the left and right parts
    vector<int> left, right;
    // K-array to store the elements to be removed
    vector<int> to_remove;

    // Process the array
    while (lp <= rp) {
        int leftRemoved = 0, rightRemoved = 0;
        // Expand the left part
        while (lp < n && rightRemoved + leftRemoved <= k) {
            // Add elements to the left part
            left.push_back(A[lp]);
            leftRemoved++;
            lp++;
        }
        // Expand the right part
        while (rp >= 0 && rightRemoved + leftRemoved <= k) {
            // Add elements to the right part
            right.push_back(A[rp]);
            rightRemoved++;
            rp--;
        }
        // Calculate the new answer
        ll newAnswer = max(mx, right.empty() ? right.back() : right.back()) - min(mn, left.empty() ? left.front() : left.front());
        answer = min(answer, newAnswer);
        // Adjust lp and rp
        lp++;
        rp--;
    }

    cout << answer << endl;
}