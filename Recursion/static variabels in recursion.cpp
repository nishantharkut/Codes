#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {

    public:
        int fun(int n){
            if (n>0){
                return fun(n-1)+n;
            }
            return 0;
        }

      int fun_static(int n)//write function here 
        {  // Your code goes here
            static int x = 0; //these are created only one time when the function is created and not everytime the function is being called
            if (n>0) {
                x++;
                return fun_static(n-1)+x;
            }
            return 0;
        }
  };

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << "without static var :" << endl;
        cout << ob.fun(N) << endl;
        cout << "with static var :" << endl;
        cout << ob.fun_static(N) << endl;
    }
    return 0;
}