#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 与えられた W を達成するのに必要な最小コスト（予算 X を超えたら早期リターン）
// 戻り値が X+1 なら「不可能」とみなす
ll cost_for_W(int N, ll W, ll X,
    const vector<ll>& A, const vector<ll>& P,
    const vector<ll>& B, const vector<ll>& Q)
{
    ll total = 0;
    for(int i = 0; i < N; i++){
        // 各工程 i で能力 W を達成する最小コスト
        ll best = X + 1;

        // 候補となる x の集合を列挙
        vector<ll> xs;
        xs.push_back(0);
        xs.push_back((W + A[i] - 1) / A[i]);  // 全て Si

        // 連続緩和からの最適 x*
        long double x_star = (long double)W * Q[i] / 
            (A[i]*Q[i] + B[i]*P[i]);
        ll xf = floor(x_star), xc = ceil(x_star);
        xs.push_back(xf-1);
        xs.push_back(xf);
        xs.push_back(xf+1);
        xs.push_back(xc);
        xs.push_back(xc+1);

        // Tiを使うケースも同様に考慮
        xs.push_back((W + B[i] - 1) / B[i]);

        // 重複削除して有効範囲だけ
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        ll max_x = (W + A[i] - 1) / A[i];
        for(ll x: xs){
            if(x < 0 || x > max_x) continue;

            // y を最低限
            ll rem = W - A[i]*x;
            ll y = rem <= 0 ? 0 : (rem + B[i] - 1) / B[i];
            ll c = P[i]*x + Q[i]*y;

            if(c < best) best = c;
        }

        // 追加：best が 0 の場合（=x=y=0）は不正なので不可とする
        if(best == 0) return X + 1;

        total += best;
        if(total > X) return X + 1;  // これ以上はムリ
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

    // 下限と上限の初期化
    ll lo = 0, hi = 0;

    // 上限 W_hi は、予算すべてを最も効率の良いマシンに使ったときの見積もり
    for(int i = 0; i < N; i++){
        // Si の性能/価格
        ll w1 = A[i] * X / P[i];
        // Ti の性能/価格
        ll w2 = B[i] * X / Q[i];
        hi = max({hi, w1, w2});
    }
    hi += 10;  // 少し余裕を持たせる

    // [lo, hi) 二分探索
    while(lo + 1 < hi){
        ll mid = lo + (hi - lo) / 2;
        if(cost_for_W(N, mid, X, A, P, B, Q) <= X){
            lo = mid;  // mid が可能
        } else {
            hi = mid;
        }
    }

    cout << lo << "\n";
    return 0;
}