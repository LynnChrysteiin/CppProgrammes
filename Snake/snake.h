/*
    @Title: Snake Game Header File
    @Author: LynnChrysteiin
    @Updated: 2024/04/14 12:37
*/


#include <iostream>
#include <fstream>
#include <windows.h>
#include <list>
#include <vector>

// 方向的枚举类型
enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

// 墙壁类
class Wall
{
private:
    int width;
    int height;
    char symbol;

public:
    Wall();
    Wall(int width, int height, char wallSymbol);
    ~Wall();
    void draw(std::vector<std::vector<char>> &screen);
};

// 食物类
class Food
{
private:
    char symbol;
    std::pair<int, int> pos;
    std::pair<int, int> domain; // 食物的生成范围

public:
    Food();
    Food(char s, int width, int height);
    ~Food();
    void eat();
    void generate();
    void draw(std::vector<std::vector<char>> &screen);
};

// 蛇类
class Snake
{
private:
    int len;
    std::pair<char, char> symbol;
    Direction dir;
    std::list<std::pair<int, int>> body;

public:
    Snake();
    Snake(int len, Direction dir, std::pair<char, char> symbol);
    ~Snake();
    void setDirection(Direction dir);
    void move(Direction dir);
    bool collidesWithSelf();
    bool collidesWith(Wall wall);
    bool collidesWith(Food food);
};

// 游戏类
class Game
{
private:
    int score;
    int speed;
    std::vector<std::vector<char>> screen;
    bool isOver;
    Snake snake;
    Food food;
    Wall wall;

public:
    Game();
    Game(int width, int height, int speed, Direction dir, int length,
         char wallSymbol, char foodSymbol, std::pair<char, char> snakeSymbol);
    ~Game();
    void start();
    void update();
    void end();
    void pause();
    void resume();
    void restart();
};
