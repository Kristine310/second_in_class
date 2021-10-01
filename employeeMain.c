//gcc employeeMain.c employeeTable.c employeeOne.c
//gcc employeeMain.c employeeTable.c employeeTwo.c
#include<stdio.h>
#include<stdlib.h>
#include "employee.h"

int main(void) 
{
    //define in employeeOne.c or employeeTwo.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    //defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;   //Declaration

    //Example found for phone search
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "310-555-1215");

    if (matchPtr != NULL)
        printf("Employee phone number 310-555-1215 is in record %d %d %d\n", matchPtr, EmployeeTable, matchPtr - EmployeeTable);
    else
        printf("Employee phone number is NOT found in the record\n");
    
    //Example not found for phone search
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "661-786-4532");

    if (matchPtr != NULL)
        printf("Employee phone number 661-786-4532 is in record %d %d %d\n", matchPtr, EmployeeTable, matchPtr - EmployeeTable);
    else
        printf("Employee phone number is NOT found in the record\n");

    //Example found for salary search
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.32);

    if (matchPtr != NULL)
        printf("Employee with salary $8.32 is in record %d %d %d\n", matchPtr, EmployeeTable, matchPtr - EmployeeTable);
    else
        printf("Employee salary is NOT found in the record\n");

    //Example not found for salary search
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 4.35);

    if (matchPtr != NULL)
        printf("Employee with salary $4.35 is in record %d %d %d\n", matchPtr, EmployeeTable, matchPtr - EmployeeTable);
    else
        printf("Employee salary is NOT found in the record\n");
    EXIT_SUCCESS;
}