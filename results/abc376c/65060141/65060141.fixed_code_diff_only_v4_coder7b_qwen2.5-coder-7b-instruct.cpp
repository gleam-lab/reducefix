#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;
ll a[N], b[N];

bool canPlace(int x, int n, vector<int>& A, vector<int>& B) {
    // Sort the arrays
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Initialize pointers for both arrays
    int i = 0, j = 0;

    while (i < n && j < n - 1) {
        // If current toy can fit in the current box
        if (B[j] >= A[i]) {
            i++;  // Move to the next toy
            j++;  // Move to the next box
        } else {
            // If current toy cannot fit, we need a larger box
            return false;
        }
    }

    // Check if there are any remaining toys without a box
    while (i < n) {
        if (x < A[i]) {
            return false;
        }
        i++;
    }

    return true;
}

int main() {
    ll n;
    cin >> n;
    vector<int> A(n), B(n - 1);

    for (ll i = 0; i < n; ++i) {
        cin >> A[i];
    }

    for (ll i = 0; i < n - 1; ++i) {
        cin >> B[i];
    }

    // Binary search for the smallest box size x
    int low = *max_element(A.begin(), A.end()), high = 1e9;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canPlace(mid, n, A, B)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}