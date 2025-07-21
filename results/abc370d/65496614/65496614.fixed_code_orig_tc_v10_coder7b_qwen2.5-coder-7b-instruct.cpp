#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n) ; ++i)
#define rep1(i,n) for(int i = 1; i < (int)(n) ; ++i)
#define rrep(i,n) for(int i = (int)n-1; i >= 0 ; --i)
#define rrep1(i,n) for(int i = (int)n-1; i >= 1 ; --i)

using ll = long long;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;

using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvvb>;

using vs = vector<string>;

string filename = __FILE__;

//===============================================
//デバッグ用出力関数===============================
//===============================================

// コンテナ型かどうかの判定（begin/endがあるかで判定）
//is_containerはstd::false_typeを継承。::valueを通じてfalseを返す。
//デフォルトではコンテナ型なしと判定。
template<typename T, typename = void>
struct is_container : std::false_type {};


template<typename T>
struct is_container<
    T,
    //ヘルパー型。中のすべてのdecltypeが有効ならvoid型になる。
    //無効であればテンプレートの特殊化自体が除外(SFINAE発動)
    std::void_t<
        //右辺値を生成せずにメンバ関数を持っているか判定
        //decltype: 中の式の型を取得する
        //declval:  実体を生成せずに使う
        decltype(std::declval<T>().begin()),
        decltype(std::declval<T>().end())
    >
> : std::true_type {};



template<typename T>
void dbg(const T &i, bool linebreak = true){
    if(filename == "Main.cpp") return;

    cout << i;
    if(linebreak) cout << "\n";
    else cout << " ";
    return;
}

// double型専用処理（std::enable_ifを使う)
// enable_ifは中身がtrueの場合、voidを返す
// 中身がfalseの場合、enable_ifは無効化され、このテンプレート関数は選ばれない。
template<typename T>
typename std::enable_if<std::is_same<T, double>::value>::type
dbg(const T &i, bool linebreak = true){
    if(filename == "Main.cpp") return;

    printf("%.10lf", i);
    if(linebreak) cout << "\n";
    else cout << " ";
    return;
}

// string専用処理
template<typename T>
typename std::enable_if<std::is_same<T, string>::value>::type
dbg(const T &i, bool linebreak = true){
    if(filename == "Main.cpp") return;

    cout << i;
    if(linebreak) cout << "\n";
    else cout << " ";
    return;
}



template<typename T>
void dbg(const vector<T> &vec, bool linebreak = true){
    if(filename == "Main.cpp") return;

    for(const auto &val: vec) dbg(val, is_container<T>::value);
    cout << endl;
    return;
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, w, q;
    cin >> h >> w >> q;

    vvb coo(h+2, vb(w+2, true));
    set<pair<int, int>> walls;

    int r, c;

    auto erase_wall = [&](int i, int j){
        if(i*j == 0) return;
        walls.erase({i, j});
        coo[i][j] = false;
    };

    auto place_bomb = [&]() {
        for(auto [i, j]: walls) {
            erase_wall(i, j);
            if(i > 1 && coo[i-1][j]) erase_wall(i-1, j);
            if(i < h && coo[i+1][j]) erase_wall(i+1, j);
            if(j > 1 && coo[i][j-1]) erase_wall(i, j-1);
            if(j < w && coo[i][j+1]) erase_wall(i, j+1);
        }
    };

    while(q--){
        cin >> r >> c;
        --r, --c; // Convert to 0-indexed

        if(coo[r][c]){
            erase_wall(r, c);
            continue;
        }

        place_bomb();
    }

    int ans = 0;
    for(int i = 1; i <= h; ++i) 
        for(int j = 1; j <= w; ++j) 
            if(!coo[i][j]) ++ans;

    cout << ans << endl;
    return 0;
}