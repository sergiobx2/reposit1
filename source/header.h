#include <iostream>

using namespace std;
const uint16_t dpt_elements = 10;

class Department{

    static uint16_t _elements;
    string department_location;
    string department_name;
    string dpt_manager = "Stefan";

    public:
    Department(){
        cout << "hello" << endl;
    };
    
    Department(string location, string dptname): department_location(location), department_name(dptname){
        cout << "Department " << department_name << " Created." << endl;
    };
    inline int numberofelements(){
        return _elements;
    }
    ~Department(){};
        
friend class Employee;

};

uint16_t Department::_elements = dpt_elements;

class Employee {
    protected:
    string name;
    string job_function;
    unsigned char gender;
    uint16_t employee_number;
    Department* dpt;
    uint16_t base_salary;
    uint16_t promotion_opportunity;

    protected:
    Employee(string _name, Department* dptw) : name(_name), dpt(dptw)
    {
        //Department();
        switch(name.back()){
            case 'o':
            case 'O':
            case 'e':
            case 'E':
            case 'l':
            case 'L':
            gender = 'M';
            break;

            case 'a':
            case 'A':
            gender = 'F';
            break;

            default:
            gender = '-';
            break;
        }
        cout << "Employee " << name << " Added." << endl;
        Department::_elements += 1;
    };
    
    public:
    void department_info(){
        
        cout << "Department Name: " << dpt->department_name << endl;
        cout << "Location: " << dpt->department_location << endl;
        cout << "Manager: " << dpt->dpt_manager << endl;
        cout << "Base Salary: " << base_salary << endl;
        cout << "Job Funtion: " << job_function << endl;
        cout << "\n\n";
    }
    virtual void RaiseSalary() = 0;
    ~Employee(){};
friend void viewopportunities(vector<Employee*> employee_vec);
friend void delete_gender(vector<Employee*> employee_vec);
};


class Manager : public Employee{

    
    string employee_function = "Manager";
    int base_salary_man=2400;
    uint16_t promo_opp = 1;

    public:
    Manager(string name, Department* dpt) : Employee(name, dpt) {
        Employee::base_salary = base_salary_man;
        Employee::job_function = employee_function;
        Employee::promotion_opportunity = promo_opp;
    }
    void RaiseSalary(){
        auto raise_percentage = 0.5;
        auto base_salary_aux = Employee::base_salary + (Employee::base_salary * raise_percentage);
        Employee::base_salary = base_salary_aux;
    };
    


};

class Clerk : public Employee{

    string employee_function = "Clerk";
    uint16_t base_salary_clerk=1600;
    uint16_t promo_opp = 1;

    public:
    Clerk(string name, Department* dpt) : Employee(name, dpt) {
        Employee::base_salary = base_salary_clerk;
        Employee::job_function = employee_function;
        Employee::promotion_opportunity = promo_opp;
    }

    void RaiseSalary(){
        auto raise_percentage = 0.01;
        Employee::base_salary = Employee::base_salary + (Employee::base_salary * raise_percentage);
        
    };

};

class Technician : public Employee{

    string employee_function = "Technician";
    uint16_t base_salary_tech = 1300;
    uint16_t promo_opp = 2;

    public:
    Technician(string name, Department* dpt) : Employee(name, dpt){
        Employee::base_salary = base_salary_tech;
        Employee::job_function = employee_function;
        Employee::promotion_opportunity = promo_opp;
    };

    void RaiseSalary(){
        auto raise_percentage = 0.1;
        Employee::base_salary = Employee::base_salary + (Employee::base_salary * raise_percentage);
        
    };
};

class Coder : public Employee{

    string employee_function = "Technician";
    uint16_t base_salary_tech = 1300;
    uint16_t promo_opp = 3;

    public:
    Coder(string name, Department* dpt) : Employee(name, dpt){
        Employee::base_salary = base_salary_tech;
        Employee::job_function = employee_function;
        Employee::promotion_opportunity = promo_opp;
    };

    void RaiseSalary(){
        auto raise_percentage = 0.1;
        Employee::base_salary = Employee::base_salary + (Employee::base_salary * raise_percentage);
        
    };
};






void viewopportunities(vector<Employee*> employee_vec){
    for(auto& i:employee_vec){
        cout << i->name << "'s promotion opportunity level: " << i->promotion_opportunity << endl;
    }
}

void delete_gender(vector<Employee*> employee_vec){
    for(auto& f:employee_vec){
        f->gender = '-';
    }
}