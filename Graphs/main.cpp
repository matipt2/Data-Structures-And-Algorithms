#include <iostream>
#include <vector>
#include <unordered_map>
class UndirectedGraphVector {
public:
    int V;
    std::vector<std::vector<int>>adj;

    UndirectedGraphVector(int vert) : V(vert){
        adj.resize(V+1, std::vector<int>(V+1,0));
    }
    void addEdge(int v, int w){
        adj[v][w] = 1;
        adj[w][v] = 1;

    }

    std::vector<int> neigbors(int v){

        std::vector<int> neighborsList;
        for(int i=0;i<V;i++){
            if(adj[v][i]==1){
                neighborsList.push_back(i);
            }

        }
        return neighborsList;
    }

    int degree(int vertex){
        return neigbors(vertex).size();
    }

};

class DirectedGraphVector{
public:
    int V;
    std::vector<std::vector<int>>adj;

    DirectedGraphVector(int vert) : V(vert){
        adj.resize(V+1, std::vector<int>(V+1,0));
    }
    void addEdge(int v, int w){
        adj[v][w] = 1;
    }

    int in(int vert){
        int counter = 0;
        for(int i=0;i<V;i++){
            if(adj[i][vert]==1){
                counter++;
            }
            else{
                continue;
            }
        }
        return counter;
    }
    int out(int vert){
        int counter = 0;
        for(int i=0;i<V;i++){
            if(adj[vert][i]==1){
                counter++;
            }
            else{
                continue;
            }
        }
        return counter;
    }

    std::vector<int> neighbors(int vert){
        std::vector<int> neighborsList;
        for(int i=0;i<V;i++){
            if(adj[vert][i]==1){
                neighborsList.push_back(i);
            }
            else{
                continue;
            }
        }
        return neighborsList;
    }

    std::vector<int> vertexes(int vert){
        std::vector<int> vertexesList;
        for(int i=0;i<V;i++){
            if(adj[i][vert]==1){
                vertexesList.push_back(i);
            }
        }
        return vertexesList;
    }
};

class UndirectedGraphDictionary{
private:
    std::unordered_map<int, std::vector<int>> adj;
public:

    void addEdge(int v, int w){
        adj[v].push_back(w);
        adj[w].push_back(v);

    }

    int degree(int vertex){
        int counter = 0;
        auto it = adj.find(vertex);
        const auto& neighbors = it->second;
        counter = neighbors.size();
        return counter;
    }
    std::vector<int> neighbors(int vertex){
        std::vector<int> neighList;
        auto it = adj.find(vertex);
        const auto& neighbors = it->second;
        for(int neighb: neighbors){
            neighList.push_back(neighb);
        }
        return neighList;
    }


};

class DirectedGraphDictionary {
private:
    std::unordered_map<int, std::vector<int>> adj;

public:
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    int in(int vertex) {
        int counter = 0;
        for (const auto& pair : adj) {
            for (int neighbor : pair.second) {
                if (neighbor == vertex) {
                    counter++;
                    break;
                }
            }
        }
        return counter;
    }

    int out(int vertex) {
        auto it = adj.find(vertex);
        if (it != adj.end())
            return it->second.size();
        return 0;
    }

    std::vector<int> neighbors(int vertex) {
        std::vector<int> result;
        for (const auto& pair : adj) {
            for (int neighbor : pair.second) {
                if (pair.first == vertex) {
                    result.push_back(neighbor);
                }
            }
        }
        return result;
    }

    std::vector<int> vertexes(int vertex) {
        std::vector<int> verticesList;
        for (const auto& pair : adj) {
            for (int neighbor : pair.second) {
                if (neighbor == vertex) {
                    verticesList.push_back(pair.first);
                    break;
                }
            }
        }
        return verticesList;
    }

};


class DirectedGraphIncidence{
private:
    std::vector<std::vector<int>>inc;
public:
    int V;
    DirectedGraphIncidence(int vert) : V(vert){
        inc.resize(V+1, std::vector<int>(V+1,0));
    }





};

class UndirectedGraphIncidence{
private:
    std::vector<std::vector<int>>inc;
public:
    int V;
    UndirectedGraphIncidence(int vert) : V(vert){
        inc.resize(V+1, std::vector<int>(V+1,0));
    }

    void addEdge(int vertex, int edge){
        inc[vertex][edge]=1;
        inc[edge][vertex]=1;
    }

    int degree(int vertex){
        int counter = 0;
        for(int i=0;i<inc[vertex].size();i++){
            if(inc[vertex][i]==1){
                counter++;
            }
            else{
                continue;
            }
        }
        return counter;
    }

    std::vector<int> neighbors(int vertex){
        std::vector<int> neighborsList;
        for(int i=0;i<inc[vertex].size();i++){
            if(inc[vertex][i]==1){
                neighborsList.push_back(i);
            }
            else{
                continue;
            }
        }
        return neighborsList;
    }
};
