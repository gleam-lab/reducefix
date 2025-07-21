#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef struct {
    ll a;
    int idx;
} node;

node A[200000];
ll psum[200001];
ll K;
int N, M;

bool is_possible(ll x, int i) {
    ll target = A[i].a + x;
    int idx = upper_bound(A, A+N, node{target, -1}, [](node a, node b){ return a.a < b.a; }) - A;
    int l = N - M;
    if (i >= l) l--;
    if (idx <= l) return false;
    ll required = (idx - l) * (target + 1) - (psum[idx] - psum[l]);
    if (i > l) required -= (target + 1 - A[i].a);
    return required <= (K - x);
}

int main() {
    scanf("%d %d %lld", &N, &M, &K);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i].a);
        A[i].idx = i;
    }
    sort(A, A+N, [](node a, node b){ return a.a < b.a; });
    psum[0] = 0;
    for (int i = 1; i <= N; i++) {
        psum[i] = psum[i-1] + A[i-1].a;
    }
    ll remaining = K - psum[N];
    vector<ll> result(N, -1);
    for (int i = 0; i < N; i++) {
        ll lo = 0, hi = remaining;
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
        if (ans != -1) {
            result[A[i].idx] = ans;
        } else if (is_possible(0, i)) {
            result[A[i].idx] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%lld ", result[i]);
    }
    printf("\n");
    return 0;
}