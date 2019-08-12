/*************************************************************************
	> File Name: 25.cpp
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年08月12日 星期一 11时21分32秒
 ************************************************************************/

#include<iostream>
using namespace std;

int fib[3][1005] = {{0, 0}, {1, 1}, {1, 1}};

int main() {
    int n = 2;
    while (fib[n % 3][0] < 1000) {
        n += 1;
        for (int i = 1; i <= fib[(n - 1) % 3][0]; ++i) {
            fib[n % 3][i] = fib[(n - 1) % 3][i] + fib[(n - 2) % 3][i];
        }
        fib[n % 3][0] = fib[(n - 1) % 3][0];

        for (int i = 1; i <= fib[n % 3][0]; ++i) {
            if (fib[n % 3][i] < 10) continue;
            fib[n % 3][i + 1] += fib[n % 3][i] / 10;
            fib[n % 3][i] %= 10;
            fib[n % 3][0] += (i == fib[n % 3][0]);
        }
    }
    cout << n << endl;

    return 0;
}
