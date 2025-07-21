#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
long long t, n, k, a[maxN], b[maxN];

// Function to calculate the minimum cost based on the problem statement
void solve() {
    cin >> n >> k;
    vector<pair<long long, long long>> vec(n);
    for(long long i = 0; i < n; ++i)
        cin >> a[i] >> b[i], vec[i] = {a[i], b[i]};
    
    // Sort pairs based on the first element (maximize the first element in subset S)
    sort(vec.begin(), vec.end());
    
    // Priority queue to keep track of the smallest elements in the subset
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long sum = 0, ans = LLONG_MAX;
    
    // Initialize the priority queue with the first 'k' elements
    for(long long i = 0; i < k; ++i)
        pq.push(vec[i].second), sum += vec[i].second;
    
    // Calculate initial cost
    ans = min(ans, sum * vec[k - 1].first);
    
    // Iterate through the rest of the elements
    for(long long i = k; i < n; ++i) {
        // If current element can replace the largest element in the subset
        if(vec[i].second < pq.top()) {
            sum -= pq.top(); // Remove the largest element
            pq.pop();
            pq.push(vec[i].second); // Add the current element
            sum += vec[i].second; // Update the sum
        }
        // Calculate the new cost and update the answer
        ans = min(ans, sum * vec[i].first);
    }
    
    // Print the result for this test case
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}