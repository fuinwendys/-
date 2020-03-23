//
// Created by zhengwei.
//
/*

����: �ƽ�������


    �ƽ�ָ���0.61803... �Ǹ����������������ʮ����Ҫ������๤�������л���֡���ʱ��Ҫ�����������úܾ�ȷ��

    ����ĳЩ���ܹ��̣������ľ��Ⱥ���Ҫ��Ҳ������˵������̫����Զ�������״����պ�ͷ�����һ���˹��ӹ�����
    ������һ����Ȼ�����ʵֻ�Ǿ���ӹ�ʱ�б�ͷ��˿��ϸ��౶��һ��������ѣ�ȴʹ�����ˡ������ۡ�!!


    �Թ����������������ûƽ�ָ����ľ����ܾ�ȷ��ֵ�أ�����෽����

    �Ƚϼ򵥵�һ��������������

                  1
    �ƽ��� = ---------------------
                        1
             1 + -----------------
                          1
                 1 + -------------
                            1
                     1 + ---------
                          1 + ...



    �������������ġ�������Խ�࣬����ֵԽ�ӽ��ƽ�ָ�����

    ����������һ���ԣ�����ƽ�ָ������㹻��ȷֵ��Ҫ���������뵽С�����100λ��

    С�����3λ��ֵΪ��0.618
    С�����4λ��ֵΪ��0.6180
    С�����5λ��ֵΪ��0.61803
    С�����7λ��ֵΪ��0.6180340
   ��ע��β����0�����ܺ��ԣ�

��������ǣ�д����ȷ��С�����100λ���ȵĻƽ�ָ�ֵ��

ע�⣺β�����������룡 β����0ҲҪ������

��Ȼ����һ��С������С�������100λ���֣���ͨ�������ֱ���ύ�����֡�
ע�⣺��Ҫ�ύ�����̣�����������˵��������ݡ�

 */

/*1��תΪ��쳲��������е�n��n+1��
 * 2��nȡ���٣�������n��С������101λû�б仯
 * 3��������c���Զ����������ֱ�����㣬��Ҫ�ֹ���д�����ӷ��ͳ�����������*/
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int n = 450;


void i2s(int num, string &str) {
    stringstream ss;
    ss << num;
    ss >> str;
}

string add(string a, string b) {
    a = a.substr(a.find_first_not_of('0'));
    b = b.substr(b.find_first_not_of('0'));
    long long lenA = a.length();
    long long lenB = b.length();
    long long len = max(lenA, lenB) + 10;
//��ת�����ڴӵ�λ�����
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string ans(len, '0');//��ʼ����Ϊlen����ȫ��Ϊ�ַ�0
//    ��a������ans��
    for (int i = 0; i < lenA; ++i) {
        ans[i] = a[i];
    }
    int tmp = 0;//tmp����һλ��Ӻ�Ľ�λ
    for (int i = 0; i < len; ++i) {
        if (i < b.length())
            tmp += (ans[i] - '0') + (b[i] - '0');//����Ϊ18
        else
            tmp += (ans[i] - '0');
        ans[i] = tmp % 10 + '0';//8 8+'0'
        tmp /= 10;//1
    }
    reverse(ans.begin(), ans.end());
    return ans.substr(ans.find_first_not_of('0'));
}

int cmp(string a, string b) {
    unsigned long i1 = a.find_first_not_of('0');
    if (i1 == string::npos)a = '0';
    else a.substr(i1);

    unsigned long i2 = b.find_first_not_of('0');
    if (i2 == string::npos)b = '0';
    else b.substr(i2);

    if (a.length() > b.length())return 1;
    else if (a.length() < b.length())return -1;
    else {//�������
        if (a < b)return -1;
        if (a > b)return 1;
        else return 0;
    }
}

//�˴���aһ�����ڵ���b
string subtract(string a, string b) {
//    �����ļ������棬a����С��b����ʱ���Ϊ����������ab��������Ĵ���
//    1.��ת
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
//    2.��λ������
    for (int i = 0; i < b.length(); ++i) {
        if (a[i] >= b[i]) {
            a[i] = a[i] - b[i] + '0';
        } else {//��Ҫ��
            int k = 1;
            while (a[i + k] == '0') {
                a[i + k] = '9';
                k++;
            }
//            ������Ա�֤i+k��һλ�ϲ���0
            a[i + k] = a[i + k] - '1' + '0';

            a[i] = (a[i] - '0' + 10) - (b[i] - '0') + '0';
        }
    }

    reverse(a.begin(), a.end());
    if (a.find_first_not_of('0') == string::npos)return "0";
    return a.substr(a.find_first_not_of('0'));
}

/*ת���ɼ���*/
string divide(string a, string b) {
//    ֻ����a<b�����
    string ans = "0.";
//    ת���ɼ���
    for (int i = 0; i < 101; ++i) {//101��
        a.append("0");
        int t = 0;
        while (cmp(a, b) >= 0) {//a>=b
            a = subtract(a, b);//��ͣ��������
            t++;//��¼�������˶��ٴ�
        }
        string t_str;
        i2s(t, t_str);
        ans.append(t_str);
    }
    return ans;
}

int main(int argc, const char *argv[]) {
    string a = "1";
    string b = "1";
    cout << subtract(a, b) << endl;
    for (int i = 3; i <= n; ++i) {
        string tmp = b;
        b = add(a, b);
        a = tmp;
//        cout << b << " " << endl;
    }
//    a b��쳲�������n-1��n��
    string ans = divide(a, b);
    cout << ans << endl;
    cout << ans.length()-2 << endl;
    return 0;
}




