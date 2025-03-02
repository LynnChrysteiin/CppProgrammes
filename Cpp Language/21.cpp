/*

魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。

红司令部，City 1，City 2，……，City n，蓝司令部

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值这两种属性。
有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。
双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。

不同的武士有不同的特点。
dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。
ninja可以拥有两件武器。编号为n的ninja降生时即获得编号为 n%3 和 (n+1)%3的武器。
iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。
lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。
wolf没特点。

请注意，在以后的题目里，武士的士气，生命值，忠诚度在其生存期间都可能发生变化，都有作用，武士手中的武器随着使用攻击力也会发生变化。
武士在刚降生的时候有一个生命值。
在每个整点，双方的司令部中各有一个武士降生。

红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序循环制造武士。
蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序循环制造武士。

制造武士需要生命元。
制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。
给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。
一共有两种事件，其对应的输出样例如下：

1) 武士降生
输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
表示在 4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5,降生后蓝魔司令部里共有2个lion武士。(为简单起见，不考虑单词的复数形式)注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。
如果造出的是dragon，那么还要输出一行，例：

It has a arrow,and it's morale is 23.34
表示该dragon降生时得到了arrow,其士气是23.34（为简单起见，本题中arrow前面的冠词用a,不用an，士气精确到小数点后面2位，四舍五入）

如果造出的是ninja，那么还要输出一行，例：
It has a bomb and a arrow
表示该ninja降生时得到了bomb和arrow。

如果造出的是iceman，那么还要输出一行，例：
It has a sword
表示该iceman降生时得到了sword。

如果造出的是lion，那么还要输出一行，例：
It's loyalty is 24
表示该lion降生时的忠诚度是24。

2) 司令部停止制造武士
输出样例： 010 red headquarter stops making warriors
表示在 10点整，红方司令部停止制造武士

输出事件时：
首先按时间顺序输出；
同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数,代表测试数据组数。
每组测试数据共两行。
第一行，一个整数M。其含义为： 每个司令部一开始都有M个生命元( 1 <= M <= 10000)
第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000

输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
对每组测试数据，首先输出“Case:n" n是测试数据的编号，从1开始
接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。

样例输入
1
20
3 4 5 6 7

样例输出
Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
It has a bomb
000 blue lion 1 born with strength 6,1 lion in blue headquarter
It's loyalty is 14
001 red lion 2 born with strength 6,1 lion in red headquarter
It's loyalty is 9
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
It has a arrow,and it's morale is 3.67
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
It has a sword and a bomb
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
It has a bomb
004 blue headquarter stops making warriors

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>

std::map<int, std::string> warrior_names = {
    {0, "dragon"},
    {1, "ninja"},
    {2, "iceman"},
    {3, "lion"},
    {4, "wolf"}};

std::map<int, std::string> weapon_names = {
    {0, "sword"},
    {1, "bomb"},
    {2, "arrow"}};

class Warrior
{
private:
    int id;
    int hp;

protected:
    int n_weapon;
    int *weapons;

public:
    Warrior(int id, int hp) : id(id), hp(hp), n_weapon(0), weapons(NULL) {}
    virtual ~Warrior()
    {
        if (weapons)
            delete[] weapons;
    }
    virtual void print_extra_info() = 0;
};

class Dragon : public Warrior
{
private:
    float morale;

public:
    Dragon(int id, int hp, float morale) : Warrior(id, hp), morale(morale)
    {
        n_weapon = 1;
        weapons = new int[1];
        weapons[0] = id % 3;
    }
    ~Dragon() = default;
    void print_extra_info() override
    {
        std::cout << "It has a " << weapon_names[weapons[0]] << ",and it's morale is " << std::fixed << std::setprecision(2) << morale << std::endl;
    }
};

class Ninja : public Warrior
{
public:
    Ninja(int id, int hp) : Warrior(id, hp)
    {
        n_weapon = 2;
        weapons = new int[2];
        weapons[0] = id % 3;
        weapons[1] = (id + 1) % 3;
    }
    ~Ninja() = default;
    void print_extra_info() override
    {
        std::cout << "It has a " << weapon_names[weapons[0]] << " and a " << weapon_names[weapons[1]] << std::endl;
    }
};

class Iceman : public Warrior
{
public:
    Iceman(int id, int hp) : Warrior(id, hp)
    {
        n_weapon = 1;
        weapons = new int[1];
        weapons[0] = id % 3;
    }
    ~Iceman() = default;
    void print_extra_info() override
    {
        std::cout << "It has a " << weapon_names[weapons[0]] << std::endl;
    }
};

class Lion : public Warrior
{
private:
    int loyalty;

public:
    Lion(int id, int hp, int loyalty) : Warrior(id, hp), loyalty(loyalty) {}
    ~Lion() = default;
    void print_extra_info() override
    {
        std::cout << "It's loyalty is " << loyalty << std::endl;
    }
};

class Wolf : public Warrior
{
public:
    Wolf(int id, int hp) : Warrior(id, hp) {}
    ~Wolf() = default;
    void print_extra_info() override {}
};

class Headquarter
{
private:
    std::string name;                // 红/蓝
    int power;                       // 生命元
    std::vector<int> warrior_order;  // 长度5, 值为0-4
    std::vector<int> warrior_count;  // 用于记录每种武士的数量
    std::vector<Warrior *> warriors; // 用于存放所有武士
    int warrior_id = 0;              // 用于给武士编号
    int current_warrior_index = 0;   // 用于指示当前应该制造的武士, 0-4
    bool making = true;              // 用于判断是否还能制造武士
    int count = 0;                   // 用于判断是否所有武士都不能制造了

public:
    Headquarter(std::string name, int power, const std::vector<int> &warrior_order)
        : name(name), power(power), warrior_order(warrior_order), warrior_count(5, 0) {}
    ~Headquarter()
    {
        for (auto warrior : warriors)
            delete warrior;
    }
    bool is_making() const { return making; }
    void try_making_warrior(int time, const std::vector<int> &hp_warrior)
    {
        if (!making)
            return;
        int current_warrior_type = warrior_order[current_warrior_index];
        if (power >= hp_warrior[current_warrior_type])
        {
            std::string warrior_name = warrior_names[current_warrior_type];
            int warrior_hp = hp_warrior[current_warrior_type];
            int warrior_amount = ++warrior_count[current_warrior_type];
            power -= hp_warrior[current_warrior_type];
            warrior_id++;
            current_warrior_index = (current_warrior_index + 1) % 5;
            switch (current_warrior_type)
            {
            case 0:
                warriors.push_back(new Dragon(warrior_id, warrior_hp, (float)power / hp_warrior[current_warrior_type]));
                break;
            case 1:
                warriors.push_back(new Ninja(warrior_id, warrior_hp));
                break;
            case 2:
                warriors.push_back(new Iceman(warrior_id, warrior_hp));
                break;
            case 3:
                warriors.push_back(new Lion(warrior_id, warrior_hp, power));
                break;
            case 4:
                warriors.push_back(new Wolf(warrior_id, warrior_hp));
                break;
            }
            std::cout << std::setw(3) << std::setfill('0') << time << " " << name << " " << warrior_name << " " << warrior_id << " born with strength " << warrior_hp << ","
                      << warrior_amount << " " << warrior_name << " in " << name << " headquarter" << std::endl;
            warriors.back()->print_extra_info();
            count = 0;
        }
        else
        {
            if (count == 5)
            {
                std::cout << std::setw(3) << std::setfill('0') << time << " " << name << " headquarter stops making warriors" << std::endl;
                making = false;
                return;
            }
            current_warrior_index = (current_warrior_index + 1) % 5;
            count++;
            try_making_warrior(time, hp_warrior);
        }
    }
};

void mainloop(int power_hq, const std::vector<int> &hp_warrior)
{
    std::vector<int> warrior_order_red = {2, 3, 4, 1, 0};
    std::vector<int> warrior_order_blue = {3, 0, 1, 2, 4};
    Headquarter red("red", power_hq, warrior_order_red);
    Headquarter blue("blue", power_hq, warrior_order_blue);
    int time = 0;
    while (red.is_making() || blue.is_making())
    {
        if (red.is_making())
            red.try_making_warrior(time, hp_warrior);
        if (blue.is_making())
            blue.try_making_warrior(time, hp_warrior);
        time++;
    }
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        std::cin >> m;
        std::vector<int> hp_warrior(6);
        for (int j = 0; j < 5; j++)
            std::cin >> hp_warrior[j];
        std::cout << "Case:" << i + 1 << std::endl;
        mainloop(m, hp_warrior);
    }
}