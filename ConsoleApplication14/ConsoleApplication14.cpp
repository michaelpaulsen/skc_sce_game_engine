#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <varargs.h>
#include <time.h>
#include <string>
//this is the thing that holds the data for entities..!
enum class cmp_types {
	NA = -1, 
	RB2D = 0,
	RB3D = 2,
	INTER = 10, 
	POS2D = 20,
	POS3D = 21,
	DISC = 30, 
	TXTDATA = 31, 
	DMG = 40, 
};
typedef cmp_types type_t; 
typedef long long UUID_t; 
//this is the main type of data for the entities that "live" in the world it 
//holds any data that entities need to interact. 
///TODO move this to its own file.
struct component {
	component(type_t type = type_t::NA) {
		this->UUID = time(0);
		this->type = type;
	}
	virtual bool Run(type_t type ...) = 0; 
	bool GetActive(void) {
		return this->isActive; 
	}
	[[nodiscard]] long long GetUUID() {
		return this->UUID; 
	}
	bool IsOfType(type_t type ){
		return this->type == type; 
	}
	type_t GetType() {
		return this->type; 
	}
	void ToggleActive() {
		this->isActive = !this->isActive; 
	}
	void Deactivate() {
		this->isActive = false; 

	}
	void Activate() {
		this->isActive = true; 
	}

private:
	type_t type; 
	UUID_t UUID;
	bool isActive = true;
};

//this is anything that moves or you can interact whith
// it is suposed to be a conainer for components..
///TODO move this to its own file.
struct entity {
	std::vector<component*> components; 
	//this is the components of the entity this is the only thing that is needed for 
	//an entity 
	component* GetComponetFromUUID(UUID_t UUID) {
		for (const auto& c : components) {
			if (UUID == c->GetUUID()) {
				return c; 
			}
		}
		return nullptr; 
	}
	component* GetFirstComponentOfType(type_t type) {
		for (const auto& c : components) {
			if (c->IsOfType(type)) {
				return c; 
			}
		}
	}
	component* GetFirstActiveComponentOfType(type_t type) {
		for (const auto& c : components) {
			if (c->IsOfType(type) && c->GetActive()) {
				return c;
			}
		}
	}
};
//this is the system this is what is the main part of the game engine 
///TODO move this to its own file.
struct system{

};


int main()
{	
    std::cout << "Hello World!\n"; 
}