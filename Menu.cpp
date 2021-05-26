#include "Menu.h"

Menu::Menu()
{
    curr_filt_criteria="Point2D";
    curr_sort_criteria="x-ordinate";
    curr_sort_order="ASC";
}
void Menu::start()
{
    while(1){
        bool choice_flag = true;
        print_menu();
        while(choice_flag)
        {
            get_choice();
            switch(choice)
            {
                case 1:
                    read_data();
                    break;
                case 2:
                    spec_filt_criteria();
                    break;
                case 3:
                    spec_sort_criteria();
                    break;
                case 4:
                    spec_sort_order();
                    break;
                case 5:
                    view_data();
                    break;
                case 6:
                    store_data();
                    break;
                case 7:
                    cout<<"Thank You"<<endl;
                    return;
                    break;
                default:
                    cout<<"Entered choice is absent in menu!! Try again."<<endl;
                    choice_flag=false;
                    break;
            }
            choice_flag=!choice_flag;
        }
        
    }
}

void Menu::get_choice()
{
    cout<<"Please enter your choice :";
    cin>>choice;
    cout<<endl;
    cout<<endl;
}

void Menu::print_menu()
{
    cout<<endl;
    cout<<"1)   Read in data"<<endl;
    cout<<"2)   Specify filtering criteria (current : "<<curr_filt_criteria<<")"<<endl;
    cout<<"3)   Specify sorting criteria (current : "<<curr_sort_criteria<<")"<<endl;
    cout<<"4)   Specify sorting order (current : "<<curr_sort_order<<")"<<endl;
    cout<<"5)   View data"<<endl;
    cout<<"6)   Store data"<<endl;
    cout<<"7)   Exit program"<<endl;
    cout<<endl;
}
void Menu::read_data()
{
    cout<<"Please enter filename : ";
    cin>>in_filename;
    cout<<endl;
    cout<<endl;
    int line=table.read_data(in_filename);
    if (line == -1) {cout<<endl<<"Going back to main menu ..."<<endl; return;}
    cout<<line<<" records read in successfully!"<<endl;
    table.remove_duplicates();
    cout<<endl<<"Going back to main menu ..."<<endl;
    cout<<endl;
}

void Menu::spec_filt_criteria()
{
    char op;
    cout<<"[ Specifying filtering criteria (current : "<<curr_filt_criteria<<") ]"<<endl;
    cout<<endl;
    cout<<"\ta)   Point2D records"<<endl;
    cout<<"\tb)   Point3D records"<<endl;
    cout<<"\tc)   Line2D records"<<endl;
    cout<<"\td)   Line3D records"<<endl;
    cout<<endl;
    cout<<"\tPlease enter your criteria(a-d):";
    cin>>op;
    switch(op)
    {
        case('a'):
            curr_filt_criteria="Point2D";
            curr_sort_criteria="X-ordinate";
            break;
        case('b'):
            curr_filt_criteria="Point3D";
            curr_sort_criteria="X-ordinate";
            break;
        case('c'):
            curr_filt_criteria="Line2D";
            curr_sort_criteria="Pt. 1";
            break;
        case('d'):
            curr_filt_criteria="Line3D";
            curr_sort_criteria="Pt. 1";
            break;
        default:
            break;
    }
    cout<<endl;
    cout<<"    Filter criteria successfully set to'"<<curr_filt_criteria<<"'!"<<endl;
    cout<<"..."<<endl;
}

void Menu::spec_sort_criteria()
{
    char op;
    cout<<"[ Specifying sorting criteria (current : "<<curr_sort_criteria<<") ]"<<endl;
    cout<<endl;
    if(curr_filt_criteria=="Point2D")P2Dsort();
    
    else if(curr_filt_criteria=="Point3D")P3Dsort();
            
    else if(curr_filt_criteria=="Line2D")L23Dsort();
            
    else if(curr_filt_criteria=="Line3D")L23Dsort();
    
    cout<<"\tFilter criteria successfully set to'"<<curr_sort_criteria<<"'!\n";
    cout<<"...\n";
}
void Menu::P2Dsort()
{
    char op;
    cout<<"\ta)\tX ordinate value\n";
    cout<<"\tb)\tY ordinate value\n";
    cout<<"\tc)\tDist From Origin value\n";
    cout<<endl;
    cout<<"\tPLease enter your criteria(a-c) :";
    cin>>op;     cout<<endl;
    switch(op)
    {
        case('a'):
            curr_sort_criteria="X-ordinate";
            break;
        case('b'):
            curr_sort_criteria="Y-ordinate";
            break;
        case('c'):
            curr_sort_criteria="Dist";
            break;
        default:
            break;
    }

}
void Menu::P3Dsort()
{
    char op;
    cout<<"\ta)\tX ordinate value\n";
    cout<<"\tb)\tY ordinate value\n";
    cout<<"\tc)\tZ ordinate value\n";
    cout<<"\td)\tDist From Origin value\n";
    
    cout<<endl;
    cout<<"\tPLease enter your criteria(a-d) :";
    cin>>op;     cout<<endl;
    switch(op)
    {
        case('a'):
            curr_sort_criteria="X-ordinate";
            break;
        case('b'):
            curr_sort_criteria="Y-ordinate";
            break;
        case('c'):
            curr_sort_criteria="Z-ordinate";
            break;
        case('d'):
            curr_sort_criteria="Dist";
            break;
        default:
            break;
    }
}
void Menu::L23Dsort()
{
    char op;
    cout<<"\ta)\tPt. 1`s(x,y)  values\n";
    cout<<"\tb)\tPt. 2`s(x,y)  values\n";
    cout<<"\tc)\tLength value\n";

    cout<<endl;
    cout<<"\tPLease enter your criteria(a-c) :";
    cin>>op;     cout<<endl;
    switch(op)
    {
        case('a'):
            curr_sort_criteria="Pt. 1";
            break;
        case('b'):
            curr_sort_criteria="Pt. 2";
            break;
        case('c'):
            curr_sort_criteria="Length";
            break;
        default:
            break;
    }
}

void Menu::spec_sort_order()
{
    char op;
    cout<<"[ Specifying sorting order (current : "<<curr_sort_order<<") ]\n";
    cout<<endl;
    cout<<"\ta)\tASC (Ascending order)\n";
    cout<<"\tb)\tDSC (Descending order)\n";
    cout<<endl;
    cout<<"\tPlease enter your criteria(a-b) :";
    cin>>op;
    switch(op)
    {
        case('a'):
            curr_sort_order="ASC";
            break;
        case('b'):
        curr_sort_order="DSC";
            break;
        default:
            break;
    }
    cout<<endl;
    cout<<"\tSorting order successfully set to'"<<curr_sort_order<<"'!\n";
    cout<<"..."<<endl;
}

void Menu::view_data()
{
    cout<<"[View data ... ]\n";
    cout<<"filtering criteria : "<<curr_filt_criteria<<endl;
    cout<<"sorting criteria : "<<curr_sort_criteria<<endl;
    cout<<"sorting order : "<<curr_sort_order<<endl;
    cout<<endl;
    table.sort_data(curr_filt_criteria,curr_sort_criteria,curr_sort_order);
    table.view_data(curr_filt_criteria,curr_sort_criteria,curr_sort_order);
    cout<<"Press any key to go back to main menu ...";
    char esc;
    cin>>esc;
    cout<<endl<<endl;
}
void Menu::store_data()
{
    cout<<"Please enter filename :";
    cin>>op_filename;
    cout<<endl<<endl;

    table.sort_data(curr_filt_criteria,curr_sort_criteria,curr_sort_order);
    cout<<table.store_data(op_filename,curr_filt_criteria);

    cout<<" records output succesfully!\n\n";
    cout<<"Going back to main menu ...\n";
}

