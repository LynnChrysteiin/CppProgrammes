/*
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。
红司令部，City 1，City 2，……，City n，蓝司令部

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。
双方的武士编号都是从1开始计算。红方制造出来的第n个武士，编号就是n。同样，蓝方制造出来的第n个武士，编号也是n。
武士在刚降生的时候有一个生命值。

在每个整点，双方的司令部中各有一个武士降生。
红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。
蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。

制造武士需要生命元。
制造一个初始生命值为m的武士，司令部中的生命元就要减少m个。
如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。

给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。
一共有两种事件，其对应的输出样例如下：

1) 武士降生
输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
表示在4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5，降生后蓝魔司令部里共有2个lion武士。（为简单起见，不考虑单词的复数形式）注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。

2) 司令部停止制造武士
输出样例： 010 red headquarter stops making warriors
表示在10点整，红方司令部停止制造武士

输出事件时：
首先按时间顺序输出；
同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数，代表测试数据组数。
每组测试数据共两行。
第一行：一个整数M。其含义为， 每个司令部一开始都有M个生命元( 1 <= M <= 10000)。
第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000。

输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
对每组测试数据，首先输出"Case:n" n是测试数据的编号，从1开始 。
接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。

样例输入
1
20
3 4 5 6 7

样例输出
Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
000 blue lion 1 born with strength 6,1 lion in blue headquarter
001 red lion 2 born with strength 6,1 lion in red headquarter
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
004 blue headquarter stops making warriors
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

map<int, string> warrior_name = {
    {0, "dragon"},
    {1, "ninja"},
    {2, "iceman"},
    {3, "lion"},
    {4, "wolf"}};

class Headquarter
{
private:
    string name;
    int power;
    vector<int> warrior_order; // 长度5, 值为0-4
    vector<int> warrior_count; // 长度5, 分别代表dragon, ninja, iceman, lion, wolf的数量
    int warrior_id = 0;
    int current_warrior_index = 0;
    bool making = true;
    int count = 0; // 用于判断是否所有武士都不能制造了

public:
    Headquarter(string name, int power, vector<int> warrior_order) : name(name), power(power), warrior_order(warrior_order), warrior_count(5, 0) {}
    ~Headquarter() = default;
    bool isMaking() const { return making; }
    void tryMakeWarrior(int time, vector<int> hp_warrior)
    {
        if (!making)
            return;
        if (power >= hp_warrior[warrior_order[current_warrior_index]])
        {
            string warrior_name = ::warrior_name[warrior_order[current_warrior_index]];
            int warrior_hp = hp_warrior[warrior_order[current_warrior_index]];
            int warrior_amount = ++warrior_count[warrior_order[current_warrior_index]];
            power -= hp_warrior[warrior_order[current_warrior_index]];
            warrior_id++;
            current_warrior_index = (current_warrior_index + 1) % 5;
            cout << setw(3) << setfill('0') << time << " " << name << " " << warrior_name << " " << warrior_id << " born with strength " << warrior_hp << ","
                 << warrior_amount << " " << warrior_name << " in " << name << " headquarter" << endl;
            count = 0;
        }
        else
        {
            if (count == 5)
            {
                cout << setw(3) << setfill('0') << time << " " << name << " headquarter stops making warriors" << endl;
                making = false;
                return;
            }
            current_warrior_index = (current_warrior_index + 1) % 5;
            count++;
            tryMakeWarrior(time, hp_warrior);
        }
    }
};

void mainloop(int m, const vector<int> hp_warrior)
{
    vector<int> warrior_order_red = {2, 3, 4, 1, 0};
    vector<int> warrior_order_blue = {3, 0, 1, 2, 4};
    Headquarter red("red", m, warrior_order_red);
    Headquarter blue("blue", m, warrior_order_blue);
    int time = 0;
    while (red.isMaking() || blue.isMaking())
    {
        red.tryMakeWarrior(time, hp_warrior);
        blue.tryMakeWarrior(time, hp_warrior);
        time++;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<int> hp_warrior(6);
        for (int j = 0; j < 5; j++)
            cin >> hp_warrior[j];
        cout << "Case:" << i + 1 << endl;
        mainloop(m, hp_warrior);
    }
}