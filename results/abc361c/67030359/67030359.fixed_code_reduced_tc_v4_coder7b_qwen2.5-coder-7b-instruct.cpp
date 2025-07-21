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
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  sort(all(A));

  ll min_range = LLONG_MAX;
  for (int i = 0; i <= K; ++i) {
    int j = i + (N - K);
    min_range = min(min_range, static_cast<ll>(A[j - 1]) - A[i]);
  }

  cout << min_range << endl;
  return 0;
}