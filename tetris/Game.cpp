#include<stdio.h>
#include<string.h>

#include "Common.h"
#include "Tetris.h"

// 当前正在下落的形状对象
extern Figure tetrisFigure;

// 游戏类构造函数
Game::Game(){

  // 设置界面中宽和高各可以容纳方块
  num_col = (WINDOW_WIDTH)/(BLOCK_SIZE+BLOCK_SPACING);
  num_row = (WINDOW_HEIGHT)/(BLOCK_SIZE+BLOCK_SPACING);
  
  status = true;
}

// 析构函数
Game::~Game(){
}


// 显示游戏界面
void Game::Draw() const {
    
    int i,j;
    
    // 使用OpenGL库函数显示边界
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.2,0.1);
    glVertex3f(0,0,0);
    glVertex3f(WINDOW_WIDTH-BLOCK_SIZE/2,0,0);
    glVertex3f(WINDOW_WIDTH-BLOCK_SIZE/2,WINDOW_HEIGHT,0);
    glVertex3f(0,WINDOW_HEIGHT,0);
    glEnd();

    // 显示游戏
    // 如果还没有失败，游戏继续
    if(status){

        Block block = Block();
        
        // 扫描map数组，根据内容显示所有需要显示的方块
        for(i=0; i < num_row; ++i) {
            for(j = 0 ; j < num_col; ++j) {
                if(map[i][j]) {
                    // 该坐标位置需要显示方块
                    block.SetPosX(j);
                    block.SetPosY(i);
                    block.Draw();
                }
            }
        }
    } else {
        // 游戏已经失败，游戏结束，显示GAME OVER
        char string[]="GAME OVER";
        int len;
        
        glRasterPos2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
        
        // 获取游戏结束后字符串长度
        len = (int) strlen(string);
        for (i = 0; i < len; i++) {
            //依次显示每个字母
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
        }
    }
}

// 创建新游戏
void Game::New(){
    
    // 初始化界面中的每个方块区域：初始化map数组
    int i,j;
    for(i=0; i<num_row; ++i){
        for(j=0; j<num_col; ++j){
            map[i][j] = EMPTY;
        }
    }
    
    // 创建第一个形状
    tetrisFigure.New(rand()%NUM_FIGURE);
    
    // 设置失败标志为False
    status = true;
}

// 更新游戏界面状态
void Game::Update(const Figure &figure){
    int i,num;
    
    // 根据形状设置对应位置方块标志
    // 每个形状都由四个方块组成
    for(i=0; i<NUM_FIGURE_BLOCK; ++i){
        map[figure.data[i].GetPosY()][figure.data[i].GetPosX()] = USED;
    }

    // 如果存在已经满的行，消除该行
    // 获得最新形状的Y坐标
    num=figure.GetPosY();
    
    // 从num位置开始判断是否行已满
    for(i=num+2; i>=num-2; --i){
        // 如果行满则清除该行
        if(RowIsFull(i)){
            ClearRow(i);
        }
    }
}

// 清除行，使一行的方块都消失，其他行自动向下移动
void Game::ClearRow(const int row){
    
    int i,j;
    
    // 如果输入无效则返回
    if(row<0 || row>=num_row)
        return;

    // 扫描map，将每一行都向下移动
    for(i=row; i<num_row-2; ++i)
        for(j=0; j<num_col; ++j)
            map[i][j]=map[i+1][j];
    
    // 将最上面一行内容清空
    for(j=0; j<num_col; ++j)
        map[num_row-1][j]=0;
}

// 判断行是否已经被方块占满
bool Game::RowIsFull(const int row) const {
    int i;
  
    // 如果输入无效则返回False
    if(row<0 || row>=num_row)
        return false;
    
    // 扫描map中的指定数据查看是否为空
    for(i=0; i<num_col; ++i)
        // 如果该行中任何一个位置为空，则该行没有满
        if(map[row][i]==EMPTY)
            return false;

    return true;
}

// 获得游戏界面中指定坐标区域的方块是否显示
int Game::GetMap(const int x, const int y) const {
    if((x<0) || (y<0) || (x>= num_col) 
        || (y>=num_row))
        return -1;
    else
        return map[y][x];
}
