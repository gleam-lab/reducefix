#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
using ll = long long;
using P = pair<ll, ll>;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define yes cout << "Yes" << endl
#define no cout << "No" << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<ll> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    // Find the range of elements to consider removing
    int low = k / 2;
    int high = low + (k % 2);

    // Calculate the minimum difference between the max and min
    // We consider removing `k` elements below the median or above the median
    ll min_diff = LINF;
    for (int i = low; i <= high; i++) {
        ll max_val = A[n - 1 - i];
        ll min_val = A[i];
        min_diff = min(min_diff, max_val - min_val);
    }

    cout << min_diff << endl;
    return 0;
}