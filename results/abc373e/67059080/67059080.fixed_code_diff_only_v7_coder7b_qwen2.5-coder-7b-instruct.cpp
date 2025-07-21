#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  cin >> N >> M >> K;

  vector<ll> votes(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> votes[i];
  }

  vector<ll> prefix_sum(N + 1);
  for (int i = 1; i <= N; ++i) {
    prefix_sum[i] = prefix_sum[i - 1] + votes[i];
  }

  vector<ll> result(N + 1, -1);
  for (int i = 1; i <= N; ++i) {
    ll current_votes = votes[i];
    ll remaining_votes = K - prefix_sum[i];
    
    if (current_votes >= remaining_votes + 1) {
      result[i] = 0;
      continue;
    }

    ll needed_votes = remaining_votes + 1 - current_votes;
    ll max_possible_votes = remaining_votes / (M - 1);
    
    if (max_possible_votes >= current_votes) {
      result[i] = needed_votes;
    }
  }

  for (int i = 1; i <= N; ++i) {
    cout << result[i] << " ";
  }

  return 0;
}