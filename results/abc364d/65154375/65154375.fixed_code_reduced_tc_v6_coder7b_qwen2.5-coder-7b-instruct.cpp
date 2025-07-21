#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 100005;

vector<ll> A[MAXN];
ll B[MAXN], K[MAXN];
vector<ll> dists[MAXN];

void preprocess() {
    for(int i = 0; i < MAXN; ++i) {
        A[i].clear();
        dists[i].clear();
    }
}

void add_point(ll a, int idx) {
    A[idx].push_back(a);
}

void process_queries(int n, int q) {
    for(int i = 0; i < n; ++i) {
        sort(A[i].begin(), A[i].end());
        for(int j = 0; j < q; ++j) {
            if(B[j] == A[i][0]) {
                dists[j].push_back(0);
            } else {
                auto it = lower_bound(A[i].begin(), A[i].end(), B[j]);
                int pos = it - A[i].begin();
                if(pos == 0) {
                    dists[j].push_back(abs(A[i][pos] - B[j]));
                } else if(pos == A[i].size()) {
                    dists[j].push_back(abs(A[i][pos - 1] - B[j]));
                } else {
                    dists[j].push_back(min(abs(A[i][pos] - B[j]), abs(A[i][pos - 1] - B[j])));
                }
            }
        }
    }

    for(int j = 0; j < q; ++j) {
        sort(dists[j].begin(), dists[j].end());
    }
}

void query(int q) {
    for(int j = 0; j < q; ++j) {
        int result = dists[j][K[j] - 1];
        cout << result << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    preprocess();

    for(int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        add_point(a, i);
    }

    for(int i = 0; i < q; ++i) {
        cin >> B[i] >> K[i];
    }

    process_queries(n, q);
    query(q);

    return 0;
}