#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef struct {
    ll a;
    int idx;
} node;

vector<node> A;
vector<ll> psum;
ll K;
int N, M;

bool is_possible(ll x, int i) {
    ll total_votes = A[i].a + x;
    int pos = upper_bound(A.begin(), A.end(), node{total_votes, -1}, 
        [](const node &a, const node &b) { return a.a < b.a; }) - A.begin();
    pos = N - pos;
    if (pos < M) {
        ll remaining = K - x;
        ll required = 0;
        int l = N - M;
        if (i >= l) {
            required = (total_votes + 1) * (l) - psum[l];
        } else {
            required = (total_votes + 1) * (l + 1) - (psum[l + 1] + x);
        }
        if (required <= remaining) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> N >> M >> K;
    A.resize(N);
    psum.resize(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].a;
        A[i].idx = i;
    }
    sort(A.begin(), A.end(), [](const node &a, const node &b) { return a.a < b.a; });
    for (int i = 1; i <= N; ++i) {
        psum[i] = psum[i - 1] + A[i - 1].a;
    }
    vector<ll> res(N);
    for (int i = 0; i < N; ++i) {
        ll lo = 0, hi = K;
        ll ans = -1;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            if (is_possible(mid, i)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        res[A[i].idx] = ans;
    }
    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}