/*Floyd : City of Blinding Lights
link: https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights?isFullScreen=true
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



int main()
{
    string road_nodes_edges_temp;
    getline(cin, road_nodes_edges_temp);

    vector<string> road_nodes_edges = split(rtrim(road_nodes_edges_temp));

    int road_nodes = stoi(road_nodes_edges[0]);
    int road_edges = stoi(road_nodes_edges[1]);

    vector<int> road_from(road_edges);
    vector<int> road_to(road_edges);
    vector<int> road_weight(road_edges);
    
    //code1: Initialize distance vector
    vector<vector<int>> dist(road_nodes,vector<int>(road_nodes,INT_MAX));
    for(int i=0;i<road_nodes;i++){
        for(int j=0;j<road_nodes;j++){
            if(i==j)
                dist[i][j]=0;
        }
    }

    for (int i = 0; i < road_edges; i++) {
        string road_from_to_weight_temp;
        getline(cin, road_from_to_weight_temp);

        vector<string> road_from_to_weight = split(rtrim(road_from_to_weight_temp));

        int road_from_temp = stoi(road_from_to_weight[0]);
        int road_to_temp = stoi(road_from_to_weight[1]);
        int road_weight_temp = stoi(road_from_to_weight[2]);

        road_from[i] = road_from_temp;
        road_to[i] = road_to_temp;
        road_weight[i] = road_weight_temp;
        //code2: fill distance vector with weights road_from to road_to nodes
        dist[road_from_temp-1][road_to_temp-1]=road_weight_temp;
    }

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));
    
    //code3: now use floy-warshells to fill the distance matrix of shortest paths 
    //from each node to every other node
    for(int k=0;k<road_nodes;k++){
        for(int i=0;i<road_nodes;i++){
            for(int j=0;j<road_nodes;j++){
                if(dist[i][k]!=INT_MAX&&dist[k][j]!=INT_MAX){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int x = stoi(first_multiple_input[0]);

        int y = stoi(first_multiple_input[1]);
        
        //code4: Now answer for each query using distance matrix computed from floyd-warshells
        int ans=-1;
        if(dist[x-1][y-1]!=INT_MAX){
            cout<<dist[x-1][y-1]<<endl;
        } else {
            cout<<ans<<endl;
        }        
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
