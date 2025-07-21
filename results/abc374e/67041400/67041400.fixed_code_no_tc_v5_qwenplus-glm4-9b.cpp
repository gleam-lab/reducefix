#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ä¸ãããã W ãéæããã®ã«ãªæå°ã³ã¹ãï¼äºç® X ããããæ©æãªã¿ã¼ã³ï¼
// æ»ãå¤ã X+1 ä»¥ä¸ãªããä¸å¯è½ãã¨ã¿ãªã
ll cost_for_W(int N, ll W, ll X,
    const vector<ll>& A, const vector<ll>& P,
    const vector<ll>& B, const vector<ll>& Q)
{
    ll total = 0;
    for(int i = 0; i < N; i++){
        // åå·¥ç¨ i ã§è½å W ãéæããæå°ã³ã¹ã
        ll best = X + 1;

        // åè£ã¨ãªã x ã®éåãåæ
        vector<ll> xs;
        xs.push_back(0);
        xs.push_back((W + A[i] - 1) / A[i]);  //ã¦ Si
        // é£ç¶ç·©åããã®æé© x*
        long double x_star = (long double)W * Q[i] / ( (long double)A[i]*Q[i] + (long double)B[i]*P[i] );
        ll xf = floor(x_star), xc = ceil(x_star);
        xs.push_back(xf-1);
        xs.push_back(xf);
        xs.push_back(xf+1);
        xs.push_back(xc);
        xs.push_back(xc+1);
        xs.push_back((W + B[i] - 1) / B[i]);  //ã¦ Ti ããxãã¨ãã¦æ±ãï¼Sã¯0å°ï¼

        // éè¤åé¤ãã¦æå¹ç¯å²ã ã
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        ll max_x = (W + A[i] - 1) / A[i];
        for(ll x: xs){
            if(x < 0 || x > max_x) continue;
            // y ãæä½é
            ll rem = W - A[i]*x;
            ll y = rem <= 0 ? 0 : (rem + B[i] - 1) / B[i];
            ll c = P[i]*x + Q[i]*y;
            if(c < best) best = c;
        }

        total += best;
        if(total > X) return X+1;  // ããä»¥ä¸ã¯ã ãª
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

    // äºåæ¢ç´¢ã®ä¸ä¸é
    // ä¸é W_hi ã¯ãäºç®ãã¹ã¦ãæãå¹çã®è¯ããã·ã³ã«ä½¿ã£ãã¨ãã®è¦ç©ãã
    long double best_ratio = 0;
    for(int i = 0; i < N; i++){
        best_ratio = max(best_ratio, (long double)A[i] / P[i]);
        best_ratio = max(best_ratio, (long double)B[i] / Q[i]);
    }
    ll lo = 0, hi = (ll)floor(X * best_ratio) + 1;

    // [lo, hi) äºåæ¢ç´¢
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