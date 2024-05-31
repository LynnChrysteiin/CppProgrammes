/*
你有一个破损的键盘。键盘上的所有键都可以正常工作，但有时Home键或者End键会自
动按下。你并不知道键盘存在这一问题，而是专心地输入英文单词，甚至连显示器都没瞧一眼。
当你看显示器时，展现在你面前的是一段悲剧的文本。你的任务是计算这段文本有几个单词。
输入包含多组数据。每组数据占一行，包含不超过20000个英文字母、空格、字符“[”或者“]”（这多达20000个字符的数据会显示在一行，不用担心会换行）。
其中字符“[”表示Home键（将光标定位到一行的开头），“]”表示End键（将光标定位到一行的结尾）。输入结束标志为文件结束符（EOF）。输入文本不超过50kB。
对于每组数据，输出一个数字，即这一行悲剧文本中共有几个单词（以空格分隔的连续字符串为一个单词）。
比如，输入：
This is a [Beiju] text
得到的悲剧文本是：
BeijuThis is a  text
因此，共有4个单词。
而输入：
This[     ]is[ ]a [Beiju] text
得到的悲剧文本是：
Beiju      Thisisa  text
因此，共有3个单词。
本程序用带头结点的单链表实现，请编写其中的count函数，实现统计单词个数的功能。请不要尝试使用数组实现，那样会导致程序运行超时。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct node
{
    char data;
    struct node *next;
};

struct node *create(char text[])
{
    int i;
    struct node *current;                              // 当前插入位置指针
    struct node *tail;                                 // 尾指针
    struct node *head;                                 // 头指针
    head = (struct node *)malloc(sizeof(struct node)); // 头结点
    head->next = NULL;
    current = head; // 当前位置指针指向头结点
    tail = head;    // 尾指针也指向头结点
    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] == '[')
        { // 当前位置指针回到最前面
            current = head;
        }
        else if (text[i] == ']')
        { // 当前位置指针移到最后面
            current = tail;
        }
        else
        { // 在当前位置指针后面插入结点
            struct node *p;
            p = (struct node *)malloc(sizeof(struct node));
            p->data = text[i];
            p->next = current->next;
            current->next = p;
            current = p;
            if (current->next == NULL)
                tail = current; // 当前位置在最后面，则需要修改tail指针
        }
    }
    return head;
}
int count(struct node *head)
{
    // 请在此输入你的代码，统计单词数目并返回
    int num = 0;
    struct node *p;
    for (p = head->next; p != NULL; p = p->next)
        if (p->data == ' ' && p->next != NULL && p->next->data != ' ')
            num++;
    if (head->next != NULL && head->next->data != ' ')
        num++;
    return num;

    // 函数形参为链表头指针，注意，其中第一个结点是头结点
}
int main()
{
    // freopen("input2.txt","r",stdin);
    // freopen("output2.txt", "w", stdout);
    char text[100005];
    struct node *head, *p;
    int num;
    while (gets(text) != NULL)
    {
        head = create(text);
        // for(p=head->next; p!=NULL; p=p->next)
        //     printf("%c",p->data);
        // printf("\n");
        num = count(head);
        printf("%d\n", num);
    }

    // printf("%.2f\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}