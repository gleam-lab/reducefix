#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define g(i,t) get<i>(t)

#define tos(n) to_string(n)
#define toc(n) '0' + n
#define toi(s) stoi(s)
#define btoi(b) static_cast<int>(b.to_ulong())

using namespace std;

using ll = long long int;
using vi = vector<int>;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, K;
  cin >> N >> K;
  vi A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  sort(all(A));
  vi diffs;
  for (int i = 1; i < N; i++) {
    diffs.eb(A[i] - A[i - 1]);
  }

  sort(rall(diffs));

  for (int i = 0; i < K; i++) {
    diffs.pop_back();
  }

  if (!diffs.empty()) {
    cout << A[N - 1] - A[0] - diffs.back() << endl;
  } else {
    cout << A[N - 1] - A[0] << endl;
  }

  return 0;
}