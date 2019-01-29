#pragma once
#ifndef GAME_LEVEL
#define GAME_LEVEL
#include <iostream>
#include <vector>
#include "game_object.h"

/*
����0����ש�飬��ʾ�ؿ��пյ�����
����1��һ����Ӳ��ש�飬���ɱ��ݻ�
����1�����֣�һ���ɱ��ݻٵ�ש�飬��ͬ����������ש�����ɫ
*/

class GameLevel
{
public:

	std::vector<GameObject> bricks;
	GameLevel();
	~GameLevel();
	//���ļ��м��عؿ�
	void Load(const GLchar*file,GLuint levelWidth, GLuint levelHeight);
	//��Ⱦ�ؿ�
	void Draw(SpriteRenderer &render);
	// ���һ���ؿ��Ƿ������ (���зǼ�Ӳ�Ĵ�ש�����ݻ�)
	GLboolean IsComplete();

private:
	// ��ש�����ݳ�ʼ���ؿ�
	void init(std::vector<std::vector<GLuint>> tileData, GLuint levelWidth,GLuint levelHeight);
};

#endif // !GAME_LEVEL
