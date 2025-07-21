#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N), boxes(N-1);
    
    // Reading input
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (ll i = 0; i < N-1; i++) {
        cin >> boxes[i];
    }
    
    // Sort the box sizes in descending order
    sort(boxes.rbegin(), boxes.rend());
    
    // Check if each toy can fit in any box
    for (ll i = 0; i < N; i++) {
        ll canFit = 0;
        for (ll j = 0; j < N-1; j++) {
            if (boxes[j] >= A[i]) {
                canFit = 1;
                break;
            }
        }
        if (!canFit) {
            cout << "-1" << endl;
            return 0;
        }
    }
    
    // The minimum size of the additional box is the size of the smallest box
    // that can fit all toys, which is the smallest box that can fit the
    // largest toy, as all the other toys will fit in the boxes that can
    // already fit the largest toy.
    cout << boxes[0] << endl;
    
    return 0;
}