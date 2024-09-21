#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {

    public:
        void fun2(int x)     //write function here 
        {  // Your code goes here
            if (x>0){
                fun2(x-1);
                cout << x << " ";
            }
        }
  };

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        ob.fun2(N);
    }
    return 0;
}