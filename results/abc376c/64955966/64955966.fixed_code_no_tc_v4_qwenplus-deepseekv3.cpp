#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> A(N), B(N-1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N-1; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll low = 1, high = 1e18;
    ll answer = -1;

    while (low <= high) {
        ll mid = (low + high) / 2;
        vector<ll> boxes = B;
        boxes.push_back(mid);
        sort(boxes.begin(), boxes.end());

        bool possible = true;
        int toy_ptr = 0;
        for (int box_ptr = 0; box_ptr < boxes.size() && toy_ptr < A.size(); box_ptr++) {
            if (boxes[box_ptr] >= A[toy_ptr]) {
                toy_ptr++;
            }
        }

        if (toy_ptr == A.size()) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << '\n';

    return 0;
}