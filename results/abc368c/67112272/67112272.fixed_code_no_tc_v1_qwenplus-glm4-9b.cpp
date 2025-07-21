#include<bits/stdc++.h>
using namespace std;

#define rep(i,N) for(ll i = 0; i < N; ++i)
using ll = long long;

int main() {
    ll N; cin >> N;
    vector<ll> H(N);
    
    rep(i, N) {
        cin >> H[i];
    }
    
    ll T = 0;
    for (ll i = 0; i < N; ++i) {
        // Calculate the number of full attacks and the remainder for the current enemy
        ll full_attacks = H[i] / 3;
        ll remainder = H[i] % 3;
        
        // Add the number of full attacks to T. Since each full attack happens after every 3 increments of T,
        // we add the full attacks to the number of increments of T needed before the first full attack.
        // Each full attack also increments T by 1.
        T += full_attacks + (full_attacks - remainder);
        
        // If there's a remainder, it means we need one more attack, and since T must be a multiple of 3
        // before we can perform another full attack, we need to increment T by 2 more to reach the next multiple of 3.
        if (remainder > 0) {
            T += 2;
        }
    }
    
    // Output the total number of increments of T
    cout << T << endl;
}