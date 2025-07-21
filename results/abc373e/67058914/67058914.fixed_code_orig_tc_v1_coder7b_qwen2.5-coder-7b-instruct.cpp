#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
  ll val;
  int idx;
};

int N, M;
ll K;

auto cmp = [](const auto &A, const auto &B) -> bool {
  return A.val < B.val;
};

vector<Node> preprocess(const vector<int>& A) {
  vector<Node> a(A.size());
  for (int i = 0; i < A.size(); ++i) {
    a[i].val = A[i];
    a[i].idx = i + 1;
  }
  sort(a.begin(), a.end(), cmp);
  return a;
}

void solve(int i, vector<Node>& a, vector<ll>& pre, vector<ll>& ans, ll K, int M) {
  ll remain = K - pre.back();
  ll cur = a[i].val + remain;
  ll target = cur + 1;
  int L = 0, R = N - i - 1;
  while (L < R) {
    int MID = (L + R + 1) / 2;
    ll need = target * MID - (pre[R] - pre[R - MID]);
    if (R - MID < i) {
      need -= (remain + 1);
    }
    if (need > remain) R = MID - 1;
    else L = MID;
  }
  ans[a[i].idx - 1] = L - (R - L < i);
}

int main() {
  cin >> N >> M >> K;

  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  auto a = preprocess(A);
  vector<ll> pre(N + 5);
  pre[0] = 0LL;
  for (int i = 0; i < N; ++i) {
    pre[i + 1] = pre[i] + a[i].val;
  }

  K -= pre.back();

  vector<ll> ans(N);
  for (int i = 0; i < N; ++i) {
    solve(i, a, pre, ans, K, M);
  }

  for (int i = 0; i < N; ++i) {
    if (a[i].val + ans[i] >= pre.back()) ans[i] = 0;
    else if (a[i].val + ans[i] < pre.back() && a[i].val + ans[i] + 1 >= pre.back()) ans[i] = -1;
  }

  for (int i = 0; i < N; ++i) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

  return 0;
}