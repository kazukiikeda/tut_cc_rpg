#include "CollisionObject.h"

#include <math.h>

CollisionObject::CollisionObject()
{
	x = r = 0;
	y = 11 * 32;
	id = OBJECT_UNDEFINED;
}

GAME_COLLISION_OBJ_ID CollisionObject::GetObjectID()
{
	return id;
}

float CollisionObject::GetPosX()
{
	return x;
}

float CollisionObject::GetPosY()
{
	return y;
}

float CollisionObject::GetRadius()
{
	return r;
}

void CollisionObject::seteFlag(bool flag){
	eFlag == flag;
}

bool CollisionObject::IsCollision(CollisionObject* Obj)
{
	if (Obj->GetObjectID() == id)
		return false;

	//�������v�Z
	float Dist_x = Obj->GetPosX() - this->x;
	float Dist_y = Obj->GetPosY() - this->y;
	float Dist = sqrt(Dist_x*Dist_x + Dist_y*Dist_y);
	//Dist_x = sqrt(Dist_x * Dist_x);
	//�����Ƒ���̑̂̑傫���̘a���������Z����Γ�����
	//if (Dist_x <= this ->r + Obj->GetRadius())
	if (Dist <= this->r + Obj->GetRadius())
		return true;

	return false;
}
int CollisionObject::getObject_num(){
	return Object_num;
}
bool CollisionObject::geteFlag(){
	return eFlag;
}
