//GameTask.h
#pragma once

#include <list>
#include <memory>

//タスクの状態を記述する列挙体
enum GAMETASK_CODE
{
	TASK_FAILED,
	TASK_SUCCEEDED,
	TASK_NEXTSCENE,
	TASK_ONOTHERSCENE,
	TASK_TALK,
};

//キャラクター・向き
enum CHARACTER_DIRECTION_TYPE
{
	CHARACTER_DIR_UP,
	CHARACTER_DIR_RIGHT,
	CHARACTER_DIR_DOWN,
	CHARACTER_DIR_LEFT,
};

//キャラクター・動作状態
enum CHARACTER_MOVE_TYPE
{
	CHARACTER_MOVE,
	CHARACTER_STAY,
};

class GameTask
{
public:
	virtual bool Init() = 0;
	virtual GAMETASK_CODE Update() = 0;
	virtual GAMETASK_CODE Draw() = 0;
	virtual bool Exit() = 0;
	virtual int getnum() = 0;
	int Scx = 0;
	int num = 0;
};

class GameTaskManager : public GameTask
{
protected:
	std::list < std::shared_ptr<GameTask> > TaskList;

public:
	virtual bool Init();
	virtual GAMETASK_CODE Update();
	virtual GAMETASK_CODE Draw();
	virtual bool Exit();
	virtual int getnum();
	virtual void EntryTask(std::shared_ptr<GameTask> task);
};

std::shared_ptr<GameTask> CreateMapTask(int num_x, int num_y, int (*map)[], int befor);

std::shared_ptr<GameTaskManager> CreateCollisionCheck();

std::shared_ptr<GameTask> CreatePlayerTask();

std::shared_ptr<GameTask> CreateObjectTask(int x, int ID, int Object_num);

std::shared_ptr<GameTask> CreateEnemyTask(int x, int ID, int movepatern, bool flag, int Object_num);