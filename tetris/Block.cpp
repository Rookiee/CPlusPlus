#include "Common.h"
#include "Tetris.h"

// 游戏类对象
extern Game tetrisGame;

// 方块的构造函数
Block::Block(){
    // 设置默认位置居中，顶部
    posX = NUM_BLOCKS_X/2;
    posY = NUM_BLOCKS_Y-1;
}

// 方块析构函数，调用销毁函数
Block::~Block(){
}

// 显示方块
void Block::Draw() const {

    // 获得方块坐标
    int left = posX * (BLOCK_SIZE + BLOCK_SPACING) - BLOCK_SPACING;
    int right = left + BLOCK_SIZE;
    int bottom = posY * (BLOCK_SIZE + BLOCK_SPACING) - BLOCK_SPACING;
    int top = bottom + BLOCK_SIZE;

    // 调用OpenGL库函数显示方块
    glBegin(GL_QUADS);
    glColor3d(1,1,1);
    glVertex3f(left, top, 0);
    glVertex3f(right, top, 0);
    glVertex3f(right, bottom, 0);
    glVertex3f(left, bottom, 0);
    glEnd();
}

// 判断方块是否可以跟着形状旋转到指定位置
bool Block::CanRotate(const int figureX, const int figureY) const {

    // 方块位置与形状位置的位移
    int offsetX = posX - figureX;
    int offsetY = posY - figureY;

    // 如果方块位置即为形状位置，则旋转形状不需要调整方块位置
    if(!offsetX && !offsetY)
        return true;

    // 向左旋转90度的新位置
    int nextPosX = figureX - offsetY;
    int nextPosY = figureY + offsetX;
    
    // 目标位置已经有方块，则返回False
    if(tetrisGame.GetMap(nextPosX,nextPosY) != EMPTY)
        return false;

    // 临时变量存储旋转过程中经过的所有
    int tmpX[3], tmpY[3];

    // 分别对不同情况的旋转经过的区域进行判断
    // 需要保证这些区域都没有方块才可以旋转
    // tmpX[0]与tmpY[0]分别为旋转过程中左边及上边所达到的最远坐标
    tmpX[0]= figureX + offsetX - offsetY;
    tmpY[0]= figureY + offsetX + offsetY;
    
    if(abs(offsetX)>1 || abs(offsetY)>1) {
        // 如果旋转的为I字形状，且为离形状位置距离最远的方块
        // (tmpX[1], tmpY[1])与(tmpX[2], tmpY[2])为向左旋转过程中经过的区域
        tmpX[1]=(tmpX[0]+posX)/2;
        tmpX[2]=(tmpX[0]+figureX-offsetY)/2;
        tmpY[1]=(tmpY[0]+posY)/2;
        tmpY[2]=(tmpY[0]+figureY+offsetX)/2;
        
        // 如果这两个坐标位置有方块则无法旋转
        if(tetrisGame.GetMap(tmpX[1],tmpY[1])!=EMPTY || 
           tetrisGame.GetMap(tmpX[2], tmpY[2])!=EMPTY)
            return false;

    } else if(abs(offsetX)==1 && abs(offsetY)==1) {
        // 如果方块与形状位置45度相邻
        // (tmpX[1], tmpY[1])为向左旋转过程中经过的区域
        tmpX[1]=(tmpX[0]+posX)/2;
        tmpY[1]=(tmpY[0]+posY)/2;
        
        // 如果(tmpX[1], tmpY[1])坐标位置有方块则无法旋转
        if(tetrisGame.GetMap(tmpX[1],tmpY[1])!=EMPTY)
            return false;

    } else if(tetrisGame.GetMap(tmpX[0], tmpY[0])!=EMPTY)
        // 如果方块与形状相邻
        // tmpX[0], tmpY[0]为向左旋转过程中经过的区域
        return false;
    
    return true;
}

// 旋转形状，方块移动到目标位置
bool Block::Rotate(const int figureX, const int figureY){
    int offsetX = posX-figureX;
    int offsetY = posY-figureY;
   
    // 如果不可以移动，则返回False
    if(!CanRotate(figureX, figureY))
        return false;

    // 获得目标位置并移动方块到目标位置
    int nextPosX, nextPosY;
    nextPosX=figureX-offsetY;
    nextPosY=figureY+offsetX;
    SetPosX(nextPosX);
    SetPosY(nextPosY);
    return true;
}

// 移动方块位置
bool Block::Translate(const int offsetX, const int offsetY) {
    
    // 获得目标位置
    int nextPosX=posX+offsetX, nextPosY=posY+offsetY;
  
    // 目标位置已经有方块，则返回False
    if(tetrisGame.GetMap(nextPosX, nextPosY)!=EMPTY)
        return false;
    
    // 移动方块到目标位置
    SetPosX(nextPosX);
    SetPosY(nextPosY);
    return true;
}

// 判断方块是否可以移动
bool Block::CanTranslate(const int offsetX,const int offsetY) const {
    
    // 获得目标位置
    int nextPosX=posX+offsetX, nextPosY=posY+offsetY;
  
    // 目标位置已经有方块，则返回False
    if(tetrisGame.GetMap(nextPosX, nextPosY)!=EMPTY)
        return false;
    return true;
}
