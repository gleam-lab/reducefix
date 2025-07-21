#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> toys(N), boxes(N-1);
    
    for (int i = 0; i < N; i++) {
        cin >> toys[i];
    }
    for (int i = 0; i < N-1; i++) {
        cin >> boxes[i];
    }

    // Sort both arrays to facilitate the comparison
    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());

    // We need to find the smallest box size that can accommodate all toys
    ll min_box_size = 0;
    for (int i = 0; i < N; i++) {
        // Update min_box_size considering the current toy and the previous box size
        min_box_size = max(min_box_size, toys[i]);
        if (i < N-1) {
            min_box_size = max(min_box_size, boxes[i]);
        }
    }

    // Output the result
    cout << min_box_size << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}