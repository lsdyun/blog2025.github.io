#include <iostream>
#include <math.h>
using namespace std;

/* #define PI 3.1415

int main(){
    cout<<"PI为:" << PI << endl;
    return 0;
} */

int main(){
    const int SQUARE_SIDE_LENGTH = 10;
    int area = pow(SQUARE_SIDE_LENGTH,2);

    cout<< "正方形面积为:"<< area << endl;
}