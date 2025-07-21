#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate the maximum experience points
ll maxExperiencePoints(const vector<ll>& a, int index, bool oddTurn, vector<vector<ll>>& dp) {
    int n = a.size();
    if (index >= n) return 0;
    
    if (dp[index][oddTurn] != -1) return dp[index][oddTurn];
    
    if (oddTurn) {
        // Player can either take one monster or skip it
        dp[index][oddTurn] = max(maxExperiencePoints(a, index + 1, !oddTurn, dp) + 2 * a[index],
                                maxExperiencePoints(a, index + 2, !oddTurn, dp));
    } else {
        // Player can either take one monster or skip it
        dp[index][oddTurn] = max(maxExperiencePoints(a, index + 1, !oddTurn, dp) + a[index],
                                maxExperiencePoints(a, index + 2, !oddTurn, dp) + 2 * a[index]);
    }
    
    return dp[index][oddTurn];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Initialize DP table with -1
    vector<vector<ll>> dp(n, vector<ll>(2, -1));
    
    // Calculate the result starting from the first monster with an odd turn
    ll result = maxExperiencePoints(a, 0, true, dp);
    
    cout << result << endl;
    
    return 0;
}