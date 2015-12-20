#include "CollisionCheck.h"
#include "CollisionObject.h"

std::shared_ptr<GameTaskManager> CreateCollisionCheck()
{
	return std::make_shared<CollisionCheck>();
}

GAMETASK_CODE CollisionCheck::Update()
{
	GAMETASK_CODE code = GameTaskManager::Update();
	
	for (auto it1 : TaskList)
	{
		CollisionObject* Obj1 = dynamic_cast<CollisionObject*>(it1.get());
		if (!Obj1)
			continue;

		for (auto it2 : TaskList)
		{
			CollisionObject* Obj2 = dynamic_cast<CollisionObject*>(it2.get());
			if (!Obj2)
				continue;
			if (Obj1->GetObjectID() == OBJECT_PLAYER || Obj2->GetObjectID() == OBJECT_PLAYER)
			if (Obj1->IsCollision(Obj2)){
				code = TASK_NEXTSCENE;
				num = Obj2->getObject_num();
				next = Obj2->getObjectnext();
				nextPosX = Obj2->getObjectnextX();
				ID = Obj2->getObjectID();
				text = Obj2->getObjectText();
				if (Obj2->GetObjectID() == OBJECT_ENEMY){
					code = TASK_BATTLESCENE;
				}
				if (Obj2->GetObjectID() == OBJECT_NPC){
					code = TASK_TALK;
				}
				if (Obj2->GetObjectID() == OBJECT_WALL){
					code = TASK_STOP;
				}
			}
			
		}
	}
	
	return code;
}
int CollisionCheck::checker(){
	for (auto it1 : TaskList)
	{
		CollisionObject* Obj1 = dynamic_cast<CollisionObject*>(it1.get());
		if (!Obj1)
			continue;

		for (auto it2 : TaskList)
		{
			CollisionObject* Obj2 = dynamic_cast<CollisionObject*>(it2.get());
			if (!Obj2)
				continue;
			if (Obj2->GetObjectID() == OBJECT_WALL && Obj2->getObject_num() == num && Obj1->GetObjectID() == OBJECT_PLAYER){
				if (Obj1->Current(Obj2) < 0){
					Obj1->setDirType(1);
				}
				else{
					Obj1->setDirType(2);
				}
				return Obj1->Current(Obj2);
			}
			if (Obj1->GetObjectID() == OBJECT_PLAYER && Obj2->getObject_num() == num && (Obj2->GetObjectID() == OBJECT_NPC || Obj2->GetObjectID() == OBJECT_DOOR)){
				
					if (Obj1->Current(Obj2) < 0){
						Obj2->setDirType(2);
						Obj1->setDirType(1);
					}
					else{
						Obj2->setDirType(1);
						Obj1->setDirType(2);
					}
			}
			if (Obj2->GetObjectID() == OBJECT_ENEMY && Obj2->getObject_num() == num){
				Obj2->dead();
			}
		}
	}
	return 0;
}
