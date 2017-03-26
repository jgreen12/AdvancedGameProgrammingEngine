//documentation on Lists https://msdn.microsoft.com/en-us/library/802d66bt.aspx
//This is not complete by any means, I will flesh it out as we continue the merging process, this is just a starting point.


//created by: Joshua Green
#include <list>
#include <string>
#include "GameObject.cpp"
using namespace std;

class Scene {
private:
	string SceneName;
	int NumOfObjects;
	list<GameObject> fullListOfObjects;
	list<GameObject>::iterator fullBeginIter;
protected:


public:
	Scene();
	void RemoveAllObjects();
	void AddObject(GameObject g);
	void UpdateObjects();
	void RemoveObject(GameObject g);
};


void Scene::RemoveObject(GameObject g) {
	fullListOfObjects.remove(g);
}

void Scene::UpdateObjects() {
	//should iterate through the list calling any update functions we define
}

void Scene::AddObject(GameObject g) {
	//simple method to add the objects to the list
	fullListOfObjects.push_front(g);
}

void Scene::RemoveAllObjects() {
	//clears all objects from the list
	fullListOfObjects.clear();
}




Scene::Scene() {
	SceneName = "New Scene";
	NumOfObjects = 0;
	fullBeginIter = fullListOfObjects.begin();
}