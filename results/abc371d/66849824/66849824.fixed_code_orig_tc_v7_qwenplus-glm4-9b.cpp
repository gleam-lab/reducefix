#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define lower_bound(m, x) (m).lower_bound(x).base()
#define upper_bound(m, x) (m).upper_bound(x).base()

int main(){
    int N;
    cin >> N;
    vector<long long> P(N+1, 0); // Initialize with 0 for all positions
    vector<int> X(N);
    rep(i, N) cin >> X[i];
    rep(i, N) cin >> P[i+1]; // Read next position sum based on previous sum

    map<int, int> x_to_ptr;
    rep(i, N) x_to_ptr.emplace(X[i], i);

    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        auto X_l = lower_bound(x_to_ptr, L);
        auto X_r = upper_bound(x_to_ptr, R);
        int l = *X_l - x_to_ptr.begin();
        int r = *X_r - x_to_ptr.begin() - 1;
        cout << P[r] - P[l] << endl;
    }
}