#pragma once
#ifndef BALL_OBJECT_H_
#define BALL_OBJECT_H_
#include "game_object.h"

class BallObject : public GameObject
{
public:
	// ���״̬ 
	GLfloat   Radius;
	GLboolean Stuck; //�˶���ֹ

	BallObject();
	BallObject(glm::vec2 pos, GLfloat radius, glm::vec2 velocity, Texture2D sprite);

	glm::vec2 Move(GLfloat dt, GLuint window_width);
	void      Reset(glm::vec2 position, glm::vec2 velocity);

private:

};

#endif // !BALL_OBJECT_H_

