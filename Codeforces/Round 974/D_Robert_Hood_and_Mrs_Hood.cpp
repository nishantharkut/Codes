#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d, k;
        cin >> n >> d >> k;
        vector<int> l(k), r(k);
        for (int i = 0; i < k; i++) {
            cin >> l[i] >> r[i];
        }

        vector<int> ohbhaioverlapkarraha(n + 2, 0);

        for (int i = 0; i < k; i++) {
            int start = max(1, l[i] - d + 1);
            int end = min(n - d + 1, r[i]);
            if (start <= end) {
                ohbhaioverlapkarraha[start]++;
                if (end + 1 <= n - d + 1) {
                    ohbhaioverlapkarraha[end + 1]--;
                }
            }
        }

        int max_ohbhaioverlapkarraha = -1, min_ohbhaioverlapkarraha = INT_MAX;
        int brder = -1, moder = -1;
        int current_ohbhaioverlapkarraha = 0;

        for (int i = 1; i <= n - d + 1; i++) {
            current_ohbhaioverlapkarraha += ohbhaioverlapkarraha[i];
            if (current_ohbhaioverlapkarraha > max_ohbhaioverlapkarraha) {
                max_ohbhaioverlapkarraha = current_ohbhaioverlapkarraha;
                brder = i;
            }
            if (current_ohbhaioverlapkarraha < min_ohbhaioverlapkarraha) {
                min_ohbhaioverlapkarraha = current_ohbhaioverlapkarraha;
                moder = i;
            }
        }

        cout << brder << " " << moder << endl;
    }
    return 0;
}
