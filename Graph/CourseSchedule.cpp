/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take 
course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for 
you to finish all courses?

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false*/

/*--------------------------------------------------------------------------------------------------*/

// Code

class Solution {
public:
    bool dfs(int t,vector<vector<int> >& v,int* arr){
        if(arr[t]==0) return false;
        arr[t]=0;

        for(int i=0;i<v[t].size();i++)
            if(!dfs(v[t][i],v,arr)) return false;
        
        arr[t]=1;        
        return true;
    }
    
    bool canFinish(int N,vector<vector<int>>& p){       
        int n=p.size();
        
        vector<vector<int> >v(N);
        for(int i=0;i<n;i++)
            v[p[i][0]].push_back(p[i][1]);
        
        int arr[N];
        for(int i=0;i<N;i++)
            arr[i]=-1;
         
        for(int i=0;i<N;i++)
            if(arr[i]==-1 && !dfs(i,v,arr))
                return false;
                  
        return true;
    }
};