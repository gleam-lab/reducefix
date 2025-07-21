#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define yes cout << "Yes" << endl
#define no cout << "No" << endl

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int res = INT_MAX;
    for(int i = 0; i <= n - k; ++i)
        res = min(res, arr[i + k - 1] - arr[i]);

    cout << res << '\n';

    return 0;
}