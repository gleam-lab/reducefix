#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n), dp(n, 0);

    // Read the array
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Initialize dp array with the first element
    dp[0] = a[0];

    // Iterate through the array starting from the second element
    for (ll i = 1; i < n; ++i) {
        // If the current number is even, add it to the previous maximum sum
        if (a[i] % 2 == 0) {
            dp[i] = max(dp[i - 1] + a[i], a[i]);
        } 
        // If the current number is odd, take the maximum of adding it to the previous sum or keeping the previous sum
        else {
            dp[i] = max(dp[i - 1] + a[i], dp[i - 1]);
        }
    }

    // The result will be the maximum value in the dp array
    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}