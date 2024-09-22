#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        
        long long s = n - k + 1;
        long long e = n;

        long long count = 0;
        if (s % 2 == 1) {
            count = (e - s) / 2 + 1;
        } else {
            count = (e - s + 1) / 2;
        }

        if (count % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
