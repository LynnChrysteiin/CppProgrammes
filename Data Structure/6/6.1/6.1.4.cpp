/*
 * 目的：使用C++模板设计并逐步完善图的邻接矩阵抽象数据类型（ADT）。
 * 内容：
 * （1）请参照图的邻接矩阵模板类原型，设计并逐步完善图的邻接矩阵ADT。
 *      （由于该环境目前仅支持单文件的编译，故将所有内容都集中在一个源文件内。
 *      在实际的设计中，推荐将抽象类及对应的派生类分别放在单独的头文件中。）
 *（2）设计并实现一个算法，在已存在的图中查找指定元素值的顶点在顶点集中的位序。
 * 图的存储结构采用邻接矩阵。将其加入到ADT中。
 */

#include <iostream>
#include <vector>
#include <string>

template <class VertexType, class EdgeType>
class AdjMatrix_Graph
{
private:
    std::string graphType;
    int nVertex;
    int nEdge;
    VertexType *vertex;
    EdgeType **edge;
    EdgeType noEdge;

public:
    AdjMatrix_Graph(std::string graphType, int nVertex, VertexType *vertex, EdgeType noEdge)
        : graphType(graphType), nVertex(nVertex), noEdge(noEdge)
    {
        nEdge = 0;

        this->vertex = new VertexType[nVertex];
        for (int i = 0; i < nVertex; i++)
            this->vertex[i] = vertex[i];

        this->edge = new EdgeType *[nVertex];
        for (int i = 0; i < nVertex; i++)
            this->edge[i] = new EdgeType[nVertex];
        for (int i = 0; i < nVertex; i++)
            for (int j = 0; j < nVertex; j++)
                this->edge[i][j] = noEdge;
    }
    AdjMatrix_Graph(std::string graphType, int nVertex, int nEdge, VertexType *vertex, std::pair<int, int> *edgePair, EdgeType *weight, EdgeType noEdge)
        : graphType(graphType), nVertex(nVertex), nEdge(nEdge), noEdge(noEdge)
    {
        this->vertex = new VertexType[nVertex];
        for (int i = 0; i < nVertex; i++)
            this->vertex[i] = vertex[i];

        this->edge = new EdgeType *[nVertex];
        for (int i = 0; i < nVertex; i++)
            this->edge[i] = new EdgeType[nVertex];
        for (int i = 0; i < nVertex; i++)
            for (int j = 0; j < nVertex; j++)
                this->edge[i][j] = noEdge;
        for (int i = 0; i < nEdge; i++)
        {
            int x = edgePair[i].first;
            int y = edgePair[i].second;
            this->edge[x][y] = weight[i];
            if (graphType == "UDG" || graphType == "UDN")
                this->edge[y][x] = weight[i];
        }
    }
    ~AdjMatrix_Graph()
    {
        delete[] vertex;
        for (int i = 0; i < nVertex; i++)
            delete[] edge[i];
        delete[] edge;
    }
    std::string getGraphType() const { return graphType; }
    std::vector<VertexType> bfs(int start) const
    {
        bool *visited = new bool[nVertex];
        for (int i = 0; i < nVertex; i++)
            visited[i] = false;
        std::vector<VertexType> result;
        std::vector<int> nodeQueue;
        nodeQueue.push_back(start);
        visited[start] = true;
        while (!nodeQueue.empty())
        {
            int nodeIndex = nodeQueue.front();
            nodeQueue.erase(nodeQueue.begin());
            result.push_back(vertex[nodeIndex]);
            for (int i = 0; i < nVertex; i++)
            {
                if (edge[nodeIndex][i] != noEdge && !visited[i])
                {
                    nodeQueue.push_back(i);
                    visited[i] = true;
                }
            }
        }
        delete[] visited;
        return result;
    }
    int locateVertex(VertexType val) const
    {
        int res = -1;
        for (int i = 0; i < nVertex; i++)
        {
            if (vertex[i] == val)
            {
                res = i;
                break;
            }
        }
        return res;
    }
    void printEdge() const
    {
        for (int i = 0; i < nVertex; i++)
        {
            for (int j = 0; j < nVertex; j++)
            {
                std::cout << edge[i][j];
                if (j != nVertex - 1)
                    std::cout << " ";
                else if (j == nVertex - 1 && i != nVertex - 1)
                    std::cout << std::endl;
            }
        }
    }
    void printVertex() const
    {
        std::cout << vertex[0];
        for (int i = 1; i < nVertex; i++)
            std::cout << " " << vertex[i];
    }
};

int main()
{
    std::string graphType;
    int nVertex, nEdge;
    int noEdge;
    std::cin >> graphType >> nVertex; // 图类型, 顶点数
    std::string vertex[nVertex];
    int edge[nVertex][nVertex];
    for (int i = 0; i < nVertex; i++)
        std::cin >> vertex[i]; // 顶点集
    std::cin >> nEdge;         // 边数
    for (int i = 0; i < nEdge; i++)
        for (int j = 0; j < nEdge; j++)
            edge[i][j] = noEdge;
    std::pair<int, int> edgePair[nEdge];
    for (int i = 0; i < nEdge; i++)
    {
        int x, y;
        std::cin >> x >> y; // 边集
        edgePair[i] = std::make_pair(x, y);
    }
    int weight[nEdge];
    for (int i = 0; i < nEdge; i++)
        weight[i] = 1;
    AdjMatrix_Graph<std::string, int> graph(graphType, nVertex, nEdge, vertex, edgePair, weight, 0);
    std::string val;
    std::cin >> val;
    graph.printVertex();
    int res = graph.locateVertex(val);
    std::cout << std::endl << res;
    return 0;
}