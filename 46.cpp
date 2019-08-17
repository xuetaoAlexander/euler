/*************************************************************************
	> File Name: 46.cpp
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年08月16日 星期五 18时56分09秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 100000
int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};

void init() { // 线性筛
    for (int i = 2; i <= max_n; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int func(int n) {
    return 2 * n * n;
}

bool binary_search(int (*f)(int), int l , int r, int x) { // 函数作为参数的传递方式
    int mid = (l + r) / 2;
    if (l > r) return false;
    if (f(mid) == x) return true;
    if (f(mid) > x) r = mid - 1;
    else l = mid + 1;
    return binary_search(f, l, r, x); //递归形式的二分查找
}

int is_val(int x) {
    for (int i = 1; i <= prime[0] && prime[i] < x; i++) { // 判断条件放在循环内部，使代码更简洁
        int val = x - prime[i];
        if (binary_search(func, 1, val, val)) return true;
    }
    return false;
}

int main() {
    init();
    for (int i = 9; i <= max_n; i += 2) {
        if (!is_prime[i]) continue;
        if (is_val(i)) continue;
        cout << i << endl;
        break;
    }

    return 0;
}
