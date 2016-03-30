#ifndef COMMON_H
#define COMMON_H

// 引入OpenGL头文件
#include <OpenGL/OpenGL.h>

// 形状的数量
#define NUM_FIGURE 7

// 每个形状需要的方块数量
#define NUM_FIGURE_BLOCK 4

// 方块的边长：19像素
#define BLOCK_SIZE 19

// 方块之间的间距：1像素
#define BLOCK_SPACING 1

// 游戏界面宽或高最大容纳的方块数
#define MAX_BLOCK_NUM 100

// 游戏界面的宽度和高度
#define WINDOW_WIDTH 350
#define WINDOW_HEIGHT 500

// 界面上横纵坐标各可以容纳的方块数
#define NUM_BLOCKS_X WINDOW_WIDTH/ (BLOCK_SIZE+BLOCK_SPACING)
#define NUM_BLOCKS_Y WINDOW_HEIGHT/ (BLOCK_SIZE+BLOCK_SPACING)

// 用在游戏类的map二位数组中，
// 当坐标位置不显示方块时则为空
#define USED 1
#define EMPTY 0

// 游戏运行状态
#define RUNNING 1
#define LOSE 0

// 使用三维数组定义7中不同的形状
// 第一维表示7个不同的形状
// 第二维为组成形状的四个方块
// 第三维为每个方块坐标与形状坐标的偏移量
const int image[NUM_FIGURE][NUM_FIGURE_BLOCK][2] =
    {
        {
            // O字形状
            {0,0},
            {0,1},
            {1,1},
            {1,0}
        },
        {
            // I字形状
            {0,-1},
            {0,0},
            {0,1},
            {0,2}
        },
        {
            // J字形状
            {0,1},
            {-1,1},
            {-1,0},
            {-1,-1}
        },
        {
            // L字形状
            {0,1},
            {1,1},
            {1,0},
            {1,-1}
        },
        {
            // S字形状
            {-1,1}, 
            {-1,0}, 
            {0,0},
            {0,-1}
        },
        {
            // Z字形状
            {0,1},
            {0,0},
            {-1,0},
            {-1,-1}
        },
        {
            // T字形状
            {-1,0},
            {0,0},
            {1,0},
            {0,1}
        }
    };


#endif
