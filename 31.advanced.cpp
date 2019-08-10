/*************************************************************************
	> File Name: 31.advanced.cpp
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年08月10日 星期六 18时59分59秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_m  8
#define max_n  200
// f(x, y) = f(x - 1, y) + f(x, y - w[x])
int w[max_m + 1] = {0, 1, 2, 5, 10, 20, 50, 100, 200};
int f[2][max_n + 5] = {0};

int main() {
    for (int k = 1; k <= max_m; ++k) {
        int i = k % 2;
        f[i][0] = 1;
        for (int j = 1; j <= max_n; ++j) {
            f[i][j] = f[i ^ 1][j];
            if (j - w[k] >= 0) f[i][j] += f[i][j - w[k]];
        }
    }
    cout << f[max_m % 2][max_n] << endl;

    return 0;
}
