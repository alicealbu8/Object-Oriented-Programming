#include "Domain.h"
#include <exception>
Chocolate::Chocolate()
{
}
/**
 * .
 * 
 * \param price - the price of the object
 * \param type - the type of the object eq. can be dark white etc.
 * \param id - the id of the object
 */

Chocolate::Chocolate(float price, string type, string id)
{
	this->price = price;
	this->type = type;
	this->id = id;
}

float Chocolate::GetPrice() const
{
	return this->price;
}
/**
 * .
 * 
 * \param price - the price we set for an Chocolate object
 */
void Chocolate::setPrice(float price)
{
	if (price >= 0)
		this->price = price;
	else
		throw 1;
}

string Chocolate::GetType() const
{
	return this->type;
}
/**
 * .
 * 
 * \param type - the type we set for an Chocolate object
 */
void Chocolate::setType(string type)
{
	this->type = type;
}

string Chocolate::GetId() const
{
	return this->id;
}
/**
 * .
 * 
 * \param id - the id we set for an Chocolate object
 */
void Chocolate::setId(string id)
{
	this->id = id;
}

string Chocolate::toString()
{
	std::string str1 = std::to_string(this->price);
	return "Chocolate " + this->id + " " + this->type + " " + str1 + " ";
}
/**
 * \param p - price
 * \param t - type
 * \param q - id
 * \param texture - texture
 */
ChocolateCake::ChocolateCake(float p, string t, string q, string texture):Chocolate{p, t, q}
{
	this->texture = texture;
}

string ChocolateCake::toString()
{
	std::string repr = Chocolate::toString();
	repr += this->texture;
	repr += "\n";
	return repr;
}
/**
 * \param p - price
 * \param t - type
 * \param q - id
 * \param with_chocolate_chips 
 */
Cookies::Cookies(float p, string t, string q, bool with_chocolate_chips):Chocolate{p, t, q}
{
	this->with_chocolate_chips = with_chocolate_chips;
}

string Cookies::toString()
{
	std::string repr = Chocolate::toString();
	if (this->with_chocolate_chips == 1)
		repr += "with chocolate chips"; 
	else
		repr += "without chocolate chips";
	repr += "\n";

	return repr;
}
