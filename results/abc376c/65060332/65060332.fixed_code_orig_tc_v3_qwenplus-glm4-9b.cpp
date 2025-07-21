#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;
ll a[N], b[N];

ll binary_search(ll low, ll high, vector<ll> &arr, ll num) {
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (arr[mid] == num)
            return mid;
        else if (arr[mid] < num)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

ll find_min_box_size() {
    vector<ll> sorted_box_sizes;
    for (ll i = 0; i < N - 1; ++i) {
        sorted_box_sizes.push_back(b[i]);
    }
    sort(sorted_box_sizes.begin(), sorted_box_sizes.end());

    ll required_box_size = 0;
    for (ll i = 0; i < N; ++i) {
        ll toy_size = a[i];
        ll box_index = binary_search(0, N - 2, sorted_box_sizes, toy_size);
        if (box_index == N - 1) { // No box can fit the toy
            required_box_size = toy_size;
            break;
        } else {
            required_box_size = sorted_box_sizes[box_index];
        }
    }

    return required_box_size;
}

int main() {
    ll n;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    ll min_box_size = find_min_box_size();
    cout << min_box_size << endl;

    return 0;
}