#include <iostream>
#include <cstdio>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <cstdlib>

#include "phonesCollection"

using namespace std;



void printMenu(){
    cout << "************************************************************************" << endl;
	cout << "*                                                                      *" << endl;
	cout << "*                              MENU                                    *" << endl;
	cout << "*                                                                      *" << endl;
	cout << "*                    1. Show availible phones                          *" << endl;
	cout << "*                    2. Add a phone to collection                      *" << endl;
	cout << "*                    3. Delete a phone                                 *" << endl;
	cout << "*                    4. Update a phone                                 *" << endl;
	cout << "*                    5. Sort phones collection by model                *" << endl;
	cout << "*                    6. Search phone by id                             *" << endl;
	cout << "*                    7. Search phone by model                          *" << endl;
	cout << "*                    8. Search phone binary by diagonal                *" << endl;
	cout << "*                    0. Exit                                           *" << endl;
	cout << "*                                                                      *" << endl;
	cout << "************************************************************************" << endl;
}


int main(){

    int number=5;
    Phone *phones = new Phone[5];
    phones[0]= newPhone('b',"galaxy",1);
    phones[1] = newPhone('r',"chinaPhone",4);
    phones[2] = newPhone('g',"iPhone",6);
    phones[3] = newPhone('y',"Lenovo",5);
    phones[4] = newPhone('r',"HTC",6);
    phones[0].id=1;
    phones[1].id=2;
    phones[2].id=3;
    phones[3].id=4;
    phones[4].id=5;

    bool showMenu = true;
	while (showMenu) {
		system("clear");
		printMenu();
		char character;
		int id;
		char *mdk;
		char line[20];
		char *lin;
		cout << "Select a number: "; cin >> character;
		switch (character) {
			default:
				cout << endl << "Something went wrong! Try a bit later." << endl;
				showMenu = false;
				break;
			case '0':
				cout << endl << "Have a nice day :D" << endl;
				showMenu = false;
				break;
			case '1':
				system("clear");
				cout << "++++++++++++++++++++++++++++++ PHONES Table: +++++++++++++++++++++++++++++++" << endl << endl;
				printPhones(phones,number);
				cout << endl;
				cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
				cin.ignore(); cin.get();
				break;
			case '2':
				system("clear");
				phoneAdd(phones, number);
				number++;
				cin.ignore();  cin.get();
				break;
			case '3':
				system("clear");
				cout << "Input the phones's id to delete from collection: "; cin >> id;
				cin.ignore();

				phoneDelete(phones, number, id);
				number--;
				break;
			case '4':
				system("clear");
				//cout << "Input the phones's id to update: ";
				cout<<"You should pay to update";
				cin.ignore(); cin.get();
				break;
			case '5':
				system("clear");
				phonesSort(phones, number);
				break;
			case '6':
				system("clear");
				cout << "Input the phones's id to search: "; cin >> id;
				cin.ignore();
				cout << endl << "Direct Search returned:" << endl;
				phonesSearchDirect(phones, number, id);
				cin.get();
				break;
			case '7':
				system("clear");

				cout << "Input the phones's model to search: "; cin>>line;
				lin=line;
				cin.ignore();
				cout << endl << "Linear Search returned:" << endl;
				phonesSearchLineal(phones, number, lin);
				cin.get();
				break;
			case '8':
				system("clear");
				int dgl;
				cout << "Input the phones's diagonal to search: "; cin >> dgl;
				cout << endl << "Binary Search returned:" << endl;
				id = phonesSearchBinary(phones, number, dgl);
				if (id == -1) {
					cout << "Not found!" << endl;
				}
				else {
					phonesSearchDirect(phones, number, (id - 1));
				}
				cin.ignore(); cin.get();
				break;
				case '9':
				system("clear");
				cout << "Input the phones's model to delete from collection: "; cin >> line;
				lin=line;
				cin.ignore();
				id= phonesSearchLineal(phones, number, lin);
				phoneDelete(phones, number, id);
				number--;
				break;
		}
	}


}
