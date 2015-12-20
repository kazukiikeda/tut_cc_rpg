#include "ObjectTask.h"
#include "KeyDownChecker.h"
#include <fstream>
#include <string>
#include <sstream>

std::shared_ptr<GameTask> CreateObjectTask(int x, int y, std::string ID, int Object_num, std::string nextscene, int nextPosX, std::string textad)
{
	return std::make_shared<ObjectTask>(x, y, ID, Object_num, nextscene, nextPosX, textad);
}
ObjectTask::ObjectTask(){}
ObjectTask::ObjectTask(int x, int y, std::string id, int object_num, std::string nextscene, int nextPosX, std::string textad)
{
	ID = id;
	PosX = x * 32;
	PosY = y * 32;
	CollisionObject::id = OBJECT_DOOR;
	CollisionObject::y = PosY;
	Object_next = nextscene;
	Object_nextX = nextPosX;
	Object_num = object_num;
	Object_ID = id;
	Object_text = textad;
	std::ifstream ifs;
	std::string str = "Data/Object/" + id + ".txt";
	ifs.open(str.c_str());
	int i = 0;
	while (getline(ifs, str))
	{
		std::stringstream stream(str);
		std::string dumy;
		std::vector<std::string> buffer;
		while (getline(stream, dumy, ',')){
			if (i == 0){
				buf = dumy;
			}
			else if (i == 1){
				col.push_back(dumy);
			}
			else {
				buffer.push_back(dumy);
			}
		}
		if (i > 1)
			objectHandle.push_back(buffer);
		i++;
	}
	ifs.close();
	if (col.at(0) != "0"){
		r = std::stof(col.at(1));
		adjY = 0;
	}
	else
		adjY = std::stoi(col.at(1));
}
bool ObjectTask::Init()
{
	int Sizex, Sizey, Gr;
	Gr = LoadGraph(buf.c_str());
	GetGraphSize(Gr, &Sizex, &Sizey);
	LoadDivGraph(buf.c_str(), (Sizex * Sizey) / (32 * 32), Sizex / 32, Sizey / 32, 32, 32, GraphHandle);
	return true;
}

GAMETASK_CODE ObjectTask::Draw()
{
	CollisionObject::x = PosX + 32 * std::stoi(col.at(0));
	for (int x = 0; x < objectHandle.size() ; x++){
		for (int y = 0; y < objectHandle[x].size(); y++){
			DrawGraph((x+1) * 32 + PosX, PosY - 32 * y + adjY, GraphHandle[std::stoi(objectHandle[x][y])], true);
		}
	}
	return TASK_SUCCEEDED;
}

bool ObjectTask::Exit()
{
	for (int i = 0; i < 400; i++)
		DeleteGraph(GraphHandle[i]);
	return true;
}

void ObjectTask::setDirType(int i){
	DirType = (CHARACTER_DIRECTION_TYPE)i;
}