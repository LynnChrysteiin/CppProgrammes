/*
    @Title: Snake Game Main Function File
    @Author: LynnChrysteiin
    @Updated: 2024/04/14 12:37
*/

#include "snake.cpp"

// 主函数
int main()
{
    const int WIDTH = 22;
    const int HEIGHT = 22;
    const int SPEED = 1;
    const Direction ORIGIN_DIRECTION = LEFT;
    const int ORIGIN_LENGTH = 3;
    const char WALL_SYMBOL = '.';
    const char FOOD_SYMBOL = '*';
    const std::pair<char, char> SNAKE_SYMBOL = {std::make_pair('@', 'O')};
    Game game(WIDTH, HEIGHT, SPEED, ORIGIN_DIRECTION, ORIGIN_LENGTH,
              WALL_SYMBOL, FOOD_SYMBOL, SNAKE_SYMBOL);

    std::cout << WIDTH << " " << HEIGHT << " " << SPEED << " " << ORIGIN_DIRECTION << " " << ORIGIN_LENGTH << " " << WALL_SYMBOL << " " << FOOD_SYMBOL << " " << SNAKE_SYMBOL.first << " " << SNAKE_SYMBOL.second << std::endl;
    return 0;
}

/*
    Copyright 2024 LynnChrysteiin
    Github: https://www.github.com/LynnChrysteiin/
*/