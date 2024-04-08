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
class UndirectedIncidenceMatrix {
private:
    int vertices;
    int edges;
    std::vector<std::vector<int>> incidenceMatrix;

public:
    UndirectedIncidenceMatrix(int v, int e) : vertices(v), edges(e) {
        incidenceMatrix.resize(vertices, std::vector<int>(edges, 0));
    }

    void addEdge(int edgeIndex, int vertex1, int vertex2) {
        if (edgeIndex >= 0 && edgeIndex < edges && vertex1 >= 0 && vertex1 < vertices && vertex2 >= 0 && vertex2 < vertices) {
            incidenceMatrix[vertex1][edgeIndex] = 1;
            incidenceMatrix[vertex2][edgeIndex] = 1;
        } else {
            std::cout << "invalid edge or vertex index!" << std::endl;
        }
    }

    void degree(int vertex) {
        if (vertex >= 0 && vertex < vertices) {
            int degree = 0;
            for (int j = 0; j < edges; ++j) {
                if (incidenceMatrix[vertex][j] == 1)
                    degree++;
            }
            std::cout << "degree of vertex " << vertex << ": " << degree << std::endl;
        } else {
            std::cout << "invalid vertex index!" << std::endl;
        }
    }

    void neighbors(int vertex) {
        if (vertex >= 0 && vertex < vertices) {
            std::cout << "neighbors " << vertex << ": ";
            for (int i = 0; i < vertices; ++i) {
                if (i != vertex && incidenceMatrix[vertex][i] == 1)
                    std::cout << i << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "invalid vertex index!" << std::endl;
        }
    }
};
class DirectedIncidenceMatrix {
private:
    int vertices;
    int edges;
    std::vector<std::vector<int>> incidenceMatrix;

public:
    DirectedIncidenceMatrix(int v, int e) : vertices(v), edges(e) {
        incidenceMatrix.resize(vertices, std::vector<int>(edges, 0));
    }

    void addEdge(int edgeIndex, int fromVertex, int toVertex) {
        if (edgeIndex >= 0 && edgeIndex < edges && fromVertex >= 0 && fromVertex < vertices && toVertex >= 0 && toVertex < vertices) {
            incidenceMatrix[fromVertex][edgeIndex] = -1;
            incidenceMatrix[toVertex][edgeIndex] = 1;
        } else {
            std::cout << "invalid edge or vertex index!" << std::endl;
        }
    }

    void outDegree(int vertex) {
        if (vertex >= 0 && vertex < vertices) {
            int outDegree = 0;
            for (int j = 0; j < edges; ++j) {
                if (incidenceMatrix[vertex][j] == 1)
                    outDegree++;
            }
            std::cout << "out degree " << vertex << ": " << outDegree << std::endl;
        } else {
            std::cout << "invalid vertex index!" << std::endl;
        }
    }

    void inDegree(int vertex) {
        if (vertex >= 0 && vertex < vertices) {
            int inDegree = 0;
            for (int j = 0; j < edges; ++j) {
                if (incidenceMatrix[vertex][j] == -1)
                    inDegree++;
            }
            std::cout << "in degree " << vertex << ": " << inDegree << std::endl;
        } else {
            std::cout << "invalid vertex index!" << std::endl;
        }
    }

    void adjacentVertices(int vertex) {
        if (vertex >= 0 && vertex < vertices) {
            std::cout << "vertices adjacent to vertex " << vertex << ": ";
            for (int i = 0; i < vertices; ++i) {
                if (i != vertex && (incidenceMatrix[vertex][i] == -1 || incidenceMatrix[vertex][i] == 1))
                    std::cout << i << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "invalid vertex index!" << std::endl;
        }
    }
};


int main() {
    return 0;
}