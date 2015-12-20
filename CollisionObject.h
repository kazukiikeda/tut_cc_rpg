//CollisionObject.h
#pragma once
#include <string>

//当たり判定オブジェクトを記述する列挙体
enum GAME_COLLISION_OBJ_ID
{
	OBJECT_PLAYER,
	OBJECT_ENEMY,
	OBJECT_ITEM,
	OBJECT_NPC,
	OBJECT_DOOR,
	OBJECT_WALL,
	OBJECT_ALLNUM,
	OBJECT_UNDEFINED = 0xFFFFFFFF,

};
//当たり判定オブジェクト基底クラス
class CollisionObject
{
protected:
	float x, y, r;
	GAME_COLLISION_OBJ_ID id;
	int Object_num;
	std::string Object_ID;
	std::string Object_next;
	int Object_nextX;
	std::string Object_text;
public:
	CollisionObject();
	virtual int getObject_num();
	virtual GAME_COLLISION_OBJ_ID GetObjectID();
	virtual std::string getObjectID();
	virtual std::string getObjectnext();
	virtual int getObjectnextX();
	virtual std::string getObjectText();
	float GetPosX();
	float GetPosY();
	float GetRadius();
	int Current(CollisionObject* Obj);
	virtual void setDirType(int i);
	virtual void dead();
	//引数のオブジェクトと接触しているか判定する
	virtual bool IsCollision(CollisionObject* Obj);
};