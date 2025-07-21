#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 200005;

ll a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i < n; ++i) {
        cin >> b[i];
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n);

    // We will try to match the largest toys with boxes
    // Start from end of toy list and box list

    int toy_ptr = n;
    int box_ptr = n - 1;

    ll need_box_size = -1;

    while (toy_ptr >= 1 && box_ptr >= 1) {
        if (b[box_ptr] >= a[toy_ptr]) {
            // Box can fit this toy
            box_ptr--;
            toy_ptr--;
        } else {
            // Can't fit in current box, must be placed in new box
            if (need_box_size == -1) {
                need_box_size = a[toy_ptr];
            } else {
                // More than one toy needs the new box => impossible
                cout << -1 << endl;
                return 0;
            }
            toy_ptr--;
        }
    }

    // If some toys are left unmatched
    if (toy_ptr >= 1) {
        // All remaining toys must go in new box
        if (need_box_size == -1) {
            need_box_size = a[toy_ptr];
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << need_box_size << endl;
    return 0;
}