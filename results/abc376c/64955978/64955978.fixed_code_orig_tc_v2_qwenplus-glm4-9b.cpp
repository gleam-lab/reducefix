#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;
    vector<ll> toys(N), boxes(N - 1);
    
    for (ll i = 0; i < N; i++) {
        cin >> toys[i];
    }
    for (ll i = 0; i < N - 1; i++) {
        cin >> boxes[i];
    }
    
    // Sort both toys and boxes in descending order
    sort(toys.begin(), toys.end(), greater<ll>());
    sort(boxes.begin(), boxes.end(), greater<ll>());
    
    ll minBoxSize = -1; // Initialize the minimum box size to -1 (impossible case)
    bool placed[N]; // Track if a toy has been placed
    
    for (ll i = 0; i < N; i++) {
        bool placedSuccessfully = false;
        
        for (ll j = 0; j < N - 1; j++) {
            if (toys[i] <= boxes[j]) {
                // If the toy can be placed in the current box
                if (!placed[j]) { // Check if the box has not been used already
                    placed[j] = true; // Mark the box as used
                    minBoxSize = boxes[j]; // Update the minimum box size
                    placedSuccessfully = true;
                    break;
                }
            }
        }
        
        if (!placedSuccessfully) {
            cout << -1 << endl; // If the toy cannot be placed in any box, output -1
            return 0;
        }
    }
    
    cout << minBoxSize << endl; // Output the minimum box size
    return 0;
}