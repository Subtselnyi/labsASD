#include<iostream>
#include<iomanip>
#include<math.h>
#include<time.h>
#include<cmath>
#include<cstdlib>

using namespace std;
struct ZNO
{
    char student_name[30];
    int r,        //резульатт Математики
        g,        //результат фызики
        b;        //результат укрмови
}students[30];

int main()
{
     int R_MAX =200;
     int G_MAX =200;
     int B_MAX =200;
    char question;
    int max_num=200;
    srand(time(NULL));
    /*
      cout<<"menu"<<endl;
      cout<<"1.default options 200"<<endl<<"2.change zno results"<<endl;
      cin>>question;
      cout<<"1.enter results"<<endl<<"2.generate zno ressults"<<endl;
    */

    cout<<"Do you want to change the max ZNO?[y/n]"<<endl;
    cin>>question;
    if ((question!='y')&&(question!='n')){
        cout<<"Enter valid letter y or n"<<endl;
            cin>>question;
    }

    if (question=='y'){
        cout<<"Enter the maximal ZNO result"<<endl;
        cin>>max_num;
        R_MAX=max_num;
        G_MAX=max_num;
        B_MAX=max_num;
    } else {
        cout<<"the maximal result will be 200"<<endl;
    }






    int number;
    cout<<"Please,enter the number of students"<<endl;
    cin>>number;

    cout<<"Do you want to generate results ZNO?[y/n]"<<endl;
    cin>>question;
    if ((question!='y')&&(question!='n')){
        cout<<"Enter valid letter y or n"<<endl;
            cin>>question;
    }

    if (question=='y'){

        for (int i=0;i<number;i++){
        cout<<"Enter the name of "<<i+1<<"student"<<endl;
        cin>> students[i].student_name;
        students[i].r=rand()%max_num +1;
        students[i].g=rand()%max_num +1;
        students[i].b=rand()%max_num +1;
    }
    }
    else{

    for (int i=0;i<number;i++){
        cout<<"Enter the name of "<<i+1<<"student"<<endl;
        cin>> students[i].student_name;
        cout<<"Enter student "<<students[i].student_name<<"'s"<<" results in ZNO of Math, Physics, Ukrainian"<<endl;
        int enter_r, enter_g, enter_b;
        cin>>enter_r>>enter_g>>enter_b;
        while (!((enter_r<=200)&&(enter_g<=200)&&enter_b<=200)){
           // if (!(enter_r<=200)&&(enter_g<=200)&&enter_b<=200)
            cout<<"You entered incorect ZNO results"<<endl<<"Please enter valid numbers"<<endl;;
            cin>>enter_r>>enter_g>>enter_b;
        }
        students[i].r=enter_r;
        students[i].g=enter_g;
        students[i].b=enter_b;
    }
    }

    int summ_r=0,summ_g=0,summ_b=0;
    for (int i=0;i<number;i++){
        summ_r+=students[i].r;
        summ_g+=students[i].g;
        summ_b+=students[i].b;
    }
    double avrg_r=summ_r/number;
    double avrg_g=summ_g/number;
    double avrg_b=summ_b/number;

    cout<<endl<<" Thanks, for having input data about"<<number<<"students"<<endl;
    cout<<setw(15) << "STUDENT" << " | " <<setw(5) << "Math" <<setw(8) << "Physic" <<setw(5) << "Ukr" <<endl;		//вивід введенних значень
	cout<< "=====================================================" <<endl;
	for(int i=0;i<number;i++){
		cout<<setw(2) << i + 1;
		cout<<setw(13) <<students[i].student_name << " | ";
		cout<<setw(5) <<students[i].r <<setw(8) <<students[i].g <<setw(5) <<students[i].b <<endl;
	}
	cout<<endl;

    cout<<"The avarage marks in ZNO are:"<<endl<<"Math: "<<setw(5)<<avrg_r<<endl<<"Physics: "<<setw(5)<<avrg_g<<endl<<"Ukr: "<<setw(5)<<avrg_b<<endl;



    return 0;
}
