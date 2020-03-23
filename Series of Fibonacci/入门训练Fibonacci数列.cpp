/*
Fibonacci数列的递推公式为：Fn=Fn-1+Fn-2，其中F1=F2=1。
当n比较大时，Fn也非常大，现在我们想知道，Fn除以10007的余数是多少。
说明：在本题中，答案是要求Fn除以10007的余数，因此我们只要能算出这个余数即可，
而不需要先计算出Fn的准确值，再将计算的结果除以10007取余数，直接计算余数往往比先算出原数再取余简单。
*/
#include <iostream>
using namespace std;
const int N = 1000001;
int main() {
    int F[N];
    F[1] = F[2] = 1;
    for (int i = 3; i <= 1000000; i++) {
        F[i] = (F[i - 1] + F[i - 2]) % 10007;
    }
    int n;
    cin >> n;
    cout << F[n];
    return 0;
}
