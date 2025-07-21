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
typedef long long int ll;
typedef pair<int,int> pi;
typedef queue<int> qi;
typedef queue<pi> qp;
typedef set<int> si;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
template<typename T> inline bool chmin(T &a, T b) {if (a > b) {a = b; return true;} return false;}
template<typename T> inline bool chmax(T &a, T b) {if (a < b) {a = b; return true;} return false;}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N, K; cin >> N >> K;
  vi A(N); for(int i=0;i<N;i++) cin >> A[i];
  sort(all(A));
  int l=0, r=N-K-1;
  cout << A[r+1] - A[l] << endl;
  return 0;
}