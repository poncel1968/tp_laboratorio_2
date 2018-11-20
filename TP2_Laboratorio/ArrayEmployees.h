#ifndef ARRAY_EMPLOYEES
#define ARRAY_EMPLOYEES

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

int initEmployees(Employee* lista, int len);
int addEmployee(Employee* list,int len, int id, char name[],char lastName[], float salary, int sector);
int findEmployeeById(Employee* list, int len, int id);
int findEmployeeIsEmpty(Employee* list, int len);
int sortEmployee(Employee* array, int limite,int order);
int swapEmployee(Employee* list, int index);
int addConsoleEmployee(Employee* list,int len);
int editEmployee(Employee* list,int len);
int removeEmployee(Employee* list, int len, int id);
int emptyList(Employee* list, int length);
int printEmployee(Employee* list, int length);



#endif // ARRAY_EMPLOYEES
