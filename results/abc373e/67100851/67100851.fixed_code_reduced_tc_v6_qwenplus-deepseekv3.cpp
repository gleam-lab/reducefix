#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

struct candidate {
    ll a;
    int idx;
};

bool compare_a(const candidate &x, const candidate &y) {
    return x.a < y.a;
}

bool compare_idx(const candidate &x, const candidate &y) {
    return x.idx < y.idx;
}

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<candidate> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].a;
        A[i].idx = i;
    }
    sort(A.begin(), A.end(), compare_a);
    
    vector<ll> prefix_sum(N + 1);
    prefix_sum[0] = 0;
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + A[i].a;
    }
    ll remaining = K - prefix_sum[N];
    
    vector<ll> res(N);
    for (int i = 0; i < N; ++i) {
        ll low = 0;
        ll high = remaining;
        ll ans = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = A[i].a + mid;
            int pos = upper_bound(A.begin(), A.end(), candidate{new_votes, -1}, compare_a) - A.begin();
            int better = N - pos;
            if (better < M) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
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