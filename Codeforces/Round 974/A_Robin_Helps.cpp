#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;  
    while (t--) {
        int n, k;
        cin >> n >> k;  
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int rGold = 0;
        int count = 0;
        bool donor = false;

        for (int i = 0; i < n; i++) {
            if (a[i] >= k) {
                rGold += a[i];
                donor = true;
            } else if (donor && a[i] == 0) {
                if (rGold > 0) {
                    rGold--;
                    count++;
                }
            }
        }
        
        cout << count << endl;
    }
    return 0;
}
