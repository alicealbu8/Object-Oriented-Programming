#pragma once
#include <string>
using namespace std;
class Chocolate {
private:

	float price;
	string type; //dark, white, etc
	string id;

public:

	Chocolate();
	Chocolate(float price, string type, string id);
	float GetPrice() const;
	void setPrice(float price);
	string GetType() const;
	void setType(string type);
	string GetId() const;
	void setId(string id);

	virtual string toString();
};

class ChocolateCake :public Chocolate{
private:

	string texture;

public:

	ChocolateCake(float p, string t, string q, string texture);
	string GetTexture() const { return texture; };
	void setTexture(string texture) { this->texture = texture; };

	string toString() override;

};

class Cookies : public Chocolate {
private:

	bool with_chocolate_chips;

public:

	Cookies(float p, string t, string q, bool with_chocolate_chips);

	string toString() override;
};