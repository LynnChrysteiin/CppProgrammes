/*
    @Title: Snake Game Source File
    @Author: LynnChrysteiin
    @Updated: 2024/04/14 12:37
*/

#include "snake.h"

// 定义墙壁类的方法
Wall::Wall() : width(12), height(12), symbol('*') {}
Wall::Wall(int width, int height, char symbol) : width(width), height(height), symbol(symbol) {}
Wall::~Wall() {}
void Wall::draw(std::vector<std::vector<char>> &screen)
{
    // 把墙壁字符填充到屏幕数组中
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                screen[i][j] = symbol;
}

// 定义食物类的方法
Food::Food() : symbol('+'), domain(std::make_pair(20, 20)) { generate(); }
Food::Food(char s, int width, int height) : symbol(s), domain(std::make_pair(width - 2, height - 2))
{
    generate();
}
void Food::generate()
{
    int x = rand() % domain.first + 1;
    int y = rand() % domain.second + 1;
    pos = std::make_pair(x, y); //
}
Food::~Food() {}
void Food::eat()
{
    generate();
}
void Food::draw(std::vector<std::vector<char>> &screen)
{
}

// 定义蛇类的方法
Snake::Snake() : len(1), dir(RIGHT)
{
    body.push_back(std::make_pair(0, 0));
    symbol = std::make_pair('O', 'o');
}
Snake::Snake(int len, Direction dir, std::pair<char, char> symbol)
    : len(len), dir(dir), symbol(symbol) {}
Snake::~Snake() {}
void Snake::setDirection(Direction dir) { this->dir = dir; }
void Snake::move(Direction dir) {}
bool Snake::collidesWithSelf() {}
bool Snake::collidesWith(Wall wall) {}
bool Snake::collidesWith(Food food) {}


// 定义游戏类的方法
Game::Game() : score(0), speed(1), isOver(false), snake(), food(), wall()
{
    screen = std::vector<std::vector<char>>(22, std::vector<char>(22, ' '));
}
Game::Game(int width, int height, int speed, Direction dir, int length,
           char wallSymbol, char foodSymbol, std::pair<char, char> snakeSymbol)
{
    score = 0;
    this->speed = speed;
    isOver = false;
    snake = Snake(length, dir, snakeSymbol);
    food = Food(foodSymbol, width, height);
    wall = Wall(width, height, wallSymbol);
    screen = std::vector<std::vector<char>>(height, std::vector<char>(width, ' '));
}
Game::~Game() {}
void Game::start() {}
void Game::update() {}
void Game::end() {}
void Game::pause() {}
void Game::resume() {}
void Game::restart() {}