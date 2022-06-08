#pragma once
#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include"Functions.h"
void Start() {
	r.AddAdmin(cosqun);
	r.AddAdmin(Ejdaha);

	WriteAdminsToFile();

	r.addDish(dolma);
	r.addDish(sezar);
	r.addDish(paytaxt);
	r.addDish(Sushi);
	r.addDish(Cola);
	r.addDish(Ayran);
	while (true) {
		showmenu();
		int secim = 0;
		cout << "Secim edin  : ";
		cin >> secim;
		system("cls");

		if (secim == 1)  //musderi
		{
			while (true) {
				ShowCustomerMenyu();
				//musderi

				int secim = 0;
				cout << "Secim edin  1/2	: ";
				cin >> secim;

				if (secim == 0)
				{
					break;
				}


				if (secim == 1)
				{
					ShowDishies();

					//menyu
				}
				else if (secim == 2) {
					vector<Dish>dishes1;
					int count[10] = {};
					int index = 0;

					while (true) {

						system("cls");
						ShowDishies();

						int id1 = 0;
						setcolor(3, 0);
						cout << "	Yemeyin id sini daxil edin " << endl;
						cin >> id1;
						if (id1 == 0) { break; };
						auto dish = getdishbyid(id1);

						int cnt = 0;
						setcolor(2, 0);
						cout << "	Sayini daxil edin : " << endl;
						cin >> cnt;
						double price = dish.GetPrice() * cnt;
						cout << "Qiymeti : " << price << endl;
						cout << "Tarix : " << __DATE__ << endl;
						dishes1.push_back(dish);
						count[index] = cnt;
						index++;
						r.SetBudget(r.GetBudGet() + price);
						system("pause");


					}
					WriteDishOrdersToFile(dishes1, count);
					ShowOrders(dishes1, count);
				}
			}
		}

		else if (secim == 2) {
			cin.ignore();
			cin.clear();


			string username;
			cout << "Istifadeci adini daxil edin: " << endl;;
			getline(cin, username);

			string password;
			cout << "Parolu daxil edin: " << endl;
			getline(cin, password);

			auto admins = ReadAdmins();
			if (CheckAdminData(admins, username, password)) {
				ShowAdminMenyu();
				int secim = 0;
				cout << "Secim edin  	: ";
				cin >> secim;
				system("cls");


				if (secim == 1)
				{
					cin.ignore();
					cin.clear();
					string name;
					setcolor(5, 0);
					cout << "	Yemeyin adini daxil edin ; " << endl;
					setcolor(3, 0);
					getline(cin, name);

					double price = 0;
					cout << "	Qiymetini daxil edin : " << endl;
					cin >> price;

					Dish newdish(name, price);
					r.addDish(newdish);
					setcolor(8, 0);
					cout << "	Emaliyat ugurla tamamlandi...." << endl;
				}
				else if (secim == 3) {
					ShowBadget();
				}
				else if (secim == 2) {
					ShowDishies();
					int id = 0;
					cout << "Silmek isdediyinz yemeyin id sin daxil edin :" << endl;
					cin >> id;

					r.DeleteDish(id);
					cout << "\n Ugurla tamamlandi....." << endl;
				}
			} //admin

			else {
				cout << "\nParol ya da istifadeci adi yanlisdir !!!" << endl;
				continue;
			}

		}
	}
}