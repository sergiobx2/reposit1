/*TASK 3-4 - Polymorphism and late binding*/
#include <iostream>
#include <vector>
#include "header.h"


using namespace std;

namespace stf{
    string name = "Sergio Cristiano";
    void print(){
        cout << name << endl;
    };

}

namespace ddf{
    string name = "Neiva Alves Baixo";
    void print2(){
        cout << name << endl;
    };
}



int main(){
    vector<Employee*> interior_department;
    int number = 200;

    Department* interiors;
    interiors = new Department("Porto", "Interior Engineering");

    Employee* employee1;
    Employee* employee2;
    Employee* employee3;
    Employee* employee4;
    Employee* employee5;

    employee1 = new Manager("Sergio", interiors);
    employee2 = new Clerk("Joao", interiors);
    employee3 = new Clerk("Adriana", interiors);
    employee4 = new Technician("Gabriel", interiors);
    employee5 = new Coder("Joana", interiors);


    interior_department.push_back(employee1);
    interior_department.push_back(employee2);
    interior_department.push_back(employee3);
    interior_department.push_back(employee4);
    interior_department.push_back(employee5);

    employee1->department_info();
    employee3->department_info();

    // employee1->RaiseSalary();
    // employee3->RaiseSalary();
    cout << "\n\n" << endl;
    
    // employee1->department_info();
    // employee3->department_info();
    cout << interiors->numberofelements() << endl;

    viewopportunities(interior_department);
    delete_gender(interior_department);
    cout << "\n" << endl;




    for(auto& i : interior_department){
        delete i;
    }
    cout << "Deleted all elements" << endl;
    

    return 0;
}