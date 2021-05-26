#ifndef MENU_H
#define MENU_H
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<iomanip>
#include<sstream>


#include "Data.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"
#include "MyTemplates.h"

using namespace std;
// Header file for the menu class describing all the methods and variables.
class Menu
{
    private:
    //Attributes
    int choice;                     //Attribute to store the choice entered by user
    string in_filename;             //Attribute to store the input file name entered by user
    string op_filename;             //Attribute to store the output file name entered by user
    string curr_filt_criteria;      //Attribute to store the preferred filtering criteria
    string curr_sort_criteria;      //Attribute to store the preferred sorting criteria
    string curr_sort_order;         //Attribute to store the preferred sorting order

    //Methods
    
    void print_menu();              //Method to print out the menu and get the choice
    void get_choice();               //Method to get choice for the menu
    void read_data();               //Method to read data from a file
    void spec_filt_criteria();      //Method to select filtering criteria
    void spec_sort_criteria();      //Method to select sorting criteria
    void spec_sort_order();         //Method to select sorting order
    void view_data();              //Method to view data according to preferences
    void store_data();             //Method to store data according into output file 

    void P2Dsort();                //Helper methods
    void P3Dsort();                //to print 
    void L23Dsort();               //sorting criteria


    public:
    Menu();
    void start();  
    Data table;           
};

#endif