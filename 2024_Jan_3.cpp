#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_set<int> uniqueNumbers;
int mx=1e18;
int result = 0;
void check1(){
    if (uniqueNumbers.size() <= 3) {
        cout << mx * (mx + 1) / 2 << endl;
        exit(0);
    }
}
void check2(){
    for (int i = 1; i <= 1000000; ++i) {
        if (i > mx) return;
        unordered_set<int> moduloSet;
        for (int num : uniqueNumbers) {
            moduloSet.insert(num % i);
            if (moduloSet.size() == 4) {
                break;
            }
        }
        if (moduloSet.size() < 4) {
            result += i;
        }
    }
}
void solve(){
        if (uniqueNumbers.size() < 1000) {
        unordered_set<int> factorSet;
        for (int num1 : uniqueNumbers) {
            for (int num2 : uniqueNumbers) {
                if (num2 - num1 > 1000000) {
                    for (int k = 1; k <= 4000; ++k) {
                        if ((num2 - num1) % k == 0) {
                            factorSet.insert((num2 - num1) / k);
                        }
                    }
                }
            }
        }

        for (int factor : factorSet) {
            if (factor > mx) continue;
            if (factor <= 1000000) continue;
            unordered_set<int> moduloSet;
            for (int num : uniqueNumbers) {
                moduloSet.insert(num % factor);
                if (moduloSet.size() == 4) {
                    break;
                }
            }
            if (moduloSet.size() < 4) {
                result += factor;
            }
        }
    }
}
signed main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        uniqueNumbers.insert(tmp);
        mx = min(mx,tmp);
    }
    mx/=4;
    check1();
    check2();
    solve();
    cout << result << endl;
    return 0;
}