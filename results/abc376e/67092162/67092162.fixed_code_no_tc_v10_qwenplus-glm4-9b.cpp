#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];
pair<int, int> p[maxN];
bool cmp(pair<int, int> p1, pair<int, int> p2) {
  if (p1.first != p2.first)
    return p1.first > p2.first; // Changed to descending for A[i]
  return p1.second > p2.second; // Changed to descending for B[i]
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--) {
    cin >> n >> k;
    int maxA = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cin >> b[i];
    }
    
    // Create a list of pairs (A[i], B[i]) and sort by A[i] descending
    for (int i = 0; i < n; i++) {
      p[i] = {a[i], b[i]};
    }
    sort(p, p + n, cmp);
    
    // Calculate the initial sum of B and the maximum A in the first k elements
    long long sum = 0, maxB = 0;
    for (int i = 0; i < k; i++) {
      sum += p[i].second;
      if (i == 0 || p[i].first > maxA) {
        maxA = p[i].first;
      }
    }
    
    // Calculate initial result
    long long result = maxA * sum;
    
    // Slide window to find the minimum result
    for (int i = k; i < n; i++) {
      sum += p[i].second - p[i - k].second;
      maxA = p[i].first; // Since we're sorting by A descending, the max A is the first in the current window
      result = min(result, maxA * sum);
    }
    
    cout << result << "\n";
  }
  
  return 0;
}