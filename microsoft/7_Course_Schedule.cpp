#include<iostream>
#include<vector>
#include<queue> 
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // first creating a graph for all pre-requisites        
        vector<int> adj[numCourses];

        for( auto it : prerequisites ) {
            adj[it[0]].push_back( it[1] );
        }

        // setting the indegree of all nodes
        int inDegree[numCourses] = {0};
        for( int i=0; i<numCourses; i++ ) {
            for( auto it : adj[i] ) {
                inDegree[it]++;
            }
        }

        // taking all the elements with indegree 0 in a seperate queue, as they all can be valid candiates for the starting point
        queue<int> q;
        for( int i=0; i<numCourses; i++ ) {
            if( inDegree[i] == 0 ) {
                q.push( i );
            }
        }

        // using topological sort to get a valid path 
        vector<int> topo;
        while( !q.empty() ) {
            int node = q.front();
            q.pop();
            topo.push_back( node );

            for( int it : adj[node] ) {
                inDegree[it]--;
                if( inDegree[it] == 0 ) q.push( it );
            }
        }

        cout << topo.size() << " " << endl;
        return topo.size() == numCourses;
    }
};

int main() {
    Solution s;

    vector<vector<int>> v = { {1,0},  };
    bool result = s.canFinish( 2, v );

    cout << result << " ";

    return 0;
}