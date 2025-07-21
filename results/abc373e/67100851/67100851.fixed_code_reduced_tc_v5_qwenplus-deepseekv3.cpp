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

bool is_possible(int i, ll x) {
    ll total_votes = A[i].a + x;
    int pos = upper_bound(A.begin(), A.end(), node{total_votes, -1}, [](node a, node b) {
        return a.a < b.a;
    }) - A.begin();
    int l = N - M;
    if (pos <= l) {
        return false;
    }
    ll required = (pos - l) * total_votes - (psum[pos] - psum[l]);
    if (required <= K - x) {
        return true;
    }
    return false;
}

int main() {
    scanf("%d %d %lld", &N, &M, &K);
    A.resize(N);
    psum.resize(N + 1, 0);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i].a);
        A[i].idx = i;
    }
    sort(A.begin(), A.end(), [](node a, node b) {
        return a.a < b.a;
    });
    for (int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + A[i - 1].a;
    }
    K -= psum[N];
    vector<ll> ans(N, -1);
    for (int i = 0; i < N; i++) {
        ll lo = 0, hi = K;
        ll res = -1;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            if (is_possible(i, mid)) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        ans[A[i].idx] = res;
    }
    for (int i = 0; i < N; i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
    return 0;
}