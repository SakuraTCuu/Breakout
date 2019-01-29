#include "game_level.h"
#include <fstream>
#include <sstream>
#include "resource_manager.h"

GameLevel::GameLevel()
{

}

GameLevel::~GameLevel()
{
}

void GameLevel::Load(const GLchar * file, GLuint levelWidth, GLuint levelHeight)
{
	// 清空过期数据
	this->bricks.clear();
	//从文件中加载
	GLuint tileCode;
	GameLevel level;
	std::string line;
	std::ifstream fstream(file);
	std::vector<std::vector<GLuint>> tileData;

	if(fstream)
	{
		while (std::getline(fstream,line))// 读取关卡文件的每一行
		{
			std::istringstream sstream(line);
			std::vector<GLuint> row;
			while (sstream >> tileCode)
				row.push_back(tileCode);
			tileData.push_back(row);
		}
		if (tileData.size() > 0)
			this->init(tileData, levelWidth, levelHeight);
	}
}

void GameLevel::Draw(SpriteRenderer & renderer)
{
	for (GameObject &tile : this->bricks)
		if (!tile.Destroyed)
			tile.Draw(renderer);
}

GLboolean GameLevel::IsComplete()
{
	return GLboolean();
}

void GameLevel::init(std::vector<std::vector<GLuint>> tileData, GLuint lvlWidth, GLuint lvlHeight)
{
	// 计算每个维度的大小
	GLuint height = tileData.size();
	GLuint width = tileData[0].size();
	GLfloat unit_width = lvlWidth / static_cast<GLfloat>(width);
	GLfloat unit_height = lvlHeight / height;
	// 基于tileDataC初始化关卡
	for (GLuint y = 0; y < height; y++)
	{
		for (GLuint x = 0; x < width; x++)
		{
			// 检查砖块类型
			if (tileData[y][x] == 1)
			{
				//不可被摧毁
				glm::vec2 pos(unit_width * x, unit_height * y);
				glm::vec2 size(unit_width, unit_height);
				GameObject obj(pos, size,
					ResourceManager::GetTexture("block_solid"),
					glm::vec3(0.8f, 0.8f, 0.7f)
				);

				obj.IsSolid = GL_TRUE;
				this->bricks.push_back(obj);
			}
			else if (tileData[y][x] > 1)
			{
				glm::vec3 color = glm::vec3(1.0f); // 默认为白色
				if (tileData[y][x] == 2)
					color = glm::vec3(0.2f, 0.6f, 1.0f);
				else if (tileData[y][x] == 3)
					color = glm::vec3(0.0f, 1.0f, 0.0f);
				else if (tileData[y][x] == 4)
					color = glm::vec3(0.8f, 0.8f, 0.4f);
				else if (tileData[y][x] == 5)
					color = glm::vec3(1.0f, 0.5f, 0.0f);

				glm::vec2 pos(unit_width * x, unit_height * y);
				glm::vec2 size(unit_width, unit_height);
				this->bricks.push_back(
					GameObject(pos, size, ResourceManager::GetTexture("block"), color)
				);
			}
		}
	}
}
