#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vl a(n), b(q);
    rep(i, n) cin >> a[i];
    rep(j, q) cin >> b[j] >> a[j]; // Overwrite a with b for sorting
    
    sort(a.begin(), a.end());
    
    rep(j, q) {
        int k = a[j];
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (a[mid] == k) {
                cout << a[mid] << '\n';
                break;
            } else if (a[mid] > k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }
    
    return 0;
}