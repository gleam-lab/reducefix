#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

vector<ll> A;

int main() {
  cin >> N >> M >> K;
  A.resize(N + 1);
  
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
  }

  sort(A.begin() + 1, A.end());

  vector<ll> prefix(N + 1);
  prefix[0] = 0;
  for (int i = 1; i <= N; ++i) {
    prefix[i] = prefix[i - 1] + A[i];
  }

  vector<ll> ans(N + 1, -1);
  for (int i = 1; i <= N; ++i) {
    ll needed_votes = 0;
    int higher_ranked_count = N - i + 1;
    
    if (higher_ranked_count < M) {
      needed_votes = ((prefix[N] - prefix[i]) + 1) / higher_ranked_count;
      if (((prefix[N] - prefix[i]) + 1) % higher_ranked_count != 0) {
        needed_votes++;
      }
      
      if (needed_votes > K - prefix[N] + prefix[i]) {
        needed_votes = -1;
      }
    }
    
    ans[i] = needed_votes;
  }

  for (int i = 1; i <= N; ++i) {
    cout << ans[i] << ' ';
  }
  
  return 0;
}