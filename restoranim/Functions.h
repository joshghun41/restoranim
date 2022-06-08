#pragma once
#pragma once
#pragma once
#include<Windows.h>
#include<iostream>
#include"Entities.h"
#include<conio.h>
#include"Start.h"
using namespace std;


Dish dolma("dolma       ", 7);
Dish sezar("sezar salati", 5);
Dish paytaxt("paytaxt salati", 5);
Dish Sushi("Sushi Baliqli", 15);
Dish Cola("Cola icki ", 2);
Dish Ayran("ev ayrani", 1);
Admin cosqun{ "cosqun","Gulmemmedli","admin","admin" };
Admin Ejdaha{ "Ejdaha","Qanadsiz","admin123","admin123" };
Restaurant r;

void setcolor(int fg, int bg) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}

void ShowOrders(vector<Dish>dish, int  count[]) {
	int total_price = 0;
	for (size_t i = 0; i < dish.size(); i++)
	{
		cout << dish[i].GetName() << " " << count[i] << " eded" << endl;
		cout << "----------------------------------------" << endl;
		total_price += dish[i].GetPrice() * count[i];

	}

	cout << "\nUmumi Qiymet : " << total_price << " Azn" << endl;
	cout << "\n" << endl;

}
void ShowBadget() {
	cout << "	Restoranin budcesi	 " << r.GetBudGet() << " Azn" << endl;
}
void ShowDishies() {
	for (size_t i = 0; i < r.GetDishies().size(); i++)
	{
		r.GetDishies()[i].ShowDish();

	}
}
void  showmenu() {
	setcolor(6, 0);
	cout << "		-----MENYU-----	" << endl;
	setcolor(7, 0);

	cout << " Musteri	[1]" << endl;

	setcolor(2, 0);
	cout << " Admin		[2]" << endl;

	setcolor(3, 0);

}

Dish getdishbyid(int id) {
	for (size_t i = 0; i < r.GetDishies().size(); i++)
	{
		if (r.GetDishies()[i].GetID() == id)
		{
			return r.GetDishies()[i];
		}
	}
}


void ShowCustomerMenyu() {
	setcolor(7, 0);
	cout << "Menyuya bax [1]  " << endl;
	setcolor(6, 0);
	cout << "Sifaris Ver [2]\n " << endl;
	setcolor(3, 0);
}

void ShowAdminMenyu() {
	setcolor(3, 0);
	cout << "Yemek elave ele	[1]" << endl;
	setcolor(4, 0);
	cout << "Yemekyi sil	[2]" << endl;
	setcolor(5, 0);
	cout << "Budcuye bax	[3]	\n" << endl;
	setcolor(7, 0);


}


#include<fstream>

void WriteAdminsToFile() {
	ofstream out("admins.txt", ios::out);
	if (out.is_open())
	{
		for (size_t i = 0; i < r.GetAdmins().size(); i++)
		{
			out << r.GetAdmins()[i].name << endl;
			out << r.GetAdmins()[i].surname << endl;
			out << r.GetAdmins()[i].password << endl;
			out << r.GetAdmins()[i].username << endl;
			out << "------" << endl;
		}

	}
	out.close();
}

#include<string>
vector<Admin>ReadAdmins() {
	ifstream in("admins.txt");
	vector<Admin>admins;
	if (in.is_open()) {

		for (size_t i = 0; i < r.GetAdmins().size(); i++)
		{
			string name;
			in >> name;

			string surname;
			in >> surname;

			string password;
			in >> password;

			string username;
			in >> username;

			string line;
			in >> line;

			Admin admin;
			admin.name = name;
			admin.surname = surname;
			admin.password = password;
			admin.username = username;

			admins.push_back(admin);

		}
	}
	in.close();
	return admins;
}


void WriteDishOrdersToFile(vector<Dish> dishes, int count[]) {

	ofstream out("dishesOrders.txt", ios::app);

	if (out.is_open()) {
		double total_price = 0;
		for (size_t i = 0; i < dishes.size(); i++)
		{
			out << "Yemek ID: " << dishes[i].GetID() << endl;
			out << "Yemek Adi: " << dishes[i].GetName() << " " << count[i] << " Eded" << endl;
			out << "Yemek Qiymeti: " << dishes[i].GetPrice() * count[i] << " Azn" << endl;
			total_price += dishes[i].GetPrice() * count[i];
		}
		out << "Umumi Qiymet: " << total_price << " Azn" << endl;
		out << "====================================" << endl;
	}

	out.close();
}


bool CheckAdminData(vector<Admin>admins, string username, string password) {
	for (size_t i = 0; i < r.GetAdmins().size(); i++)
	{
		if (admins[i].username == username && admins[i].password == password) {
			return true;
		}
	}

	return false;
}