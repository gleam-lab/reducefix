#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N - 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    
    multiset<ll> boxes(B.begin(), B.end());
    vector<ll> unplaced;
    
    for (ll toy : A) {
        auto it = boxes.lower_bound(toy);
        if (it != boxes.end()) {
            boxes.erase(it);
        } else {
            unplaced.push_back(toy);
        }
    }
    
    if (unplaced.size() > 1) {
        cout << -1 << endl;
        return;
    } else if (unplaced.empty()) {
        // All toys are placed in existing boxes, x can be any value >=0, but since we need the smallest, x=0 or 1?
        // However, since x must be positive, the smallest x is 1 if all toys are placed, but the problem might not require placing in new box.
        // This case is ambiguous, but according to the problem statement, he wants to execute step 2 by purchasing a box, so x must be at least the size of one toy.
        // So the minimal x is the smallest A_i, but since all toys are placed, x can be any >=1 (but minimal is 1).
        // But the problem states boxes' sizes are >=1, so perhaps x can be 1.
        // However, if all toys are placed in existing boxes, perhaps x is not needed, but the problem requires purchasing one box.
        // So, in this case, the minimal x is the smallest possible, which is 1.
        cout << 1 << endl;
    } else {
        cout << unplaced[0] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}