#include <iostream>
#include <vector>
class UndirectedGraph {
public:
    int V;
    std::vector<std::vector<int>>adj;

    UndirectedGraph(int vert) : V(vert){
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

class DirectedGraph{
public:
    int V;
    std::vector<std::vector<int>>adj;

    DirectedGraph(int vert) :V(vert){
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




int main() {

    //undirected
    // pairs: (6,4) (4,5) (5,1) (5,2) (5,1) (4,3) (3,2) (2,1)

//    char type;
//    int vs;
//
//
//    std::cout<<"amount of vertex"<<std::endl;
//    std::cin >> vs;
//    UndirectedGraph graph(6);
//    std::cout<<"add pairs"<<std::endl;
//
//    graph.addEdge(6,4);
//    graph.addEdge(4,5);
//    graph.addEdge(5,1);
//    graph.addEdge(5,2);
//    graph.addEdge(4,3);
//    graph.addEdge(3,2);
//    graph.addEdge(2,1);
//
//    for(int neighbor: graph.neigbors(5)){
//        std::cout<<neighbor<<std::endl;
//    }
//    std::cout<<graph.degree(5)<<std::endl;

    //directed
    DirectedGraph graph(6);
    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    graph.addEdge(3,4);
    graph.addEdge(4,1);
    graph.addEdge(4,2);
    graph.addEdge(5,4);
    graph.addEdge(5,6);
    graph.addEdge(6,2);
    graph.addEdge(6,3);



    return 0;
}
