#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, q;
int a[MAXN], b[MAXN];
int k[MAXN];

vector<int> dist[MAXN];

void preprocess() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < q; ++j) {
            dist[j].push_back(abs(a[i] - b[j]));
        }
    }
    for(int j = 0; j < q; ++j) {
        sort(dist[j].begin(), dist[j].end());
    }
}

int query(int j, int k_j) {
    return dist[j][k_j - 1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> q;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for(int j = 0; j < q; ++j) {
        cin >> b[j] >> k[j];
    }

    preprocess();

    for(int j = 0; j < q; ++j) {
        cout << query(j, k[j]) << '\n';
    }

    return 0;
}