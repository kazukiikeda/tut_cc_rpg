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
	TASK_BATTLESCENE,
	TASK_TALK,
	TASK_STOP,
};

//キャラクター・向き
enum CHARACTER_DIRECTION_TYPE
{
	CHARACTER_DIR_UP,
	CHARACTER_DIR_LEFT,
	CHARACTER_DIR_RIGHT,
	CHARACTER_DIR_DOWN,
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
	virtual std::string getID() = 0;
	virtual std::string getNext() = 0;
	virtual std::string getText() = 0;
	virtual int getNextX() = 0;
	virtual int checker() = 0;
	virtual void stop(int i) = 0;
	int num ;
	std::string ID;
	std::string next;
	std::string text;
	int nextPosX;
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
	virtual std::string getID();
	virtual std::string getNext();
	virtual std::string getText();
	virtual int getNextX();
	virtual void EntryTask(std::shared_ptr<GameTask> task);
	virtual int checker(){ return 0; };
	virtual void stop(int i);
};

std::shared_ptr<GameTask> CreateMapTask(int num_x, int num_y, int (*map)[], int befor, std::string id);

std::shared_ptr<GameTaskManager> CreateCollisionCheck();

std::shared_ptr<GameTask> CreatePlayerTask(int x, int y);

std::shared_ptr<GameTask> CreateTextTask(std::string textad, std::shared_ptr<GameTask> Root, std::string scene);

std::shared_ptr<GameTask> CreateEnemyTask(int x, int y, std::string ID, std::string movepattern, int Object_num);

std::shared_ptr<GameTask> CreateNPCTask(int x, int y, std::string ID, std::string movepattern, std::string text, int Object_num);

std::shared_ptr<GameTask> CreateWallTask(int x, int y, int ID, std::string nextscene, int nextX, std::string Handlead, int object_num);

std::shared_ptr<GameTask> CreateObjectTask(int x, int y, std::string ID, int Object_num, std::string nextscene, int nextPosX, std::string textad);

std::shared_ptr<GameTask> CreateScrollingTextTask(std::string textad);