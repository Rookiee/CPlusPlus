#ifndef TETRIS_H
#define TETRIS_H

#include "Common.h"

// Block类：方块类
class Block{
  
public:

    // 构造函数与析构函数
    Block();
    virtual ~Block();

    // 显示方块
    void Draw() const;

    // 判断方块是否可以跟着形状旋转到指定位置
    // 参数为该方块所属的形状的位置
    bool CanRotate(const int figureX,
                   const int figureY) const;

    // 形状旋转操作时方块移动到指定位置
    // 参数为该方块所属的形状的位置
    bool Rotate(const int figureX,
                const int figureY);

    // 方块移动指定的偏移
    // 参数为目标位置和当前位置之间的偏移
    bool Translate(const int offsetX,
                  const int offsetY);

    // 判断方块是否可以移动指定的偏移
    bool CanTranslate(const int offsetX,
                      const int offsetY) const;

    // 重载赋值操作符
    Block & operator = (Block & other){
        if(this != &other) {
            SetPosX(other.GetPosX());
            SetPosY(other.GetPosY());
        }
        return *this;
    }


    // 返回方块的位置
    int GetPosX() const { return posX; }
    int GetPosY() const { return posY; }

    // 设置方块的位置
    void SetPosX(const int x) { posX = x; }
    void SetPosY(const int y) { posY = y; }
private:

    // 方块的位置
    int posX, posY; 
};

// Figure类：游戏中使用的形状，形状由4个方块组成
class Figure {

public:

    // 构造函数及析构函数
    Figure(int numFigure);
    Figure();
    virtual ~Figure();
    
    // 创建新的形状
    void New(int numFigure);

    // 显示形状
    void Draw() const;
    
    // 旋转形状：向左旋转90度
    bool Rotate();

    // 移动形状
    bool Translate(const int offsetX,
                   const int offsetY);

    // 返回方块的位置
    int GetPosX() const { return posX; }
    int GetPosY() const { return posY; }

    // 设置方块的位置
    void SetPosX(const int x) { posX = x; }
    void SetPosY(const int y) { posY = y; }

public:

    // 组成形状的方块列表
    Block data[NUM_FIGURE_BLOCK];

private:

    // 形状的位置
    int posX, posY;

    // 是否可以变形
    bool canRotate;
};

// 游戏类
class Game{

public:
    // 构造函数和析构函数
    Game();
    virtual ~Game();
  
    // 显示界面
    void Draw() const;

    // 更新游戏界面状态
    void Update(const Figure &figure);
    
    // 判断行是否已经填满
    bool RowIsFull(const int row) const;
    
    // 清空行
    void ClearRow(const int row);
    
    // 创建新游戏
    void New();
    
    // 获得游戏界面中指定坐标区域的方块是否显示
    int GetMap(const int x, const int y) const;
    
    // 获得游戏运行状态：RUNNING或LOSE
    bool GetStatus() const { return status; }

    // 设置游戏运行状态
    void SetStatus(const bool newstatus) { status = newstatus; }

private:
    // 界面行数和列数
    int num_row, num_col;
    
    // 2D界面显示内容，数组中每个元素表示一个显示单元
    int map[MAX_BLOCK_NUM][MAX_BLOCK_NUM];
    
    // 游戏状态，True表示游戏运行，False表示游戏失败
    bool status;
};

#endif
