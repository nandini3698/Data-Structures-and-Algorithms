/*Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] 
when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray 
C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

Examples:

Input: [1,-2,3,-2]
Output: 3

Input: [5,-3,5]
Output: 10

Input: [3,-1,2,-1]
Output: 4

Input: [3,-2,2,-3]
Output: 3

Input: [-2,-3,-1]
Output: -1
 
Note:
* -30000 <= A[i] <= 30000
* 1 <= A.length <= 30000*/


/*------------------------------------------------------------------------------------------------------------------------*/

// Code

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a) {
        int m=0,mx=INT_MIN,i=0,n=a.size();
        while(i<n){
            m+=a[i];
            if(m<a[i])
                m=a[i];
            mx=max(mx,m);
            i++;
        }
        
        int p=0,px=INT_MIN,s=0;
        i=0;
        for(int i=0;i<n;i++){
            s+=a[i];
            a[i]=a[i]*(-1);}
        
        while(i<n){
            p+=a[i];
            if(p<a[i])
                p=a[i];
            px=max(px,p);
            i++;
        }

        if(s+px!=0)
            return max(mx,(s+px));
        else return mx;
    }
};