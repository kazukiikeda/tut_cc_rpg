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

//�����蔻��I�u�W�F�N�g���N���X
class CollisionObject
{
protected:
	float x, y, r;
	GAME_COLLISION_OBJ_ID id;
	int Object_num;
	bool eFlag;
	//bool grandcheck = false;
public:
	CollisionObject();
	int getObject_num();
	void seteFlag(bool flag);
	bool geteFlag();
	GAME_COLLISION_OBJ_ID GetObjectID();

	float GetPosX();
	float GetPosY();
	float GetRadius();

	//�����̃I�u�W�F�N�g�ƐڐG���Ă��邩���肷��
	virtual bool IsCollision(CollisionObject* Obj);
};