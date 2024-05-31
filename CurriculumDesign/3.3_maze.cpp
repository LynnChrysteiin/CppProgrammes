/* 
 * 实践五 课题三：迷宫问题求解
 * 
 * 迷宫问题是取自心理学的一个古典实验。
 * 实验中，把一只老鼠从一个没有顶的大盒子的门放入，在盒中设置了许多墙，对行进的方向形成了多处阻挡。
 * 盒子仅仅有一个出口，在出口处放置了一块奶酪，吸引老鼠在迷宫中寻找道路以到达出口。
 * 重复对老鼠进行上述实验，看老鼠能在多久找到出口。
 * 请设计一个算法实现迷宫问题求解。
 * In  1   0   0   0
 * 1   0   1   1   0
 * 1   0   1   1   0
 * 1   1   0   1   1
 * 0   0   1   0   1
 * 1   1   1   0   Out
 * 
 * 此问题定义老鼠只能向上下左右四个方向移动，不能斜着移动。
 * 则此测试数据无解，实际请自行更改迷宫二维数组，使得存在一条路径来测试程序的可行性。
 */

#include <iostream>

const int M = 6;
const int N = 5;

/* 0: 可走 1: 不可走 */
bool maze[M][N] = {
    {0, 1, 0, 0, 0},
    {1, 0, 1, 1, 0},
    {1, 0, 1, 1, 0},
    {1, 1, 0, 1, 1},
    {0, 0, 1, 0, 1},
    {1, 1, 1, 0, 0}};

/* 0: 未走过 1: 已走过 */
bool mark[M][N] = {0};

/* box结构体, 保存坐标和前驱, 用于回溯路径 */
struct box
{
    int x;
    int y;
    int pre;
};

box queue[M * N];

int front = 0;
int rear = 0;

void printPath(int i)
{
    static int step = 0;
    if (queue[i].pre != -1)
    {
        printPath(queue[i].pre);
    }
    std::cout << "第" << ++step << "步: (" << queue[i].x << ", " << queue[i].y << ")" << std::endl;
}

int main()
{
    bool found = 0;
    int cur;
    int row, col;
    int next;
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    queue[rear].x = 0;
    queue[rear].y = 0;
    queue[rear].pre = -1;
    rear++;
    mark[0][0] = 1;

    /* 广度优先搜索 */
    while (front < rear && !found) // 检查队列是否为空且未找到出口
    {
        cur = front;
        front++;
        for (int i = 0; i < 4; i++) // 尝试当前位置的四个方向
        {
            row = queue[cur].x + dir[i][0];
            col = queue[cur].y + dir[i][1];
            if (row < 0 || row >= M || col < 0 || col >= N) // 越界
            {
                continue;
            }
            if (maze[row][col] == 0 && mark[row][col] == 0) // 未走过且可走
            {
                queue[rear].x = row;
                queue[rear].y = col;
                queue[rear].pre = cur;
                rear++;
                mark[row][col] = 1;
            }
            if (row == M - 1 && col == N - 1) // 到达出口
            {
                found = 1;
                break;
            }
        }
    }

    std::cout << "***************************************************************\n";
    std::cout << "****             实践四  课题三   迷宫问题求解             ****\n";
    std::cout << "***************************************************************\n\n";

    if (found)
    {
        std::cout << "找到路径!\n";
        printPath(rear - 1);
    }
    else
    {
        std::cout << "未找到路径!\n";
    }

    while (1);

    system("pause");
    return 0;
}
