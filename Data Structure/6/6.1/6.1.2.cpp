/*
 * Ŀ�ģ�ʹ��C++ģ����Ʋ�������ͼ���ڽӾ�������������ͣ�ADT����
 * ���ݣ�
 * ��1�������ͼ���ڽӾ���ģ����ԭ�ͣ���Ʋ�������ͼ���ڽӾ���ADT��
 *      �����ڸû���Ŀǰ��֧�ֵ��ļ��ı��룬�ʽ��������ݶ�������һ��Դ�ļ��ڡ�
 *      ��ʵ�ʵ�����У��Ƽ��������༰��Ӧ��������ֱ���ڵ�����ͷ�ļ��С���
 * ��2����Ʋ�ʵ��һ���㷨��ʹ�ö��У���һ���Ѵ��ڵ�ͼ���й�����ȱ�����BFS)������������Ķ����������С�
 *      ���������ͨ������ָ����
 * ע�⣺����ʱ�����Ӹõ������������ͼ�����ͼ����ͨ����ֻ����һ����ͼ��
 * ͼ�Ĵ洢�ṹ�����ڽӾ��󡣽�����뵽ADT�С�
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
    std::vector<VertexType> bfs(int start)
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
    std::cin >> graphType >> nVertex; // ͼ����, ������
    std::string vertex[nVertex];
    int edge[nVertex][nVertex];
    for (int i = 0; i < nVertex; i++)
        std::cin >> vertex[i]; // ���㼯
    std::cin >> nEdge;         // ����
    for (int i = 0; i < nEdge; i++)
        for (int j = 0; j < nEdge; j++)
            edge[i][j] = noEdge;
    std::pair<int, int> edgePair[nEdge];
    for (int i = 0; i < nEdge; i++)
    {
        int x, y;
        std::cin >> x >> y; // �߼�
        edgePair[i] = std::make_pair(x, y);
    }
    int weight[nEdge];
    for (int i = 0; i < nEdge; i++)
        weight[i] = 1;
    int start;
    std::cin >> start; // �������
    AdjMatrix_Graph<std::string, int> graph(graphType, nVertex, nEdge, vertex, edgePair, weight, 0);

    graph.printVertex();
    std::cout << std::endl
              << std::endl;
    graph.printEdge();
    std::cout << std::endl
              << std::endl;
    auto result = graph.bfs(start);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i];
        if (i != result.size() - 1)
            std::cout << "->";
    }
    return 0;
}