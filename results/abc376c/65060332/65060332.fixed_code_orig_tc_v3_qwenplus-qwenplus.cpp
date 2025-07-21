#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2e5 + 5;

ll a[MAXN], b[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N - 1; ++i) cin >> b[i];

    sort(a, a + N);
    sort(b, b + N - 1);

    // We need to assign each toy to either a box or the additional one new box
    // Try to match largest toys with largest boxes greedily

    int i = N - 1, j = N - 2;
    while (i >= 0 && j >= 0) {
        if (b[j] >= a[i]) {
            --i;
            --j;
        } else {
            // Need to put this toy in the extra box
            --i;
        }
    }

    if (i == -1) {
        cout << a[N - 1] << "\n"; // Already sorted
        return 0;
    }

    if (i > 0) {
        // More than one toy left and no more boxes available => impossible
        cout << -1 << "\n";
        return 0;
    }

    // Exactly one toy left and we can buy one box for it
    cout << a[i] << "\n";
    return 0;
}