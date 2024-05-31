/* 
 * ʵ���� ���������Թ��������
 * 
 * �Թ�������ȡ������ѧ��һ���ŵ�ʵ�顣
 * ʵ���У���һֻ�����һ��û�ж��Ĵ���ӵ��ŷ��룬�ں������������ǽ�����н��ķ����γ��˶ദ�赲��
 * ���ӽ�����һ�����ڣ��ڳ��ڴ�������һ�����ң������������Թ���Ѱ�ҵ�·�Ե�����ڡ�
 * �ظ��������������ʵ�飬���������ڶ���ҵ����ڡ�
 * �����һ���㷨ʵ���Թ�������⡣
 * In  1   0   0   0
 * 1   0   1   1   0
 * 1   0   1   1   0
 * 1   1   0   1   1
 * 0   0   1   0   1
 * 1   1   1   0   Out
 * 
 * �����ⶨ������ֻ�������������ĸ������ƶ�������б���ƶ���
 * ��˲��������޽⣬ʵ�������и����Թ���ά���飬ʹ�ô���һ��·�������Գ���Ŀ����ԡ�
 */

#include <stdio.h>
#include <stdbool.h>

const int M = 6;
const int N = 5;

/* 0: ���� 1: ������ */
bool maze[M][N] = {
    {0, 1, 0, 0, 0},
    {1, 0, 1, 1, 0},
    {1, 0, 1, 1, 0},
    {1, 1, 0, 1, 1},
    {0, 0, 1, 0, 1},
    {1, 1, 1, 0, 0}};

/* 0: δ�߹� 1: ���߹� */
bool mark[M][N] = {0};

/* box�ṹ��, ���������ǰ��, ���ڻ���·�� */
typedef struct box
{
    int x;
    int y;
    int pre;
} box;

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
    printf("��%2d��: (%d, %d)\n", ++step, queue[i].x, queue[i].y);
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

    /* ����������� */
    while (front < rear && !found) // �������Ƿ�Ϊ����δ�ҵ�����
    {
        cur = front;
        front++;
        for (int i = 0; i < 4; i++) // ���Ե�ǰλ�õ��ĸ�����
        {
            row = queue[cur].x + dir[i][0];
            col = queue[cur].y + dir[i][1];
            if (row < 0 || row >= M || col < 0 || col >= N) // Խ��
            {
                continue;
            }
            if (maze[row][col] == 0 && mark[row][col] == 0) // δ�߹��ҿ���
            {
                queue[rear].x = row;
                queue[rear].y = col;
                queue[rear].pre = cur;
                rear++;
                mark[row][col] = 1;
            }
            if (row == M - 1 && col == N - 1) // �������
            {
                found = 1;
                break;
            }
        }
    }

    printf("********************�� �� �� �� �� �� �� ��********************\n");
    printf("****             ʵ����  ������   �Թ��������             ****\n");
    printf("***************************************************************\n\n");
    if (found)
    {
        printf("�ҵ�·��!\n");
        printPath(rear - 1);
    }
    else
    {
        printf("δ�ҵ�·��!\n");
    }

    return 0;
}
