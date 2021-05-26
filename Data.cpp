#include "Data.h"
#include "MyTemplates.h"



void Data::process(string l)
{
    string word,t;
    stringstream S(l);
    string sx,sy,sz;
    string sx1,sy1,sz1;
    S>>word;
    if(word=="Point2D,")
    {
        S>>word;
        sx=word.substr(1,word.size()-2);


        S>>word;
        sy=word.substr(0,word.size()-1);


        P2D.push_back(Point2D(stoi(sx),stoi(sy)));
        P2D[P2D.size()-1].setDistFrOrigin();
    }
    else if(word=="Point3D,")
    {
        S>>word;
        sx=word.substr(1,word.size()-2);


        S>>word;
        sy=word.substr(0,word.size()-1);


        S>>word;
        sz=word.substr(0,word.size()-1);  


        P3D.push_back(Point3D(stoi(sx),stoi(sy),stoi(sz)));
        P3D[P3D.size()-1].setDistFrOrigin();
    }
    else if(word=="Line2D,")
    {
        S>>word;
        sx=word.substr(1,word.size()-2);

        S>>word;
        sy=word.substr(0,word.size()-2);


        S>>word;
        sx1=word.substr(1,word.size()-2);

        
        S>>word;
        sy1=word.substr(0,word.size()-1);


        L2D.push_back(Line2D(Point2D(stoi(sx),stoi(sy)),Point2D(stoi(sx1),stoi(sy1))));
        L2D[L2D.size()-1].setLength();
    }
    else if(word=="Line3D,")
    {
        S>>word;
        sx=word.substr(1,word.size()-2);
        S>>word;
        sy=word.substr(0,word.size()-1);
        S>>word;
        sz=word.substr(0,word.size()-2);

        S>>word;
        sx1=word.substr(1,word.size()-2);
        S>>word;
        sy1=word.substr(0,word.size()-1);
        S>>word;
        sz1=word.substr(0,word.size()-1);
        L3D.push_back(Line3D(Point3D(stoi(sx),stoi(sy),stoi(sz)),Point3D(stoi(sx1),stoi(sy1),stoi(sz1))));
        L3D[L3D.size()-1].setLength();
    }
}
int Data::read_data(string filename)
{
    ifstream fin; 
    string line;

    fin.open(filename); 
    int line_count=0;
    if(!fin)
    {
        cout<<"\nFiles does not exist\n";
        return -1;
    }
    while (true) { 
        
        getline(fin, line);                 // Read a Line from File
        process(line);
        if(line.size()>=1)line_count++;
        if(fin.eof())break;                 // Execute a loop until EOF (End of File) 
        
        
    }


    fin.close();
    return line_count;
    
}

// template <typename T> 
void Data::remove_duplicates()
{
    sort_data("Point2D","X-ordinate","ASC");
    sort_data("Point3D","X-ordinate","ASC");
    sort_data("Line2D","Pt. 1","ASC");
    sort_data("Line3D","Pt. 1","ASC");

    vector<Point2D>::iterator ip1 = std::unique(P2D.begin(), P2D.end(),equals<Point2D>); 
    P2D.resize(std::distance(P2D.begin(), ip1)); 
    auto ip2 = std::unique(P3D.begin(), P3D.end(),equals<Point3D>); 
    P3D.resize(std::distance(P3D.begin(), ip2)); 
    auto ip3 = std::unique(L2D.begin(), L2D.end(),equals<Line2D>); 
    L2D.resize(std::distance(L2D.begin(), ip3)); 
    auto ip4 = std::unique(L3D.begin(), L3D.end(),equals<Line3D>); 
    L3D.resize(std::distance(L3D.begin(), ip4)); 
}


void Data::view_data(string filt_criteria,string sort_criteria,string sort_order)
{
    if(filt_criteria=="Point2D")
    {
        cout<<"    X    Y    Dist. Fr Origin"<<endl;
        cout<<"-------------------------------"<<endl;
        for(auto ip=P2D.begin();ip!=P2D.end();ip++)cout<<(*ip);
    }
    else if(filt_criteria=="Point3D")
    {
        cout<<"    X    Y    Z    Dist. Fr Origin"<<endl;
        cout<<"-------------------------------------"<<endl;
        for(auto ip=P3D.begin();ip!=P3D.end();ip++)cout<<(*ip);
    }
    else if(filt_criteria=="Line2D")
    {
        cout<<" P1-X P1-Y     P2-X P2-Y    Length"<<endl;
        cout<<"-------------------------------------"<<endl;
        for(auto ip=L2D.begin();ip!=L2D.end();ip++)cout<<(*ip);
    }
    else if(filt_criteria=="Line3D")
    {
        cout<<" P1-X P1-Y P1-Z     P2-X P2-Y P2-Z    Length"<<endl;
        cout<<"-------------------------------------------------"<<endl;
        for(auto ip=L3D.begin();ip!=L3D.end();ip++)cout<<(*ip);
    }
    cout<<endl<<". . ."<<endl;
}


bool Data::less_than_x_2D(Point2D P1,Point2D P2)
{
    if(P1.getX()==P2.getX())return (P1.getY()<P2.getY());
    return P1.getX()<P2.getX();
}
bool Data::less_than_x_3D(Point3D P1,Point3D P2)
{   
    if(P1.getX()==P2.getX())
    {
        if(P1.getY()==P2.getY()) return (P1.getZ()<P2.getZ());
        return (P1.getY()<P2.getY());
    }
    return (P1.getX()<P2.getX()); 
}

bool Data::greater_than_x_2D(Point2D P1,Point2D P2)
{ 
    if(P1.getX()==P2.getX())return (P1.getY()<P2.getY());
    return (P1.getX()>P2.getX());
}
bool Data::greater_than_x_3D(Point3D P1,Point3D P2)
{
    if(P1.getX()==P2.getX())
    {
        if(P1.getY()==P2.getY()) return (P1.getZ()<P2.getZ());
        return (P1.getY()<P2.getY());
    }
    return (P1.getX()>P2.getX()); 
}

bool Data::less_than_y_2D(Point2D P1,Point2D P2)
{ 
    if(P1.getY()==P2.getY())return (P1.getX()<P2.getX());
    return (P1.getY()<P2.getY()); 
}
bool Data::less_than_y_3D(Point3D P1,Point3D P2)
{   
    if(P1.getY()==P2.getY())
    {
        if(P1.getX()==P2.getX()) return (P1.getZ()<P2.getZ());
        return (P1.getX()<P2.getX());
    }
    return (P1.getY()<P2.getY()); 
}

bool Data::greater_than_y_2D(Point2D P1,Point2D P2){ 
    if(P1.getY()==P2.getY())return (P1.getX()<P2.getX());
    return (P1.getY()>P2.getY()); 
}
bool Data::greater_than_y_3D(Point3D P1,Point3D P2)
{ 
    if(P1.getY()==P2.getY())
    {
        if(P1.getX()==P2.getX()) return (P1.getZ()<P2.getZ());
        return (P1.getX()<P2.getX());
    } 
    return (P1.getY()>P2.getY());
}


bool Data::less_than_z_3D(Point3D P1,Point3D P2)
{
    if(P1.getZ()==P2.getZ())
    {
        if(P1.getX()==P2.getX()) return (P1.getY()<P2.getY());
        return (P1.getX()<P2.getX());
    }     
    return (P1.getZ()<P2.getZ());
}
bool Data::greater_than_z_3D(Point3D P1,Point3D P2)
{   
    if(P1.getZ()==P2.getZ())
    {
        if(P1.getX()==P2.getX()) return (P1.getY()<P2.getY());
        return (P1.getX()<P2.getX());
    } 
    return (P1.getZ()>P2.getZ());
}


bool Data::less_than_P1_2D(Line2D L1,Line2D L2)
{
    if(less_than_x_2D(L1.getPt1(),L2.getPt1()))return true;
    else if(L1.getPt1().getX()==L2.getPt1().getX())return less_than_y_2D(L1.getPt1(),L2.getPt1());
    return false;
}
bool Data::greater_than_P1_2D(Line2D L1,Line2D L2){return !less_than_P1_2D(L1,L2);}

bool Data::less_than_P2_2D(Line2D L1,Line2D L2)
{
    if(less_than_x_2D(L1.getPt2(),L2.getPt2()))return true;
    else if(L1.getPt2().getX()==L2.getPt2().getX())return less_than_y_2D(L1.getPt2(),L2.getPt2());
    return false;
}
bool Data::greater_than_P2_2D(Line2D L1,Line2D L2){return !less_than_P2_2D(L1,L2);}


bool Data::less_than_P1_3D(Line3D L1,Line3D L2)
{
    if(less_than_x_3D(L1.getPt1(),L2.getPt1()))return true;
    else if(L1.getPt1().getX()==L2.getPt1().getX())return less_than_y_3D(L1.getPt1(),L2.getPt1());
    return false;
}
bool Data::greater_than_P1_3D(Line3D L1,Line3D L2){return !less_than_P1_3D(L1,L2);}

bool Data::less_than_P2_3D(Line3D L1,Line3D L2)
{
    if(less_than_x_3D(L1.getPt2(),L2.getPt2()))return true;
    else if(L1.getPt2().getX()==L2.getPt2().getX())return less_than_y_3D(L1.getPt2(),L2.getPt2());
    return false;
}
bool Data::greater_than_P2_3D(Line3D L1,Line3D L2){return !less_than_P2_3D(L1,L2);}



void Data::sort_data(string filt_criteria,string sort_criteria,string sort_order)
{
    if(filt_criteria=="Point2D")
    {
        if(sort_criteria=="X-ordinate")
        {
            if(sort_order=="ASC")std::sort(P2D.begin(),P2D.end(),less_than_x_2D);
            else if(sort_order=="DSC")std::sort(P2D.begin(),P2D.end(),greater_than_x_2D);
        }
        else if(sort_criteria=="Y-ordinate")
        {
            if(sort_order=="ASC")std::sort(P2D.begin(),P2D.end(),less_than_y_2D);
            else if(sort_order=="DSC")std::sort(P2D.begin(),P2D.end(),greater_than_y_2D);
        }
        else if (sort_criteria=="Dist")
        {
            if(sort_order=="ASC")std::sort(P2D.begin(),P2D.end(),scalar_comp_asc<Point2D>);
            else if(sort_order=="DSC")std::sort(P2D.begin(),P2D.end(),scalar_comp_dsc<Point2D>);
        }
    }
    
    else if(filt_criteria=="Point3D")
    {
        if(sort_criteria=="X-ordinate")
        {
            if(sort_order=="ASC")std::sort(P3D.begin(),P3D.end(),less_than_x_3D);
            else if(sort_order=="DSC")std::sort(P3D.begin(),P3D.end(),greater_than_x_3D);
        }
        else if(sort_criteria=="Y-ordinate")
        {
            if(sort_order=="ASC")std::sort(P3D.begin(),P3D.end(),less_than_y_3D);
            else if(sort_order=="DSC")std::sort(P3D.begin(),P3D.end(),greater_than_y_3D);
        }
        else if(sort_criteria=="Z-ordinate")
        {
            if(sort_order=="ASC")std::sort(P3D.begin(),P3D.end(),less_than_z_3D);
            else if(sort_order=="DSC")std::sort(P3D.begin(),P3D.end(),greater_than_z_3D);
        }
        else if (sort_criteria=="Dist")
        {
            if(sort_order=="ASC")std::sort(P3D.begin(),P3D.end(),scalar_comp_asc<Point3D>);
            else if(sort_order=="DSC")std::sort(P3D.begin(),P3D.end(),scalar_comp_dsc<Point3D>);
        }
    }
    
    else if(filt_criteria=="Line2D")
    {        
        if(sort_criteria=="Pt. 1")
        {
            if(sort_order=="ASC")std::sort(L2D.begin(),L2D.end(),less_than_P1_2D);
            else if(sort_order=="DSC")std::sort(L2D.begin(),L2D.end(),greater_than_P1_2D);
        }
        else if(sort_criteria=="Pt. 2")
        {
            if(sort_order=="ASC")std::sort(L2D.begin(),L2D.end(),less_than_P2_2D);
            else if(sort_order=="DSC")std::sort(L2D.begin(),L2D.end(),greater_than_P2_2D);
        }
        else if(sort_criteria=="Length")
        {
            if(sort_order=="ASC")std::sort(L2D.begin(),L2D.end(),scalar_comp_asc<Line2D>);
            else if(sort_order=="DSC")std::sort(L2D.begin(),L2D.end(),scalar_comp_dsc<Line2D>);
        }
    
    }
    else if(filt_criteria=="Line3D")
    {        
        if(sort_criteria=="Pt. 1")
        {
            if(sort_order=="ASC")std::sort(L3D.begin(),L3D.end(),less_than_P1_3D);
            else if(sort_order=="DSC")std::sort(L3D.begin(),L3D.end(),greater_than_P1_3D);
        }
        else if(sort_criteria=="Pt. 2")
        {
            if(sort_order=="ASC")std::sort(L3D.begin(),L3D.end(),less_than_P2_3D);
            else if(sort_order=="DSC")std::sort(L3D.begin(),L3D.end(),greater_than_P2_3D);
        }
        else if(sort_criteria=="Length")
        {
            if(sort_order=="ASC")std::sort(L3D.begin(),L3D.end(),scalar_comp_asc<Line3D>);
            else if(sort_order=="DSC")std::sort(L3D.begin(),L3D.end(),scalar_comp_dsc<Line3D>);
        }
    }
    return;
}

int Data::store_data(string filename,string filt_criteria)
{
    ofstream fout; 
  
    string line; 
    int count =0;
    fout.open(filename); 

    if(filt_criteria=="Point2D")
    {
        fout<<"    X    Y    Dist. Fr Origin"<<endl;
        fout<<"-------------------------------"<<endl;
        for(auto ip=P2D.begin();ip!=P2D.end();ip++){fout<<(*ip);count++;}
    }
    else if(filt_criteria=="Point3D")
    {
        fout<<"    X    Y    Z    Dist. Fr Origin"<<endl;
        fout<<"-------------------------------------"<<endl;
        for(auto ip=P3D.begin();ip!=P3D.end();ip++){fout<<(*ip);count++;}
    }
    else if(filt_criteria=="Line2D")
    {
        fout<<" P1-X P1-Y     P2-X P2-Y    Length"<<endl;
        fout<<"-------------------------------------"<<endl;
        for(auto ip=L2D.begin();ip!=L2D.end();ip++){fout<<(*ip);count++;}
    }
    else if(filt_criteria=="Line3D")
    {
        fout<<" P1-X P1-Y P1-Z     P2-X P2-Y P2-Z    Length"<<endl;
        fout<<"-------------------------------------------------"<<endl;
        for(auto ip=L3D.begin();ip!=L3D.end();ip++){fout<<(*ip);count++;}
    }
    cout<<endl<<". . ."<<endl;
  
    fout.close();
    return count;
}