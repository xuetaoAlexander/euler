/*************************************************************************
	> File Name: 31.cpp
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年08月09日 星期五 21时33分19秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_m 8
#define max_n 200
//f(x, y) = f(x - 1, y) + f(x, y - w[i])
int w[9] = {0, 1, 2, 5, 10, 20, 50, 100, 200};
int f[max_m + 5][max_n + 5];

int main() {
    for (int i = 1; i <= max_m; i++) {
        f[i][0] = 1;
        for (int j = 0; j <= max_n; ++j) {
            if (i - 1 >= 1) f[i][j] = f[i - 1][j];
            if (j - w[i] >= 0) f[i][j] += f[i][j - w[i]];
        }
    }

    printf("%d\n", f[1][1]);
    printf("%d\n", f[8][200]);

    return 0;
}
