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
bool CollisionObject::IsCollision(CollisionObject* Obj)
{
	if (Obj->GetObjectID() == id)
		return false;

	//‹——£‚ðŒvŽZ
	float Dist_x = Obj->GetPosX() - this->x;
	float Dist_y = Obj->GetPosY() - this->y;
	float Dist = sqrt(Dist_x*Dist_x + Dist_y*Dist_y);
	//Ž©•ª‚Æ‘ŠŽè‚Ì‘Ì‚Ì‘å‚«‚³‚Ì˜a‚ª‹——£‚æ‚è’Z‚¯‚ê‚Î“–‚½‚è	
	if (Dist <= this->r + Obj->GetRadius())
		return true;

	return false;
}
int CollisionObject::getObject_num(){
	return Object_num;
}
std::string CollisionObject::getObjectID(){
	return Object_ID;
}
std::string CollisionObject::getObjectnext(){
	return Object_next;
}
int CollisionObject::getObjectnextX(){
	return Object_nextX;
}
std::string CollisionObject::getObjectText(){
	return Object_text;
}
int CollisionObject::Current(CollisionObject* Obj){
	float Dist = Obj->GetPosX() - this->x;
	return (Dist > 0 ? 1 : -1);
}
void CollisionObject::setDirType(int i){}
void CollisionObject::dead(){}

