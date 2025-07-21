#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

struct Node {
  ll val;
  int idx;
};

bool compare(const Node& a, const Node& b) {
  return a.val < b.val || (a.val == b.val && a.idx < b.idx);
}

vector<int> minVotesToWin(int n, int m, int k, vector<int>& votes) {
  vector<Node> nodes(n + 1);
  for (int i = 1; i <= n; ++i) {
    nodes[i] = {votes[i - 1], i};
  }

  sort(nodes.begin(), nodes.end(), compare);

  vector<ll> prefixSum(n + 1);
  for (int i = 1; i <= n; ++i) {
    prefixSum[i] = prefixSum[i - 1] + nodes[i].val;
  }

  k -= prefixSum[n];
  if (k < 0) {
    return vector<int>(n, -1);
  }

  vector<int> result(n, 0);
  for (int i = 0; i < n; ++i) {
    int target = nodes[i].val + 1;
    int left = i + 1;
    int right = n;
    while (left < right) {
      int mid = (left + right) / 2;
      ll needed = target * (mid - i) - (prefixSum[mid] - prefixSum[i]);
      if (needed > k) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    if (left == n || target * (left - i) - (prefixSum[left] - prefixSum[i]) > k) {
      --left;
    }
    if (left < n && nodes[left].val == target) {
      result[nodes[i].idx - 1] = left - i;
    }
  }

  return result;
}

int main() {
  cin >> N >> M >> K;
  vector<int> votes(N);
  for (int i = 0; i < N; ++i) {
    cin >> votes[i];
  }

  vector<int> results = minVotesToWin(N, M, K, votes);

  for (int i = 0; i < N; ++i) {
    cout << results[i] << ' ';
  }
  cout << endl;

  return 0;
}