#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pi 2*acos(0.0)
#define pb push_back
#define pf push_front
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define ff first
#define ss second 
#define mod 1e9+7
#define inf INT_MAX
#define all(v) v.begin(), v.end()
#define revs(v) sort(v.rbegin(),v.rend())
#define rev(v) reverse(v.begin(),v.end())
#define distmax(a) distance(a.begin(),max_element(all(a)))
#define distmin(a) distance(a.begin(),min_element(all(a)))
#define mem(a,b) memset(a, b, sizeof(a))
#define gcd(a,b) __gcd(a, b)
#define lcm(a, b) ((a / __gcd(a, b) ) * b)
#define sqr(x) (x*x)
#define rep(i,x) for(int i=0;i<(int)(x);i++)
#define repn(i,x) for(int i=1;i<=(int)(x);i++)
#define repo(i,x) for(int i=x-1;i>=0;i--)
#define sp(i) fixed<<setprecision(i)
#define l1s(n) __builtin_popcount(n)
#define ll1s(x) __builtin_popcountll(x)
#define permute(v) next_permutation(all(v))
#define int long long

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void Case(int t) { cout << "Case " << t << ": "; }
int countDigit(ll n, int base) { return floor(log(n) / log(base) + 1); }

void solve(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We need to find the minimum possible value of max(B) - min(B), where B is formed by deleting exactly K elements
    // So we can keep (N - K) elements.
    // Let's try to maintain a sliding window of size (N - K) and find the minimum difference between max and min in each such window.

    deque<int> maxDq, minDq;
    int res = numeric_limits<int>::max();

    for(int i = 0; i < N; ++i) {
        // Remove out of window elements
        while (!maxDq.empty() && maxDq.front() <= i - (N - K)) maxDq.pop_front();
        while (!minDq.empty() && minDq.front() <= i - (N - K)) minDq.pop_front();

        // Maintain max deque (decreasing order)
        while (!maxDq.empty() && A[maxDq.back()] <= A[i]) maxDq.pop_back();
        maxDq.push_back(i);

        // Maintain min deque (increasing order)
        while (!minDq.empty() && A[minDq.back()] >= A[i]) minDq.pop_back();
        minDq.push_back(i);

        // Once we have the window of size (N-K), compute the diff
        if (i >= (N - K - 1)) {
            res = min(res, A[maxDq.front()] - A[minDq.front()]);
        }
    }

    cout << res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}