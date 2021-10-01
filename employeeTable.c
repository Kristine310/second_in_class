#include<stdio.h>
#include<stdlib.h>
#include "employee.h"

Employee EmployeeTable[] = 
{
    {10011, "Daphne Borromeo", "909-555-2134", 8.78},
    {10111, "Tammy Franklin", "213-555-1212", 4.50},
    {11401, "Dorris Perl", "310-555-1215", 7.80},
    {40111, "Tony Bobcat", "909-555-1235", 6.34},
    {50451, "Brian Height", "714-555-2749", 8.32}
};

const int EmployeeTableEntries = sizeof(EmployeeTable)/sizeof(EmployeeTable[0]);