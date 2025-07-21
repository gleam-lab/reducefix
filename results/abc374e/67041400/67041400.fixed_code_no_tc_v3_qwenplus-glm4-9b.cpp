#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cost_for_W(int N, ll W, ll X,
    const vector<ll>& A, const vector<ll>& P,
    const vector<ll>& B, const vector<ll>& Q)
{
    ll total = 0;
    for(int i = 0; i < N; i++){
        ll best = X + 1;

        vector<ll> xs;
        xs.push_back(0);
        xs.push_back((W + A[i] - 1) / A[i]);  //ã¦ Si
        long double x_star = (long double)W * Q[i] / ( (long double)A[i]*Q[i] + (long double)B[i]*P[i] );
        ll xf = floor(x_star);
        ll xc = ceil(x_star);
        xs.push_back(xf-1);
        xs.push_back(xf);
        xs.push_back(xf+1);
        xs.push_back(xc);
        xs.push_back(xc+1);
        xs.push_back((W + B[i] - 1) / B[i]);  //ã¦ Ti ããxãã¨ãã¦æ±ãï¼Sã¯0å°ï¼

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        ll max_x = (W + A[i] - 1) / A[i];
        for(ll x: xs){
            if(x < 0 || x > max_x) continue;
            ll rem = W - A[i]*x;
            ll y = rem <= 0 ? 0 : (rem + B[i] - 1) / B[i];
            ll c = P[i]*x + Q[i]*y;
            if(c < best) best = c;
        }

        total += best;
        if(total > X) return X + 1;  // ããä»¥ä¸ã¯ã ãª
    }
    return total;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    ll lo = 0, hi = X + 1;

    while(lo + 1 < hi){
        ll mid = lo + (hi - lo) / 2;
        if(cost_for_W(N, mid, X, A, P, B, Q) <= X){
            lo = mid;  // mid ãå¯è½
        } else {
            hi = mid;
        }
    }

    cout << lo << "\n";
    return 0;
}