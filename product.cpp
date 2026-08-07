#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <numeric>
using namespace std;


 long long gcd(long long a , long long b){
            while(b!=0){
                long long tem = b;
                b = a%b;
                a = tem;
            }
            return a;
        }

string smallestnumber(string s,long long t){
    long long temp = t;
        for (int i = 2; i <= 9; ++i) {
            while (temp % i == 0) temp /= i;
        }
        if (temp > 1) return "-1";

        
        int n = s.length();
        std::vector<long long> rem(n + 1, 0);
        rem[0] = t;
        int pos = n - 1;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                pos = i;
                break;
            }
            rem[i + 1] = rem[i] / gcd(rem[i], (long long)(s[i] - '0'));
        }
        
        if (rem[n] == 1 && pos == n - 1 && s[pos] != '0') return s;
        
        for (int i = pos; i >= 0; --i) {
            int startDigit = (i < n) ? (s[i] - '0') + 1 : 1;
            for (int d = startDigit; d <= 9; ++d) {
                long long tNow = rem[i] / gcd(rem[i], (long long)d);
                std::string suffix = "";
                long long currT = tNow;
                
                for (int j = n - 1; j > i; --j) {
                    for (int v = 9; v >= 1; --v) {
                        if (currT % v == 0) {
                            suffix += std::to_string(v);
                            currT /= v;
                            break;
                        }
                    }
                }
                if (currT == 1) {
                    std::reverse(suffix.begin(), suffix.end());
                    return s.substr(0, i) + std::to_string(d) + suffix;
                }
            }
        }
        
        long long currT = t;
        std::string digits = "";
        for (int v = 9; v >= 2; --v) {
            while (currT % v == 0) {
                digits += std::to_string(v);
                currT /= v;
            }
        }
        std::sort(digits.begin(), digits.end());
        int reqLen = std::max(n + 1, (int)digits.length());
        return std::string(reqLen - digits.length(), '1') + digits;
    
        
    }
int main(){
    string s; cout<<"Enter the number: "; cin>>s;
    long long t; cout<<"Enter the t: "; cin>>t;

    string result = smallestnumber(s,t);
    cout<<"The result is: "<<result<<endl;
    return 0;
}