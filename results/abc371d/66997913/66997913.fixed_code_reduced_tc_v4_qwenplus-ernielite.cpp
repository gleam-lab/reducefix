#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  vector<ll> p(n), s(n + 1, 0); // 初始化 s 数组为 0，确保每个元素都是 0 而不是未定义值
  for (int i = 1; i <= n; i++) { // 从 1 开始循环以避免偏移问题
    p[i-1] = s[i] - s[i-1]; // 计算累积和 p[i-1] = s[i] - s[i-1]
    s[i] = s[i-1] + p[i-1]; // 更新 s 数组以包含累积和
  }
  
  int q;
  cin >> q;
  while (q--) { // 使用 while 循环代替 for 循环以处理多个查询
    int l, r;
    cin >> l >> r;
    // 确保 l 和 r 不越界，并转换为基于 0 的索引
    int lt = l == 0 ? 0 : lower_bound(x.begin(), x.end(), l) - x.begin();
    int rt = r == n ? n : upper_bound(x.begin(), x.end(), r) - x.begin() - 1; // 注意这里减去了 1 因为 upper_bound 会指向大于 r 的第一个元素的位置
    // 如果 r 不在数组中，则使用下一个元素的位置作为索引（即减一）
    ll ans = s[rt] - s[lt]; // 计算累积和的差值作为答案
    cout << ans << endl; // 输出答案
  }
  return 0;
}