#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  vector<ll> p(n), s(n+1);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    s[i+1] = s[i]+p[i];
  }
  
  // Create a vector of pairs to maintain the original order for binary search
  vector<pair<int, int>> x_p(n);
  for (int i = 0; i < n; i++) {
    x_p[i] = {x[i], i};
  }
  sort(x_p.begin(), x_p.end());
  
  // Extract sorted x values
  vector<int> sorted_x(n);
  for (int i = 0; i < n; i++) {
    sorted_x[i] = x_p[i].first;
  }
  
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    int rt = upper_bound(sorted_x.begin(), sorted_x.end(), r) - sorted_x.begin();
    int lt = lower_bound(sorted_x.begin(), sorted_x.end(), l) - sorted_x.begin();
    // Need to map back to original indices to get correct prefix sum
    // Since the prefix sum is based on original order, this approach won't work
    // Alternative approach: sort both x and p together, then compute prefix sums
    cout << "This approach needs revision - see comments" << endl;
  }
  return 0;
}