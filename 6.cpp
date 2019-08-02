/*************************************************************************
	> File Name: 5.cpp
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年08月02日 星期五 14时52分05秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int sum1 = 0,sum2 = 0;
    sum1 = (1 + 100) * 100 / 2;
    sum2 = (2 * pow(100, 3) + 3 * pow(100, 2) + 100) / 6;
    cout << sum1 * sum1 - sum2; 

    return 0;
}
