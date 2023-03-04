#pragma once
#include "Controller.h"
#include <limits>

using std::cin;
using std::cout;

class UI {
public:
    UI();
    ~UI();
    void Start();
    void DisplayMenu();
    bool ReadOption();
    Chocolate* ReadChocolate();
    static Chocolate* ReadCookie();
    static Chocolate* ReadCake();

private:
    Controller controller;
};


UI::UI() {
    Start();
}

UI::~UI() {
    for (auto c : this->controller.getController()) {
        delete c;
    }
}

void UI::Start() {
    controller = Controller();
    //controller.LoadData("data");
    DisplayMenu();
}

void UI::DisplayMenu() {
    bool option = true;
    while (option) {
        string m = "---------------------------\n";
        m += "Here are all the options: |\n";
        m += "1. Add chocolate          |\n";
        m += "2. Remove chocolate       |\n";
        m += "3. Edit chocolate         |\n";
        m += "4. Filter                 |\n";
        m += "5. Undo                   |\n";
        m += "6. Redo                   |\n";
        m += "7. Print all objects      |\n";
        m += "8. Leave shop             |\n";
        m += "---------------------------\n";
        cout << m;

        option = ReadOption();
    }
    controller.SaveData("data");
}
Chocolate* UI::ReadCookie() {
    string id;
    float price;
    string type;
    bool with_chocolate_chips;

    cout << "Please enter the Id\n";
    cin >> id;
    cout << "Please enter the price\n";
    cin >> price;
    cout << "Please enter the type\n";
    cin >> type;
    cout << "With chocolate chips?\n";
    cin >> with_chocolate_chips;

    return new Cookies(price, type, id, with_chocolate_chips);
}

Chocolate* UI::ReadCake() {

    string id;
    float price;
    string type;
    string texture;

    cout << "Please enter the Id\n";
    cin >> id;
    cout << "Please enter the price\n";
    cin >> price;
    cout << "Please enter the type\n";
    cin >> type;
    cout << "Please enter the texture\n";
    cin >> texture;

    return new ChocolateCake(price, type, id, texture);
}

Chocolate* UI::ReadChocolate() {

    cout << "Choose an object...\n";
    cout << "1 - Cookie\n";
    cout << "2 - Chocolate Cake\n";

    int option;
    cin >> option;

    if (option == 1) {
        return ReadCookie();
    }
    else if (option == 2) {
        return ReadCake();
    }
    else {
        return nullptr;
    }
}
bool UI::ReadOption() {

    int option;
    cout << "Please input the option\n";
    cin >> option;

    switch (option) {
    case 1:
    {
        auto chocolate = ReadChocolate();

        if (chocolate != nullptr) {
            try {
                controller.addChocolate_controller(chocolate);
            }
            catch (...) {
                cout << "Oops...";
            }
        }
        else {
            cout << "Invalid input! Please insert another one!\n";
        }
        break;
    }
    case 2: 
    {   string id;
        cout << "Please enter the index:";
        cin >> id;
        try {
            controller.removeChocolate_controller(id);
        }
        catch (...) {
            cout << "Wrong index!\n";
        }
        break;
    }
    case 3: {
        break;
    }
    case 4: 
    {
        float price;
        cout << "What is the maximum price you want to spend?\n";
        cin >> price;
        controller.FilterByPrice(price);
        cout << "\n Here are all the objects in your buget:\n";
        cout << controller;
        break;
    }
    case 5: 
    {
        bool res = controller.UNDO();
        if (res)
            cout << "Succesfully undone last operation" << endl;
        else
            cout << "No opertaion to be undone" << endl;
        break; 
    }
    case 6: {

        bool res = controller.REDO();
        if (res)
            cout << "Succesfully redone last operation" << endl;
        else
            cout << "No opertaion to be redone" << endl;

        break; 
    }
    case 7:
        try {
            cout << controller;
        }
        catch (...) {
            cout << "Something went wrong";
        }
        break;
    case 8:
        return false;
    default:
        cout << "Invalid option.\n";
    }

}
