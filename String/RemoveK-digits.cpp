/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.

Examples:

Input: num = "1432219", k = 3
Output: "1219"

Input: num = "10200", k = 1
Output: "200"

Input: num = "10", k = 2
Output: "0"
*/


/*------------------------------------------------------------------------------------------------------------------------------------------*/


// Code

class Solution {
public:
    string removeKdigits(string a, int k) {
        cout<<a.length();
        string t="";
        int mn;
        
        while(1){
            mn=0;
            if(k==0){
                t.append(a);
                break;
            }
            
            if(a.length()<=k) break;
            
            for(int i=1;i<=k;i++)
                if(a[i]<a[mn]) mn=i;
            t+=a[mn];
            k-=mn;
            a=a.substr(mn+1,a.length()-mn);
        }
        
        int i=0;
        while(t[i]=='0' && i<t.length())
            i++;

        t=t.substr(i,t.length()-i);
        if(t=="") return "0";
        
        return t;
    }
};