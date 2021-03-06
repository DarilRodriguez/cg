#include "cg/display.hpp"
#include "cg/Scene.hpp"

namespace cg {
	Scene::Scene() {
		camera = new cg::core::Camera(cg::display::window);
		camera->position = {0, 0};
	}
	
	void Scene::regist(cg::GameObject* object) {
		object->scene = this;
		go_wait_list.push_back(object);
	}
	
	void Scene::regist(cg::Component* object) {
		object->scene = this;
		components.push_back(object);
	}
	
	Scene::~Scene() {
		for (auto p : game_objects)
			delete p;
		
		game_objects.clear();
		
		delete camera;
	}
}
