class Solution {
  public:
  
    int countWays(int n, int k) {
        // code here
        if(n==1) return k;
        int one=k;
        int two=k*k;
        for(int i=3; i<=n; i++){
            int three=(k-1)*(one+two);
            one=two;
            two=three;
        }
        return two;
    }
};