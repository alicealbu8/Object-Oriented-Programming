#include "Controller.h"
#include <stack>

Controller::Controller()
{
}
/**
 * \param choc - object of type Cholotate*
 */
void Controller::addChocolate_controller(Chocolate* choc)
{
    UndoStack.push(std::make_pair(ActionType::ADD, choc));
	return chocolate_controller.addChocolate(choc);
   
}

bool Controller::removeChocolate_controller(string id)
{
    Chocolate* c = chocolate_controller.removeChocolate(id);
    if (c)
    {
        UndoStack.push(std::make_pair(ActionType::REMOVE, c));
    }
    return true;
   
}
/**
  * \param id - the id which identifies the object we want to edit
 * \param new_price the new price of the object after modification
 * \param new_type the new type of the object after modification
 * \param new_id the new id of the object after modification
 */
void Controller::editChocolate_controller(string id, float new_price, string new_id, string new_type, ChocolateRepo c)
{
	return chocolate_controller.editChocolate(id, new_price, new_id, new_type);
}
ChocolateRepo Controller::FilterByPrice(float price)
{

    ChocolateRepo repository;

    for (auto elem : this->chocolate_controller.GetChocolate()) {
        if (elem->GetPrice() <= price) {
            repository.addChocolate(elem);
        }
    }

    return repository;
}
//std::vector<Chocolate*> Controller::filter_controller(FilterPrice chocolate_controller)
//{
    //return filter(chocolate_controller);
//}
/**
 * .
 * 
 * \param Undo stack with Action values 
 * \param Redo  stack with Action values 
 */

bool Controller::UNDO()
{
    //ADD
    if (this->UndoStack.top().first == ActionType::ADD)
    {
        this->RedoStack.push(std::make_pair(ActionType::ADD, this->UndoStack.top().second));
        this->UndoStack.pop();
        this->chocolate_controller.removeChocolate(this->RedoStack.top().second->GetId());
        return true;
    }
    //REMOVE
    else
        if (this->UndoStack.top().first == ActionType::REMOVE)
        {
            this->RedoStack.push(std::make_pair(ActionType::REMOVE, this->UndoStack.top().second));
            this->UndoStack.pop();
            this->chocolate_controller.addChocolate(this->RedoStack.top().second);
            return true;
        }
        else
            if (this->UndoStack.size() == 0)
                return false;
}

/**
 * \param Undo stack with Action values
 * \param Redo  stack with Action values
 */

bool Controller::REDO()
{
    //ADD
    if (this->RedoStack.top().first == ActionType::ADD)
    {
        this->UndoStack.push(std::make_pair(ActionType::ADD, this->RedoStack.top().second));
        this->RedoStack.pop();
        this->chocolate_controller.addChocolate(this->UndoStack.top().second);
        return true;
    }
    //REMOVE
    else
        if (this->RedoStack.top().first == ActionType::REMOVE)
        {
            this->UndoStack.push(std::make_pair(ActionType::REMOVE, this->RedoStack.top().second));
            this->RedoStack.pop();
            this->chocolate_controller.removeChocolate(this->UndoStack.top().second->GetId());
            return true;
        }
        else
            if (this->RedoStack.size() == 0)
            {
                return false;
            }
    return false;
}

void Controller::LoadData(const string& fileName)
{
    this->chocolate_controller.LoadData(fileName);
}

void Controller::SaveData(const string& fileName)
{
    this->chocolate_controller.SaveData(fileName);
}

/**
 * .
 * 
 * \param s
 * \param a Action type
 * \return 
 */
std::ostream& operator<<(std::ostream& s, Action a)
{
    // // O: insert return statement here
    s << a.getType();
    return s;
}

std::ostream& operator<<(std::ostream& s, Controller chocolate_controller)
{
    // // 
    for (size_t i = 0; i < chocolate_controller.getController().size(); i++)
    {
        s << chocolate_controller.getController()[i]->toString();
    }
    return s;
}

Action::Action()
{

}

Action::Action(Chocolate value, ActionType type)
{
    this->type = type;
    this->value = value;
}
