#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];
pair<int, int> p[maxN];

// Comparator function to sort pairs based on the first element in descending order
// If first elements are equal, sort based on the second element in ascending order
bool cmp(pair<int, int> p1, pair<int, int> p2) {
  if (p1.first != p2.first) return p1.first > p2.first;
  return p1.second < p2.second;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--) {
    cin >> n >> k;
    priority_queue<int> q;
    long long sum = 0, ans = LLONG_MAX; // Initialize sum as 0 and ans as the maximum possible long long integer

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i <= n; i++) {
      p[i].first = a[i];
      p[i].second = b[i];
    }

    sort(p + 1, p + 1 + n, cmp); // Sort pairs based on the custom comparator

    for (int i = 1; i <= k; i++) {
      sum += p[i].second;
      q.push(p[i].second);
    }

    ans = min(ans, static_cast<long long>(p[k].first * sum)); // Calculate initial answer

    for (int i = k + 1; i <= n; i++) {
      if (p[i].second < q.top()) {
        sum -= q.top(); // Remove the largest element in the current window
        q.pop();
        q.push(p[i].second); // Add the new element to the window
        sum += p[i].second;
      }
      ans = min(ans, static_cast<long long>(p[i].first * sum)); // Update answer with the minimum value found so far
    }

    cout << ans << "\n"; // Print the result for the current test case
  }
  return 0;
}