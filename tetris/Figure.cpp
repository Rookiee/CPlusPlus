#include "Tetris.h"
#include "Common.h"
#include <stdio.h>
#include <time.h>
#include <random>

// 游戏类对象
extern Game tetrisGame;

// 形状的构造函数，创建随机形状
Figure::Figure(){
    
    // 随机获得形状
    int numFigure = rand() % NUM_FIGURE;
    
    // 创建形状
    New(numFigure);
}

// 形状构造函数，创建指定形状
Figure::Figure(int numFigure){
    New(numFigure);
}

// 形状的析构函数
Figure::~Figure(){
}

// 显示形状，显示形状中的每个方块
void Figure::Draw() const{
    int i;
    for(i=0; i<NUM_FIGURE_BLOCK; ++i){
        data[i].Draw();
    }
}

// 创建新的形状
void Figure::New(int numFigure){
    
    int i;

    // 如果创建的形状是系统支持的形状
    if(numFigure>=0 && numFigure < NUM_FIGURE){
        
        // 如果不是O字形则形状可以旋转
        canRotate = (numFigure !=0 );

        // 创建的形状初始状态为顶部居中
        posX = NUM_BLOCKS_X / 2;
        posY = NUM_BLOCKS_Y - 2;
        
        // 判断是否有足够的空间创建该形状，如果没有则游戏结束
        if(tetrisGame.GetMap(posX, posY+1)==1 && 
            tetrisGame.GetStatus()) {
            tetrisGame.SetStatus(false);
            return;
        }
        
        // 分别设置组成形状的每个方块的位置
        for(i=0; i<NUM_FIGURE_BLOCK; ++i){
            data[i].SetPosX(posX + image[numFigure][i][0]);
            data[i].SetPosY(posY + image[numFigure][i][1]);
        }
    }
}

// 向左旋转形状
bool Figure::Rotate(){
    int i;
    
    // 如果不可以旋转则返回False
    if(!canRotate)
        return false;
  
    // 依次判断每个方块是否可以移动到旋转后的位置
    for(i=0; i<4; ++i){
        
        // 有任何一个方块不可以移动则返回False
        if(!data[i].CanRotate(posX, posY)){
            return false;
        }
    }
  
    // 旋转形状，移动每个方块到指定位置
    for(i=0; i<4; ++i){
        data[i].Rotate(posX, posY);
    }
    return true;
}

// 移动形状一定的位移
bool Figure::Translate(const int offsetX, const int offsetY) {

    int i;

    // 次判断每个方块是否可以移动到指定位置
    for (i=0; i<4; ++i){
        if(!data[i].CanTranslate(offsetX, offsetY))
            return false;
    }

    // 分别移动每个方块
    for(i=0; i<4; ++i){
        data[i].Translate(offsetX, offsetY);
    }

    // 设置新的位置
    SetPosX(posX+offsetX);
    SetPosY(posY+offsetY);
    return true;
}

