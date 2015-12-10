//CollisionObject.h
#pragma once

//当たり判定オブジェクトを記述する列挙体
enum GAME_COLLISION_OBJ_ID
{
	OBJECT_PLAYER,
	OBJECT_ENEMY,
	OBJECT_ITEM,
	OBJECT_NPC,
	OBJECT_DOOR,
	OBJECT_GRAND,
	OBJECT_ALLNUM,
	OBJECT_UNDEFINED = 0xFFFFFFFF,

};
/*
enum CHARACTER_DIRECTION_TYPE
{
	CHARACTER_DIR_UP,
	CHARACTER_DIR_RIGHT,
	CHARACTER_DIR_DOWN,
	CHARACTER_DIR_LEFT,
};*/

//当たり判定オブジェクト基底クラス
class CollisionObject
{
protected:
	float x, y, r;
	GAME_COLLISION_OBJ_ID id;
	int Object_num;
public:
	CollisionObject();
	virtual int getObject_num();
	GAME_COLLISION_OBJ_ID GetObjectID();

	float GetPosX();
	float GetPosY();
	float GetRadius();
	int Current(CollisionObject* Obj);
	virtual void setDirType(int i);
	virtual void dead();
	//引数のオブジェクトと接触しているか判定する
	virtual bool IsCollision(CollisionObject* Obj);
};