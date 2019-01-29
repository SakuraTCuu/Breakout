#pragma once
#ifndef GAME_LEVEL
#define GAME_LEVEL
#include <iostream>
#include <vector>
#include "game_object.h"

/*
数字0：无砖块，表示关卡中空的区域
数字1：一个坚硬的砖块，不可被摧毁
大于1的数字：一个可被摧毁的砖块，不同的数字区分砖块的颜色
*/

class GameLevel
{
public:

	std::vector<GameObject> bricks;
	GameLevel();
	~GameLevel();
	//从文件中加载关卡
	void Load(const GLchar*file,GLuint levelWidth, GLuint levelHeight);
	//渲染关卡
	void Draw(SpriteRenderer &render);
	// 检查一个关卡是否已完成 (所有非坚硬的瓷砖均被摧毁)
	GLboolean IsComplete();

private:
	// 由砖块数据初始化关卡
	void init(std::vector<std::vector<GLuint>> tileData, GLuint levelWidth,GLuint levelHeight);
};

#endif // !GAME_LEVEL
