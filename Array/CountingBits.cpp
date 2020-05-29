/*Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate 
the number of 1's in their binary representation and return them as an array.

Example 1:
Input: 2
Output: [0,1,1]

Example 2:
Input: 5
Output: [0,1,1,2,1,2]
*/

/*-----------------------------------------------------------------------------------------------------*/

/*
Idea: count[n]=count[n-1]+1   ; if n is odd
              =count[n/2]     ; if n is even
*/

// Code

class Solution {
public:
    vector<int> countBits(int n){
        vector<int>a(n+1);
 
        a[0]=0;
        if(n==0) return a;
        a[1]=1;
        for(int i=1;i<n;i++){
            if(i&1){
              a[i+1]=a[(i+1)/2];
            }
            else
                a[i+1]=a[i]+1;
        }
        return a;        
    }
};