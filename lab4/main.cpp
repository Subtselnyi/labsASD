# include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
using namespace std;
float id_total=0;

struct Phone{
    float id;
    unsigned char color;
    char *model;
    unsigned short diagonal;
};
struct node
{
    Phone phones;
    node *l, *r;//Левая и Правая часть дерева
};

node * tree=NULL;
/*void push_id(int id_num,int u,node**t){
    while (u!=0){
    if (id_num>(*t)->phones.id) {push_id(id_num,u,&(*t)->r);u--;}
        else{ push_id(id_num,u,&(*t)->l);u--;}
    }
    (*t)->phones.id++;
}*/
void changeid(node *t,int prev){
    if (t!=NULL){
        if (t->phones.id==prev){
            t->phones.id=prev+1;
            prev++;

        }

    changeid((t->l),prev);
    changeid((t->r),prev);
    }
}
void push(Phone phone,node **t)
{
    int u=0;
    //bool key=false;
    if ((*t)==NULL)
    {
        (*t)=new node;
        (*t)->phones=phone;
        (*t)->l=(*t)->r=NULL; //Очищаем память для следующего роста
        return;
    }

        if (phone.id>(*t)->phones.id) {push(phone,&(*t)->r);u++;}
        else{ push(phone,&(*t)->l);u++;}

        /* if (phone.id==(*t)->phones.id){
            key = true;
            if (key) changeid(*t,phone.id);
        }*/
}

Phone newPhone(unsigned char clr, char *mdl, unsigned short dgl, float id_num){
    Phone phone;

    phone.color = clr;
    if (!strcmp(mdl,"nokia"))
    phone.model = "nokia";
    else if (!strcmp(mdl,"sony"))
    phone.model = "sony";
    else
        phone.model = mdl;
    phone.diagonal = dgl;
    phone.id=id_num;
    push(phone,&tree);
}

int phoneAdd(){
    unsigned char color;
    char model[10];
    char *mdl;
    unsigned short diagonal;
    float id_num;
    cout<<"Whats the model?"<<endl;
    cin>>model;
    mdl=model;
    cout<<"Whats the color?[blue-'b',red-'r']"<<endl;
    cin>>color;
    cout<<"Whats the diagonal of screen?"<<endl;
    cin>>diagonal;
    cout<<"Whats the index of phone?"<<endl;
    cin>>id_num;
    Phone newphone = newPhone(color,mdl,diagonal,id_num);
    return id_num;
}



void print (node *t,int u)
{
    if (t==NULL) return;
    else
    {
    print(t->l,++u);//С помощью рекурсивного посещаем левое поддерево
    for (int i=0;i<u;++i) cout<<"|";
    cout<<"Color   "<<t->phones.color<<endl;
    cout<<"ID   "<<t->phones.id<<endl;
    cout<<"Model   ";puts(t->phones.model);
    cout<<"Diagonal   "<<t->phones.diagonal<<endl<<endl;
    u--;
    }
    print(t->r,++u); //С помощью рекурсии посещаем правое поддерево
}
int searchId(int id, node **t){
    if (id==(*t)->phones.id){
        cout<<"Color  "<<(*t)->phones.color<<endl;
        cout<<"ID  "<<(*t)->phones.id<<endl;
        cout<<"Model   ";puts((*t)->phones.model);
        cout<<"Diagonal  "<<(*t)->phones.diagonal<<endl<<endl;
        return 0;
    }
     if (id>(*t)->phones.id) searchId(id,&(*t)->r);
        else searchId(id,&(*t)->l);
}
 void treelook(node *t) {
  if (t!=NULL) { //Пока не встретится пустой узел
    cout << t->phones.id; //Отображаем корень дерева
    treelook(t->l); //Рекурсивная функция для левого поддерева
    treelook(t->r); //Рекурсивная функция для правого поддерева
  }
}
int searchColor(char color, node *t){
    if (t!=NULL){
    if (color==t->phones.color){
        cout<<"color   "<<t->phones.color<<endl;
        cout<<"ID   "<<t->phones.id<<endl;
        cout<<"Model  ";puts(t->phones.model);
        cout<<"Diagonal  "<<t->phones.diagonal<<endl<<endl;
    }

        searchColor(color,(t->l));
        searchColor(color,(t->r));
     }

}
int searchDgl(unsigned short dgl, node *t){
   if (t!=NULL){
    if (dgl==t->phones.diagonal){
        cout<<"Color"<<t->phones.color<<endl;
        cout<<"ID  "<<t->phones.id<<endl;
        cout<<"Model  ";puts(t->phones.model);
        cout<<"Diagonal  "<<t->phones.diagonal<<endl;
    }

        searchColor(dgl,(t->l));
        searchColor(dgl,(t->r));
     }

}
void update(int id_num, node *t){
    if (t!=NULL){
        if (id_num==t->phones.id){
            cout<<"Enter the diagonal of "<<t->phones.model<<": ";
            int dg;
            cin>>dg;
            t->phones.diagonal=dg;
            cout<<"Enter the color of "<<t->phones.model<<": ";;
            char cl;
            cin>>cl;
            t->phones.color=cl;
        }
        update(id_num,(t->l));
        update(id_num,(t->r));
    }
}
void printMenu(){
    system("clear");
    cout << "************************************************************************" << endl;
	cout << "*                                                                      *" << endl;
	cout << "*                              MENU                                    *" << endl;
	cout << "*                                                                      *" << endl;
	cout << "*                    1. Show availible phones                          *" << endl;
	cout << "*                    2. Add a phone to collection                      *" << endl;
	cout << "*                    3. Search phone by id                             *" << endl;
	cout << "*                    4. Search phone by color                          *" << endl;
	cout << "*                    5. Update phone                                   *" << endl;
	cout << "*                    0. Exit                                           *" << endl;
	cout << "*                                                                      *" << endl;
	cout << "************************************************************************" << endl;
}
int main ()
{
    int what;
    Phone newphone = newPhone('b',"galaxy",1,3);
    newphone = newPhone('r',"chinaPhone",4,2);
    newphone = newPhone('g',"iPhone",6,4);
    newphone = newPhone('y',"Lenovo",5,1);
    newphone = newPhone('r',"HTC",6,5);
     bool showMenu = true;
	while (showMenu) {
		system("clear");
		printMenu();
		char character;
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
				print(tree,0);
				cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
				cin.ignore(); cin.get();
				break;
			case '2':
				system("clear");
				int id_number;
                id_number = phoneAdd();
				changeid(tree,id_number);
				cin.ignore();  cin.get();
				break;
			case '3':
				system("clear");
				int id_which;
				cout << "Input the phones's id to search: "; cin >> id_which;
				cin.ignore();
				cout << endl << "Direct Search returned:" << endl;
                searchId(id_which,&tree);
				cin.get();
				break;
            case '4':
				system("clear");
				char id_color;
				cout << "Input the phones's color to search: "; cin >> id_color;
				cin.ignore();
				cout << endl << "Direct Search returned:" << endl;
                searchColor(id_color,tree);
				cin.get();
				break;
            case '5':
				system("clear");
				unsigned short id_num;
				cout << "Input the phones's id to update: "; cin >> id_num;
				cin.ignore();
                update(id_num,tree);
                cout << endl << "Updated" << endl;
				cin.get();
				break;

		}}
    return 0;
}
