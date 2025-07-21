#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N), b(N - 1);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> b[i];
    }

    // Sort toys and boxes in ascending order
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Initialize variables
    bool placed[N] = {false};
    int boxIndex = 0;

    // Try to place each toy in the smallest possible box
    for (int i = 0; i < N; i++) {
        while (boxIndex < N - 1 && a[i] > b[boxIndex]) {
            boxIndex++;
        }
        if (boxIndex >= N - 1) {
            // If we run out of boxes, we need a larger box
            cout << max(a.back(), b.back()) + 1 << endl;
            return;
        }
        placed[boxIndex] = true;
        boxIndex++;
    }

    // Find the maximum box used
    int maxBox = *max_element(b.begin(), b.end());
    for (int i = 0; i < N - 1; i++) {
        if (!placed[i]) {
            maxBox = max(maxBox, b[i]);
        }
    }

    cout << maxBox << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}