//gcc employeeMain.c employeeTable.c employeeOne.c
//gcc employeeMain.c employeeTable.c employeeTwo.c
#include<stdio.h>
#include<stdlib.h>
#include "employee.h"

int main(void) {
    //define in employeeOne.c or employeeTwo.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * numeToFind);

    //defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;   //Declaration
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    //Example not found
    if (matchPtr !- NULL)
        printf("Employee IO 1045 is in record %d\n", matchPtr, EmployeeTable);
    else
        printf("Employee IO is NOT found in the record\n");
    
    //Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");

    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d %d %d\n", matchPtr, EmployeeTable, matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");
    EXIT_SUCCESS
}