#pragma once
#pragma once
#include<iostream>
using namespace std;
#include<vector>
struct Admin {
	string name;
	string surname;
	string username;
	string password;

};
class Dish {
	int ID;
	string name;
	double price;
public:
	static int id;
	Dish(string name, double price)
	{
		this->name = name;
		this->price = price;
		SetId(++id);
	}

	int GetID() {
		return ID;
	}
	void SetId(int id) {
		this->ID = id;
	}
	string GetName() {
		return name;
	}
	double GetPrice() {
		return price;
	}
	void ShowDish() {
		cout << "ID " << GetID() << "  |  " << name << "		" << price << " Azn" << endl;


	}
};

int Dish::id = 0;

class Restaurant {
	vector<Dish>dishes;
	vector<Admin>admins;
	double budget = 0;
public:
	Restaurant()
	{

	}
	void addDish(Dish dish) {
		dishes.push_back(dish);
	}
	vector<Dish>GetDishies() {
		return dishes;
	}
	double GetBudGet() {
		return budget;
	}
	void SetBudget(double budget) {
		this->budget = budget;
	}
	vector<Admin>GetAdmins() {
		return admins;
	}
	int GetIndex(int id) {
		for (size_t i = 0; i < dishes.size(); i++)
		{
			if (dishes[i].GetID() == id)
			{
				return i;
			}

		}
		return -1;
	}

	void DeleteDish(int id) {
		auto index = GetIndex(id);
		auto iterator = dishes.begin() + index;

		dishes.erase(iterator);

	}
	void AddAdmin(const Admin& admin) {
		admins.push_back(admin);
	}
};

struct Order {
	Dish dish;
	int count;
	double order_price;

};