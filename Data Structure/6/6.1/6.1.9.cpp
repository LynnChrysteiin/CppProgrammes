/*
 * 设计并实现一个算法，在已存在的无权图中删除两个顶点的关联边。
 * 删除成功，返回true；否则返回false。
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

private:
    void dfs_core(int start, std::vector<VertexType> &res, bool *visited) const
    {
        res.push_back(vertex[start]);
        visited[start] = true;
        for (int i = 0; i < nVertex; i++)
        {
            if (edge[start][i] != noEdge && !visited[i])
                dfs_core(i, res, visited);
        }
    }

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
    std::vector<VertexType> dfs(int start) const
    {
        std::vector<VertexType> result;
        bool *visited = new bool[nVertex];
        for (int i = 0; i < nVertex; i++)
            visited[i] = false;
        dfs_core(start, result, visited);
        delete[] visited;
        return result;
    }
    int getDegree(int index, char flag = 'o') const // 'o'求出度, 'i'求入度
    {
        if (index < 0 || index >= nVertex)
            return -1;
        int res = 0;
        for (int i = 0; i < nVertex; i++)
        {
            switch (flag)
            {
            case 'o':
                if (edge[index][i] != noEdge)
                    res++;
                break;
            case 'i':
                if (edge[i][index] != noEdge)
                    res++;
                break;
            default:
                break;
            }
        }
        return res;
    }
    bool deleteEdge(int v1, int v2) // v1 -> v2
    {
        if (v1 < 0 || v1 >= nVertex || v2 < 0 || v2 >= nVertex || edge[v1][v2] == noEdge)
            return false;
        edge[v1][v2] = noEdge;
        if (graphType == "UDG" || graphType == "UDN")
            edge[v2][v1] = noEdge;
        nEdge--;
        return true;
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
                std::cout << edge[i][j] << " ";
                if (j == nVertex - 1 && i != nVertex - 1)
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
    int noEdge = 0;
    std::cin >> graphType >> nVertex; // 图类型, 顶点数
    std::string vertex[nVertex];
    for (int i = 0; i < nVertex; i++)
        std::cin >> vertex[i]; // 顶点集
    std::cin >> nEdge;         // 边数
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
    int v1, v2;
    std::cin >> v1 >> v2; // 待删除的边

    AdjMatrix_Graph<std::string, int> graph(graphType, nVertex, nEdge, vertex, edgePair, weight, noEdge);
    graph.printVertex();
    int edgeNum = sizeof(edgePair) / sizeof(std::pair<int, int>);
    std::cout << std::endl
              << edgeNum << std::endl;
    graph.printEdge();
    std::cout << std::endl
              << std::endl;
    if (graph.deleteEdge(v1, v2))
    {
        edgeNum--;
        std::cout << "true" << std::endl;
    }
    else
        std::cout << "false" << std::endl;
    std::cout << edgeNum << std::endl;
    graph.printEdge();
    return 0;
}