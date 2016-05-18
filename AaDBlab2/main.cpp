#include<iostream>
#include<iomanip>
#include<math.h>



using namespace std;
struct usercolor{
	char user_name[100];
	int r;
	int g;
	int b;
} users[100];
int main(){

	const int R_MAX = 255;
	const int G_MAX = 200;
	const int B_MAX = 240;
	int number;
	cout<< "Enter a number of users< 100 : ";
	cin>>number;
	int i = 0;
	while (i <number){
		cout<<endl;
		cout<< "Enter user " << i + 1 << " name without spaces: ";
		cin>>users[i].user_name;
		cout<< "Enter user " << i + 1 << " favorite color - integer R, G, B < 256: ";
		int cr = R_MAX + 1, cg = G_MAX + 1, cb = B_MAX + 1;
		bool first = true;						//перевірка на правильність введення значень
		while (!(cr<= R_MAX &&cg<= G_MAX &&cb<= B_MAX)){
			if (first == false){
				cout<< "Uncorrect color! Try again." <<endl;
				cout<< "Enter user " << i + 1 << " favorite color (integer R, G, B < 256): ";
			}
			cin>>cr>>cg>>cb;
			first = false;
		}
		users[i].r = cr;
		users[i].g = cg;
		users[i].b = cb;
		i++;
	}
	int maxR=users[0].r;
	for(int i=0;i<number;i++){
if(users[i].r>maxR){
maxR=users[i].r;
                                }
            }
	int maxG=users[0].g;
	for(int i=0;i<number;i++){
if(users[i].g>maxG){
maxG=users[i].g;
                                }
            }
int maxB=users[0].b;
	for(int i=0;i<number;i++){
if(users[i].b>maxB){
maxB=users[i].b;
                                }
            }
	cout<<endl;
	cout<< "Thank you! You entered information about " <<number<< " users:" <<endl;
	cout<<endl;
	i = 0;
	cout<<setw(15) << "USER" << " | " <<setw(5) << "R" <<setw(5) << "G" <<setw(5) << "B" <<endl;		//вивід введенних значень
	cout<< "=====================================================" <<endl;
	int R = 0, G = 0, B = 0;
	while (i <number){
		cout<<setw(2) << i + 1;
		cout<<setw(13) <<users[i].user_name << " | ";
		cout<<setw(5) <<users[i].r <<setw(5) <<users[i].g <<setw(5) <<users[i].b <<endl;
		R += users[i].r;
		G += users[i].g;
		B += users[i].b;
		i++;
	}
	cout<<endl;
cout<<"Maximum color is :"<<" "<<maxR<<endl;


	return 0;
}
