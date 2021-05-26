#ifndef CONTAINER_H
#define CONTAINER_H
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<iomanip>
#include<fstream>
#include<sstream>


#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"
#include "MyTemplates.h"

using namespace std;

class Data
{
    public:
    vector<Point2D> P2D;                                                                //vectore to store all 2D Points
    vector<Point3D> P3D;                                                                //vectore to store all 3D Points
    vector<Line2D> L2D;                                                                 //vectore to store all 2D Lines
    vector<Line3D> L3D;                                                                 //vectore to store all 3D Lines

    int read_data(string filename);                                                     //method to read_data from file
    int store_data(string filename,string filt_criteria);                               //method to store_data to a file

    void sort_data(string filt_criteria,string sort_criteria,string sort_order);        //method to sort_data of any class type
    void view_data(string filt_criteria,string sort_criteria,string sort_order);        //method to print specified data
    
    void process(string l);                                                             //helper method to process a string to obtain data types

    // template <typename T> 
    void remove_duplicates();//vector<T> &v);                                               //helper method to remove duplicate data

    //HELPER COMPARATOR FUNCTION FOR SORTING 
    //GIVES RANDOM ITERATOR ERROR FOR GENERIC FUNCTION HENCE DEFINED INDIVIDUALLY
    static bool less_than_x_2D(Point2D P1,Point2D P2);
    static bool less_than_x_3D(Point3D P1,Point3D P2);
    
    static bool greater_than_x_2D(Point2D P1,Point2D P2);
    static bool greater_than_x_3D(Point3D P1,Point3D P2);
   
    static bool less_than_y_2D(Point2D P1,Point2D P2);
    static bool less_than_y_3D(Point3D P1,Point3D P2);

    static bool greater_than_y_2D(Point2D P1,Point2D P2);
    static bool greater_than_y_3D(Point3D P1,Point3D P2);

    static bool less_than_z_3D(Point3D P1,Point3D P2);
    static bool greater_than_z_3D(Point3D P1,Point3D P2);

    static bool less_than_P1_2D(Line2D L1,Line2D L2);
    static bool greater_than_P1_2D(Line2D L1,Line2D L2);
    static bool less_than_P2_2D(Line2D L1,Line2D L2);
    static bool greater_than_P2_2D(Line2D L1,Line2D L2);

    static bool less_than_P1_3D(Line3D L1,Line3D L2);
    static bool greater_than_P1_3D(Line3D L1,Line3D L2);
    static bool less_than_P2_3D(Line3D L1,Line3D L2);
    static bool greater_than_P2_3D(Line3D L1,Line3D L2);

};
#endif
