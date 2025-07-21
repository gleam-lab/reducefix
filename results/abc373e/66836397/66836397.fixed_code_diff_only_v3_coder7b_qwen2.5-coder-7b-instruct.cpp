#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

typedef long long ll;

int main(){
    ll n, m, K;
    cin >> n >> m >> K;
    vector<ll> a(n);
    ll total_votes = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        total_votes += a[i];
    }
    vector<ll> A = a;
    sort(A.begin(), A.end());
    vector<ll> prefix_sum(n + 1, 0);
    for(int i = 0; i < n; i++){
        prefix_sum[i + 1] = prefix_sum[i] + A[i];
    }
    vector<ll> C(n, 0);
    for(int i = 0; i < n; i++){
        if(m - (n - (i + 1)) <= 0){
            C[i] = -1;
        }else{
            ll target = A[i] + 1;
            int left = 0, right = n - 1;
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(prefix_sum[mid + 1] >= target * (mid + 1)){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            if(right + 1 < n && A[right + 1] == target){
                C[i] = target - A[i];
            }else{
                C[i] = -1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << C[i] << " ";
    }
    cout << endl;
    return 0;
}