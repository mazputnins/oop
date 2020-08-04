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
      virtual ~Human(){
        cout<<"\nObjekts Human iznicinats!"<<endl;
      }
//metodes
      virtual void print() const;
      string GetName() const;
      char GetSex() const;
      int GetYear() const;
      void SetName(string);
      void SetSex(char);
      void SetYear(int);
};
//  Klases Human metodes
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
    cout<<"Cilveka dzimsanas gads = "<<year<<"\n";
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
//apakšklase
class Employee : public Human {
//atributi
    private:
      double salary;
    public:
      Employee():Human(), salary(0){
      }//tukšais konstruktors
      Employee(string, int, char, double);
      virtual ~Employee(){
        cout<<"\nObjekts Employee iznicinats!"<<endl;
      }
      double GetSalary() const;
      void SetSalary(double);
      virtual void print() const;
};
//Apakšklases metodes
//konstruktors
  Employee::Employee(string v, int g, char d, double a) : Human(v,g,d){
      salary = a;
  }
//jaunā atribūta piekļuve
  inline double Employee::GetSalary() const{
    return salary;
  }
//jaunā atribūta modifikācija
  inline void Employee::SetSalary(double salary){
    cout<<"Ludzu ievadiet jauno algu:"<<"\n";
    double newsalary;
    cin>>newsalary;
    this->salary=newsalary;
  }
//pārdefinētā print metode
  inline void Employee::print() const{
    Human::print();
    cout<<"Darbinieka alga: "<<salary<<"\n";
  }

int main(){
//mainīgo inicializācija  
int n=4;

cout<<"Tiks izveidots masīvs no "<<n<<" objektiem\n";

Human *People[4]={//ja 4 aizvietoja ar n, error
  new Human(),
  new Employee(),
  new Human ("Marta", 1990, 's'),
  new Employee ("Oskars", 1991, 'v', 1234.56),
};

cout<<"\nCilvēki:\n";
for (int i=0;i<n;i++){
    cout<<"\nCilvēks Nr."<<(i+1)<<":\n";
    People[i]->print();
    }


for (int i=0;i<n;i++){
    delete People[i];
    }

return 0;
}
