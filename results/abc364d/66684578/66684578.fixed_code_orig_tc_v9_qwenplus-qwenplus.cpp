#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define all(a) a.begin(),a.end()
#define INF (1<<29)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    vi A(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    sort(all(A));

    while(Q--){
        int b, k;
        cin >> b >> k;

        // Binary search on answer distance
        int low = 0, high = 2e8 + 10;
        while(low < high){
            int mid = (low + high) / 2;

            // Find left and right bounds in A where b - mid <= A[i] <= b + mid
            int left = lower_bound(all(A), b - mid) - A.begin();
            int right = upper_bound(all(A), b + mid) - A.begin();
            int count = right - left;

            if(count >= k){
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        cout << low << "\n";
    }

    return 0;
}