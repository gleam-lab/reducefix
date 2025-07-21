#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;
constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;

// Function to calculate the minimum value of the given expression
ll minExpressionValue(int n, int k, vector<ll>& a, vector<ll>& b) {
    vector<pair<ll, ll>> pairs(n);
    
    // Create pairs of elements from both arrays
    for(int i = 0; i < n; ++i) {
        pairs[i] = {a[i], b[i]};
    }

    // Sort the pairs based on the first element (a)
    sort(pairs.begin(), pairs.end());

    // Initialize variables to keep track of the maximum A and sum of B
    ll maxA = 0;
    ll sumB = 0;
    for(int i = 0; i < k; ++i) {
        maxA = max(maxA, pairs[i].first);
        sumB += pairs[i].second;
    }

    // Calculate the initial result
    ll result = maxA * sumB;

    // Sliding window approach to find the minimum value
    for(int i = k; i < n; ++i) {
        // Update the sum of B and remove the smallest element in the current window
        sumB += pairs[i].second - pairs[i-k].second;

        // Update the maximum A in the current window
        maxA = max(maxA, pairs[i].first);

        // Calculate the new result and update if it's smaller than the current minimum
        result = min(result, maxA * sumB);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        
        // Read the elements of array A
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        // Read the elements of array B
        for(int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // Calculate and print the minimum value for the current test case
        cout << minExpressionValue(n, k, a, b) << '\n';
    }

    return 0;
}