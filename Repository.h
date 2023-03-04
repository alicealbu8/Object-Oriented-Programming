#pragma once
#include "Domain.h"
#include <vector>
#include <iostream>

class ChocolateRepo {
public:
  
    void addChocolate(Chocolate* c);
    Chocolate* removeChocolate(string id);
    void editChocolate(string id, float new_price, string new_type, string new_id); //edits by id
    void LoadData(const string& fileName);
    void SaveData(const string& fileName);

    std::vector<Chocolate*> GetChocolate() { return chocolate; }

    friend std::ostream& operator<<(std::ostream& s, ChocolateRepo &chocolateRepo);
    friend istream& operator>>(istream& stream, Chocolate& chocolate);

   

private:

    std::vector<Chocolate*> chocolate; //we can use this for chocolate cake and cookies
};

class FilteringCriteria {

    virtual  std::vector<Chocolate*> filter(std::vector<Chocolate*> chocolate) = 0;
};

class FilterPrice :FilteringCriteria {
    float price;
public:
    std::vector<Chocolate*> filter(std::vector<Chocolate*> chocolate) override {
        std::vector<Chocolate*> result;
        for (int i = 0; i < chocolate.size(); i++)
        {
            if (chocolate[0]->GetPrice() <= price)
                result.push_back(chocolate[0]);
        }
        return result;
    }
    FilterPrice() {
        this->price = 0;
    }
    FilterPrice(float pr) {
        this->price = pr;
    }
};
