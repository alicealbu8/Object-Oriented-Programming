#include "Repository.h"
#include <utility>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>

//have two functions to load and save your data from/into a .csv (comma separated value) file, respectively
vector<string> tokenize(string str, char delimiter)
{
    vector <string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

istream& operator>>(istream& is, Chocolate& chocolate) { //sau chocolate Repo??
    string line;
    getline(is, line);

    vector<string> tokens = tokenize(line, ',');
    chocolate.setId(tokens[0]);
    float price = 0;
    std::istringstream(tokens[1]) >> price;
    chocolate.setPrice(price);
    chocolate.setType(tokens[2]);

    return is;
   
}
/**
 * 
 * \param c - object of type Chocolate* which will be added to the vector
 */
void ChocolateRepo::addChocolate(Chocolate* c)
{
	chocolate.push_back(c);
}

Chocolate* ChocolateRepo::removeChocolate(string id)
{
    Chocolate* c = nullptr;
    auto index = find_if(chocolate.begin(), chocolate.end(), [id](Chocolate* c)->bool { return c->GetId() == id; });
    if (index != chocolate.end())
    {
        c = *index;
        chocolate.erase(index);
    }
    return c;
    //delete c;
}
/**
 * .
 * 
 * \param id - the id which identifies the object we want to edit
 * \param new_price the new price of the object after modification
 * \param new_type the new type of the object after modification
 * \param new_id the new id of the object after modification
 */
void ChocolateRepo::editChocolate(string id, float new_price, string new_type, string new_id){
    for (size_t i = 0; i < chocolate.size(); i++)
    {
        if (chocolate[i]->GetId() == id)
        {
            chocolate[i]->setId(new_id);
            chocolate[i]->setPrice(new_price);
            chocolate[i]->setType(new_type);
        }
    }
}

void ChocolateRepo::LoadData(const string& fileName)
{
    
     
}

void ChocolateRepo::SaveData(const string& fileName)
{

}

/**
 * .
 * 
 * \param s
 * \param chocolateRepo object of type ChocolateRepo
 * \return 
 */
std::ostream& operator<<(std::ostream& s, ChocolateRepo &chocolateRepo)
{
    for (size_t i = 0; i < chocolateRepo.chocolate.size(); i++)
    {
        s << chocolateRepo.chocolate[i]->toString();
    }
    return s;
}
