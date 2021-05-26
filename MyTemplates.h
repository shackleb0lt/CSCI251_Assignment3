#ifndef MYTEMP_H
#define MYTEMP_H

#include<iostream>
#include<algorithm>

using namespace std;

template <typename T> 
bool equals(T P1,T P2){return (P1==P2);}

template <typename T> 
double scalar_difference(T P1,T P2){return (P1-P2);}

template <typename T> 
bool scalar_comp_asc(T P1,T P2)
{
    return (P1.getScalarValue()<P2.getScalarValue());
}

template <typename T> 
bool scalar_comp_dsc(T P1,T P2)
{
    return (P1.getScalarValue()>P2.getScalarValue());
}


/*
template <typename T> 
bool equals(T P1,T P2);

template <typename T> 
double scalar_difference(T P1,T P2);

template <typename T> 
bool scalar_comp_asc(T P1,T P2);

template <typename T> 
bool scalar_comp_dsc(T P1,T P2);
*/
#endif
