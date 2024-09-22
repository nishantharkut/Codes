#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {

    public:
      void treeRecursion(int n)//write function here 
        {  // Your code goes here
            if (n>0){
                cout << n << " ";
                treeRecursion(n-1);
                treeRecursion(n-1);
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
        ob.treeRecursion(N);
    }
    return 0;
}