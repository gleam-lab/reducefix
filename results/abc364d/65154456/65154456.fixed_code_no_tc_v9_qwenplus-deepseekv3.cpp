#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        int left = 0, right = N - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (a[mid] < b) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int pos = left;
        int low = max(0, pos - k);
        int high = min(N - 1, pos + k - 1);
        vector<ll> temp;
        for (int i = low; i <= high; ++i) {
            temp.push_back(abs(a[i] - b));
        }
        sort(temp.begin(), temp.end());
        cout << temp[k - 1] << endl;
    }

    return 0;
}