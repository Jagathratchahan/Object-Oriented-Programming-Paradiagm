#include<iostream>
using std::string;
using std::cout;
using std::endl;

class AbstractEmployee{
 virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee{

private:
   string Name;
   string Company;
   int age;
public:
   void setName(string name){
    //setter
   Name = name;
   }
   string getName(){
    //getter
   return Name;
   }
   void setCompany(string company){
   //setter
   Company = company;}
   string getCompany(){
   //getter
   return Company;
   }
   void setAge(int age1){
   //setter
   if (age1>=18)
    age = age1;
    }
   int getAge(){
   //getter
   return age;
   }
   void introduceYourself(){
   cout<<"Name - " << Name << endl;
   cout<<"Company - " << Company << endl;
   cout<<"Age - " << age << endl;}

   Employee(string name, string company,int age1){
       Name = name;
       Company = company;
       age = age1;
   }
   void AskForPromotion(){
       if(age > 30)
        cout<< Name<<" got promoted as CEO."<<endl;
       else
        cout<< "Sorry,"<<Name<<"better try next time!"<<endl;
   }
   void Work(){
   cout<< Name << "is checking emails, task backlog, and performing those tasks and aso on..."<<endl;
   }
};

class Developer:public Employee{
public :
    string FavouriteProgrammingLanguage;
    Developer(string name, string company,int age, string Language):Employee(name, company, age){
    FavouriteProgrammingLanguage = Language;
    }
    void fixBug(){
    cout<<getName()<<" fixed bug using "<<FavouriteProgrammingLanguage << endl;
    }
};

class Teacher:public Employee{
public:
    string Subject;
    void PrepareLesson(){
    cout << getName() <<"is preparing for tomorrow class on "<< Subject << "lesson"<<endl;
    }
    Teacher(string name, string company,int age,string subject):Employee (name, company, age){
        Subject = subject;
    }
};


int main(){
    Employee Employee1("Jagath","Google",32);
    Employee1.introduceYourself();
    Employee1.setAge(15);
    cout<<Employee1.getName()<< " is "<< Employee1.getAge()<< " years old."<<endl;
    Employee1.AskForPromotion();
    Developer D1 =  Developer ("Jagathratchahan", "Amazon", 24,"C++");
    D1.fixBug();
    Teacher t1 = Teacher("Mahalakshmi", "REC", 59,"English");
    t1.PrepareLesson();
    t1.AskForPromotion();
    Employee *e1 = &t1;
    Employee *e2 = &D1;
    e1->Work();
    e2->Work();
    return 0;
    }
