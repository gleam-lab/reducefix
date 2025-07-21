#include <bits/stdc++.h>
using namespace std;
int n, x[200050], p[200050], q;
int a[200050]; // 假设a数组已经根据p数组计算好前缀和

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i]; // 读取x数组的值
    for (int i = 1; i <= n; ++i) {
        cin >> p[i]; // 读取p数组的值，此处假定p是某个计算条件
        a[i] = a[i - 1] + p[i]; // 计算前缀和a数组（p可以按实际需要更改）
    }
    cin >> q; // 读取查询次数q
    for (int i = 0; i < q; ++i) { // 对每个查询进行处理
        int l, r; cin >> l >> r; // 读取每个查询的l和r范围
        // 使用二分查找确定l在x数组中的位置（注意是找第一个大于等于l的位置）
        int l_index = lower_bound(x + 1, x + n + 1, l) - x;
        // 同样地，找到r在x数组中的位置（找第一个大于等于r的位置）
        int r_index = lower_bound(x + 1, x + n + 1, r) - x;
        // 因为二分查找返回的是大于等于搜索值的第一个位置，所以这里实际上找到的是包含范围的最后一个元素的下一个位置
        // 我们需要修正索引来获得实际的范围长度，同时处理数组下标从1开始的情形
        r_index--; // 因为x数组是从1开始的，所以需要减1来得到正确的下标
        if (r_index == 0) { // 如果r不在x中，则直接跳过这个查询或处理为0（根据实际需求）
            continue; // 或者可以输出0或其他默认值
        }
        // 因为a数组是前缀和数组，所以直接使用l_index和r_index对应的值计算结果即可
        cout << a[r_index] - a[l_index] << endl; // 输出结果（注意这里不需要-1）
    }
    return 0;
}