#include <string>
#include <iostream>

using namespace std;

class Human {
//atributi
protected:
 string name;
 char sex;
 int year;
//konstruktori
public:
 Human();
 Human(string, int, char);
//destruktors
~Human(){
    cout<<"Objekts iznicinats!"<<endl;
}
//metodes
void print() const;
string GetName() const;
char GetSex() const;
int GetYear() const;
void SetName(string);
void SetSex(char);
void SetYear(int);
};

//     konstruktori
 Human::Human(){
 name="nav";
 sex='n';
 year=0;
 cout<<"Objekts bez parametriem izveidots\n";
 }

 Human::Human(string v,int g,char d){
 name=v;
 sex=d;
 year=g;
 cout<<"Objekts ar parametriem izveidots\n";
 }
//objekta informacijas izvade
inline void Human::print() const{
    cout<<"Cilveka vards = "<<name<<"\n";
    cout<<"Cilveka dzimums = "<<sex<<"\n";
    cout<<"Cilveka dzimsanas gads = "<<year<<"\n\n";
}
// piekluve atributiem
inline int Human::GetYear() const{
    return year;
}
inline char Human::GetSex() const{
    return sex;
}
inline string Human::GetName() const{
    return name;
}
//atributu izmaina
inline void Human::SetName(string name){
  cout<<"Ludzu ievadiet jauno vardu:"<<"\n";
  string newname;
  cin>>newname;
  this->name=newname;
}
inline void Human::SetSex(char sex){
  cout<<"Ludzu ievadiet jauno dzimumu:"<<"\n";
  char newsex;
  cin>>newsex;
  this->sex=newsex;
}
inline void Human::SetYear(int year){
  cout<<"Ludzu ievadiet jauno dzimsanas gadu:"<<"\n";
  int newyear;
  cin>>newyear;
  this->year=newyear;
}

int main(){
string name="tukss";
char sex='n';
int year=1000;
cout<<"\n1. Statisku objektu izveidosana\n\n";
Human Stat_Empty=Human();
Human Stat_with_data=Human("Maija",1980,'s');
cout<<"\n2. Dinamisku objektu izveidosana\n\n";
Human *Dyn_Empty=new Human();
Human *Dyn_with_data=new Human("Valdis",1982,'v');
cout<<"\n";
//tuksa statiska objekta datu ievade
cout<<"\n3. Sobrid statiska objekta dati ir:\n";
Stat_Empty.Human::print();
Stat_Empty.Human::SetName(name);
Stat_Empty.Human::SetSex(sex);
Stat_Empty.Human::SetYear(year);
cout<<"\nStatiska objekta dati ir:\n";
Stat_Empty.Human::print();
//ar datiem aizpildita statiska objekta dati
cout<<"\n4. Ar datiem aizpildita statiska objekta dati ir:\n";
Stat_with_data.Human::print();
cout<<"Objekta vards ir "<<Stat_with_data.Human::GetName()<<",dzimums ir "<<Stat_with_data.Human::GetSex()<<", bet dzimsanas gads ir "<<Stat_with_data.Human::GetYear()<<"\n\n";
//cout<<
//tuksa dinamiska objekta datu ievade
cout<<"\n5. Sobrid dinamiska objekta dati ir:\n";
(*Dyn_Empty).Human::print();
(*Dyn_Empty).Human::SetName(name);
(*Dyn_Empty).Human::SetSex(sex);
(*Dyn_Empty).Human::SetYear(year);
cout<<"\nDinamiska objekta dati ir:\n";
(*Dyn_Empty).Human::print();
//ar datiem aizpildita dinamiska objekta dati
cout<<"\n6. Ar datiem aizpildita dinamiska objekta dati ir:\n";
(*Dyn_with_data).Human::print();
cout<<"Objekta vards ir "<<(*Dyn_with_data).Human::GetName()<<",dzimums ir "<<(*Dyn_with_data).Human::GetSex()<<", bet dzimsanas gads ir "<<(*Dyn_with_data).Human::GetYear()<<"\n\n";
delete Dyn_Empty;
delete Dyn_with_data;
return 0;
}
