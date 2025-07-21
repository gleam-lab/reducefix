#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n-1; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<ll> possible_x;
    // Check the case where the new box is x = a[n-1]
    {
        ll i = n-1, j = n-2;
        ll cnt = 0;
        while (i >= 0 && j >= 0) {
            if (a[i] <= b[j]) {
                i--; j--;
            } else {
                cnt++;
                i--;
            }
        }
        cnt += i + 1;
        if (cnt <= 1) {
            possible_x.push_back(a[n-1]);
        }
    }
    // Also check the case where the new box is x = a[n-2], etc.
    // Alternatively, find the minimal x in the unpaired toys.
    // Use binary search to find the minimal x.
    ll low = 1, high = 1e18;
    ll answer = -1;
    // We need to find if there's an x such that, when added to B, allows all toys to be matched.
    // The x must be >= one toy's A_i, and the number of toys that cannot be matched with B's boxes is <=1.
    // But the correct approach is to find the largest toy that cannot be matched with any B's boxes, and that's the minimal x.
    // So, first, sort A and B.
    // Then, pair the largest toys with largest B boxes.
    // The remaining toys (if any) must be <=1, and the x is the largest of them.
    ll i = n-1, j = n-2;
    ll cnt = 0;
    ll max_unpaired = -1;
    while (i >= 0 && j >= 0) {
        if (a[i] <= b[j]) {
            i--; j--;
        } else {
            cnt++;
            max_unpaired = max(max_unpaired, a[i]);
            i--;
        }
    }
    while (i >= 0) {
        cnt++;
        max_unpaired = max(max_unpaired, a[i]);
        i--;
    }
    if (cnt == 1) {
        answer = max_unpaired;
    } else if (cnt == 0) {
        // All toys are matched, but we have an extra box. The new box can be any size >= the smallest toy.
        answer = 1; // But the smallest box size is 1 (as per constraints), but the minimal x is the smallest A_i.
        answer = a[0];
    } else {
        answer = -1;
    }
    cout << answer << endl;
}

int main() {
    solve();
    return 0;
}