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

			if (Obj1->IsCollision(Obj2)){
				code = TASK_NEXTSCENE;
				num = Obj2->getObject_num();
				if (Obj2->GetObjectID() == OBJECT_ENEMY){
					code = TASK_BATTLESCENE;
				}
				if (Obj2->GetObjectID() == OBJECT_NPC){
					code = TASK_TALK;		
				}
			}
			
		}
	}
	
	return code;
}
void CollisionCheck::checker(){
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
			if (Obj2->GetObjectID() == OBJECT_NPC){
				if (Obj1->Current(Obj2) < 0){
					Obj2->setDirType(2);
				}
				else{
					Obj2->setDirType(1);
				}
			}
			if (Obj2->GetObjectID() == OBJECT_ENEMY && Obj2->getObject_num() == num){
				Obj2->dead();
			}
		}
	}
}