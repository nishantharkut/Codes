#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        long long total = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            total += a[i];
        }
        
        double avg = (double)total / n;
        int countU = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < avg / 2) {
                countU++;
            }
        }
        
        if (countU > n / 2) {
            cout << "0\n";
            continue;
        }

        int maxIndex = max_element(a.begin(), a.end()) - a.begin();
        long long WealthM = a[maxIndex];
        long long minX = -1;

        long long low = 0, high = 1e18;
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long newTotal = total + mid;
            double newAvg = (double)newTotal / n;
            countU = 0;

            for (int i = 0; i < n; i++) {
                if ((i == maxIndex ? WealthM + mid : a[i]) < newAvg / 2) {
                    countU++;
                }
            }

            if (countU > n / 2) {
                minX = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << minX << endl;
    }
    return 0;
}
