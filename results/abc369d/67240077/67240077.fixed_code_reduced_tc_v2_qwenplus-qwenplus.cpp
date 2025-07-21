#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;

ll a[MAXN], f[MAXN][2];
ll cnt_even[MAXN][2], cnt_odd[MAXN][2];

int main(){
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }

    // Initialize base cases
    f[0][0] = 0; // Not taking the previous element
    f[0][1] = 0; // Taking the previous element (but none exist yet)
    cnt_even[0][0] = 0; // Count of even-length selection when not taking previous at step 0
    cnt_odd[0][0] = 0;  // Count of odd-length selection when not taking previous at step 0
    cnt_even[0][1] = 0; // Same for taking previous
    cnt_odd[0][1] = 0;

    for(ll i=1;i<=n;i++){
        // Case 0: Don't take current element
        f[i][0] = max(f[i-1][0], f[i-1][1]);

        if(f[i-1][0] > f[i-1][1]){
            cnt_even[i][0] = cnt_even[i-1][0];
            cnt_odd[i][0] = cnt_odd[i-1][0];
        } else {
            cnt_even[i][0] = cnt_even[i-1][1];
            cnt_odd[i][0] = cnt_odd[i-1][1];
        }

        // Case 1: Take current element
        ll val1 = f[i-1][0] + a[i]; // Previous was not taken -> new sequence starts, length is 1 (odd)
        ll val2 = f[i-1][1]; // Previous was taken
        ll new_len = cnt_even[i-1][1] + cnt_odd[i-1][1] + 1;
        if(new_len % 2 == 1){
            val2 += a[i]; // Odd length -> normal value
        } else {
            val2 += 2 * a[i]; // Even length -> doubled value
        }

        if(val1 > val2){
            f[i][1] = val1;
            cnt_odd[i][1] = cnt_odd[i-1][0] + 1;
            cnt_even[i][1] = cnt_even[i-1][0];
        } else {
            f[i][1] = val2;
            cnt_odd[i][1] = cnt_odd[i-1][1];
            cnt_even[i][1] = cnt_even[i-1][1];
            if(new_len % 2 == 1){
                cnt_odd[i][1] += 1;
            } else {
                cnt_even[i][1] += 1;
            }
        }
    }

    printf("%lld", max(f[n][0], f[n][1]));
    return 0;
}