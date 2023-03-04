#pragma once
#include "Repository.h"
#include "Domain.h"
#include <stack>
#include <iostream>


using namespace std;

typedef enum {

	ADD, REMOVE

}ActionType;

class Action {
private:

	Chocolate value;
	ActionType type;

public:

	Action();
	Action(Chocolate value, ActionType type);
	Chocolate getValue() { return value; }
	ActionType getType() { return type; }
	void setValue(Chocolate value) { this->value = value; }
	void setType(ActionType type) { this->type = type; }


	friend std::ostream& operator<<(std::ostream& s, Action a);
};

class Controller {
private:

	ChocolateRepo chocolate_controller;
	std::stack<pair<ActionType, Chocolate*>>UndoStack;
	std::stack<pair<ActionType, Chocolate*>>RedoStack;

public:
	Controller();
	void addChocolate_controller(Chocolate* choc);
	bool removeChocolate_controller(string id);
	void editChocolate_controller(string id, float new_price, string new_id, string new_type, ChocolateRepo c);
	ChocolateRepo FilterByPrice(float price);
	//std::vector<Chocolate*> filter_controller(FilterPrice chocolate_controller);
	bool UNDO();
	bool REDO();
	void LoadData(const string& fileName);
	void SaveData(const string& fileName);

	std::vector<Chocolate*>  getController() { return chocolate_controller.GetChocolate(); };

	friend std::ostream& operator<<(std::ostream& s, Controller chocolate_controller);
};

