//CollisionObject.h
#pragma once

//�����蔻��I�u�W�F�N�g���L�q����񋓑�
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

//�����蔻��I�u�W�F�N�g���N���X
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
	//�����̃I�u�W�F�N�g�ƐڐG���Ă��邩���肷��
	virtual bool IsCollision(CollisionObject* Obj);
};