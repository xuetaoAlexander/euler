/*************************************************************************
	> File Name: 12.sum.cpp
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年08月15日 星期四 21时39分00秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
#define max_n 100

int prime[max_n + 5] = {0};
int factor[max_n + 5] = {0};
int sum[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; ++i) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            factor[i] = 2;
            sum[i] = i + 1;
        }

        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                int a = i, cnt = 0;
                while (a % prime[j] == 0) a /= prime[j], cnt++;
                factor[i * prime[j]] = factor[i] / (cnt + 1) * (cnt + 2);
                sum[i * prime[j]] = ((int)pow(prime[j], cnt + 2) - 1) * sum[i] / ((int)pow(prime[j], cnt + 1) - 1);
                break;
            } else {
                factor[i * prime[j]] = factor[i] * factor[prime[j]];
                sum[i * prime[j]] = sum[i] * (prime[j] + 1);
            }

        }
    }

}
int main(){
    init();
    for (int i = 2; i <= max_n; ++i) {
        cout << "i = " << i << " factor = " << factor[i] << endl;
        cout << "i = " << i << " sum = " << sum[i] << endl;

    }
    

    return 0;
}
