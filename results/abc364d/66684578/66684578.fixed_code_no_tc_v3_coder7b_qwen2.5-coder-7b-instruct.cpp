#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long

int big = 100000004;

// Function to find the k-th closest point
int findKthClosest(vector<int>& A, int B, int k) {
    vector<int> distances(A.size());
    rep(i, A.size()) {
        distances[i] = abs(A[i] - B);
    }
    sort(distances.begin(), distances.end());
    return distances[k - 1];
}

int main() {
    int n, q;
    cin >> n >> q;
    vi A(n);
    rep(i, n) {
        cin >> A[i];
    }

    rep(i, q) {
        int B, k;
        cin >> B >> k;
        int result = findKthClosest(A, B, k);
        cout << result << endl;
    }
    return 0;
}