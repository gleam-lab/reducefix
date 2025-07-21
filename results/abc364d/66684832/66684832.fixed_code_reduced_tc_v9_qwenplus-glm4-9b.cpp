#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2e5 + 9;
int a[N], b[N], k[N];
vector<int> distances[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= q; ++i) {
        cin >> b[i] >> k[i];
        distances[b[i]].push_back(k[i]);
    }

    for (int i = 1; i <= n; ++i) {
        sort(distances[i].begin(), distances[i].end());
    }

    for (int j = 1; j <= q; ++j) {
        int bj = b[j];
        int kj = k[j];
        int l = 0, r = n;
        int answer = 0;

        while (l < r) {
            int m = (l + r + 1) / 2;
            if (distances[bj][kj - 1] < a[m]) {
                l = m;
            } else {
                r = m - 1;
            }
        }

        if (l > 0 && distances[bj][kj - 1] < a[l]) {
            answer = a[l] - distances[bj][kj - 1];
        } else {
            if (l < n) {
                answer = a[l + 1] - distances[bj][kj - 1];
            }
        }

        cout << answer << '\n';
    }

    return 0;
}