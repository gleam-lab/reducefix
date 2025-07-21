#include <bits/stdc++.h>

#define endl '\n'
#define lowbit(x) (x & (-x))

using namespace std;

typedef long long ll;

const int MAXN = 100005;
int N, Q;
vector<int> A, B, K;

vector<int> dists;

bool check(int mid, int k) {
    int cnt = 0;
    for (int d : dists) {
        if (d <= mid) cnt++;
        if (cnt >= k) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    A.resize(N);
    B.resize(Q);
    K.resize(Q);

    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < Q; ++i) cin >> B[i] >> K[i];

    sort(A.begin(), A.end());

    for (int b : B) {
        dists.clear();
        for (int a : A) {
            dists.push_back(abs(a - b));
        }

        int left = 0, right = 2e8;
        while (left < right) {
            int mid = (left + right) / 2;
            if (check(mid, K[i])) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        cout << left << endl;
    }

    return 0;
}