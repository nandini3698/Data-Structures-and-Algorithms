/*Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
Each person may dislike some other people, and they should not go into the same group. 
Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
Return true if and only if it is possible to split everyone into two groups in this way.

Example 1:
Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true

Example 2:
Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false

Example 3:
Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
*/

/*----------------------------------------------------------------------------------------------------------------------------*/

// Code

class Solution {
public:
    unordered_set<int>s,t;
    
    int bfs(int k,int *arr,vector<vector<int> >&v){
        queue<int>q;
        q.push(k);
        s.insert(k);
        arr[k]=1;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            
            if(s.find(temp)==s.end())
                for(int i=0;i<v[temp].size();i++){
                    if(!arr[v[temp][i]]){
                        arr[v[temp][i]]=1;
                        q.push(v[temp][i]);
                        s.insert(v[temp][i]);
                    }
                    else if(s.find(v[temp][i])==s.end())
                        return 0;
                }
            else
                for(int i=0;i<v[temp].size();i++){
                    if(!arr[v[temp][i]]){
                        arr[v[temp][i]]=1;
                        q.push(v[temp][i]);
                        t.insert(v[temp][i]);
                    }
                    else if(t.find(v[temp][i])==t.end())
                        return 0;
                }
        }
        return 1;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& d) {
        
        int n=d.size();
        if(n==0) return true;
               
        int arr[N+1];
        for(int i=0;i<=N;i++)
            arr[i]=0;
        
        vector<vector<int> >v(N+1);
        for(int i=0;i<n;i++){
            v[d[i][0]].push_back(d[i][1]);
            v[d[i][1]].push_back(d[i][0]);
        }

        int res=1;
        
        for(int i=1;i<=N;i++)
            if(!arr[i])
                res=res&bfs(i,arr,v);
         
        if(res==1) return true;
        return false;
    }
};