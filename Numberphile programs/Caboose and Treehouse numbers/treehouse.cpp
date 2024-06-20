#include <iostream>
#include <math.h>
using namespace std;

long double tree(int h){
    return pow(M_El, M_PIl * sqrt((long double)h));
};
//https://youtu.be/mw4DM1952KI?si=woAsODUw4SrEWNXc&t=391
int main(){
    cout << fixed << tree(163) << endl; //Some of the other numbers used in the video are suspiciously close to integers, but for some reason not the same values ??
}