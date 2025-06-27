/* #include <iostream>
//using namespace std;

//函数声明
int max(int,int);

int main(){
    int a = 100;
    int b = 20;

    //cout<<"最大值为:"<< max(a,b) << endl;
    std::cout<<"最大值为:"<< max(a,b) << std::endl;
}

int max(int num1,int num2){
    if(num1 > num2){
        return num1;
    }else{
        return num2;
    }
} */

/* #include <iostream>
//using namespace std;

void swap(int,int);

int main(){
    int a = 100;
    int b = 200;

    std::cout <<"交换前a:"<< a << "交换前b:"<< b << std::endl;
    swap(a,b);
    std::cout <<"交换后a:"<< a << "交换后b:"<< b << std::endl;
}

void swap(int x,int y){
    int temp;
    
    temp = x;
    x = y;
    y = temp;
} */

/* #include <iostream>

void swap(int *x, int *y);

int main(){
    int a = 111;
    int b = 222;

    std::cout<< "交换前a:"<< a << ",交换前b:"<< b << std::endl;

    swap(&a, &b);

    std::cout<< "交换后a:"<< a << ",交换后b:"<< b << std::endl;

}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
} */

/* #include <iostream>

void swap(int &x, int &y);

int main(){
    int a = 111;
    int b = 222;

    std::cout<< "交换前a:"<< a << ",交换前b:"<< b << std::endl;

    swap(a, b);

    std::cout<< "交换后a:"<< a << ",交换后b:"<< b << std::endl;

}

void swap(int &x, int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;
} */


/* #include <iostream>

int sum(int x,int y=1000);

int main(){
    int a = 100;
    //int b = 200;
    
    //std::cout<< sum(a,b) << std::endl;
    std::cout<< sum(a) << std::endl;
}

int sum(int x, int y){
    return x + y;
} */

//#include <iostream>

/* int main(){
    auto greet = []() {
        std::cout << "Hello, Lambda!"<< std::endl;
    };
    greet(); // 输出: Hello, Lambda!
}
 */
/* int main(){
    auto add = [](int a,int b){
        return a+b;
    };
    std::cout <<add(1,1)<<std::endl;
} */

/* #include <cmath> */

/* #include <iostream>
using namespace std;
 
int main()
{
   cout << "Hello" <<endl ; 
   cout << "world" ;
} */

/* #include <iostream>
int main(){
    double arrayN[]={10, 20 , 33.4, 1.1, 99.9};
    int size = sizeof(arrayN) / sizeof(arrayN[0]); // 计算数组长度
    
    for(int i=0; i<size; i++){
        std::cout << arrayN[i] <<"  ";
    }

    std::cout<<std::endl;   //这里用来换个行

    std::cout<< "修改后的数组:"<< std::endl;
    arrayN[100]=666.666;

    for(int i=0; i<size; i++){
        std::cout << arrayN[i] <<"  ";
    }

    std::cout<<arrayN[3];
} */

/* #include <iostream>
int main(){
    double arrayN[]={10, 20, 33.4, 1.1, 99.9};
    int size = sizeof(arrayN) / sizeof(arrayN[0]); // 计算数组长度
    
    arrayN[1]=666.666;

    for(int i=0; i<size; i++){
        std::cout << arrayN[i] <<"  ";
    }

    std::cout<<"按索引查询"<<std::endl;
    std::cout<<arrayN[3];
}
 */

/* #include <iostream>
int main(){
    int arrayN[] = {10, 20, 30, 40, 50};

    for(int i : arrayN){
        std::cout << i <<" ";
    }
} */

/* #include <iostream>
#include <iterator>
int main(){
    int arrayN[] = {10, 20, 30, 40, 50};

    int i = 0;
    int size =  sizeof(arrayN)/sizeof(arrayN[0]);
    while(i < size){
        std::cout << arrayN[i] << " ";
        i++;
    }
} */

/* #include <iostream>
#include <iterator>
int main(){
    int arrayN[] = {10, 20, 30, 40, 50};

    int i = 0;
    size_t size = std::size(arrayN);
    while(i < size){
        std::cout << arrayN[i] << " ";
        i++;
    }
} */

/* #include <iostream>
#include <array>
int main(){
    std::array<double,5> arrayN= {10, 20, 30, 40, 50};

    int i = 0;
    int size = arrayN.size();
    while(i < size){
        std::cout << arrayN[i] << " ";
        i++;
    }
} */

/* #include <iostream>
int main(){
    int arrayN[]={10, 20, 30, 40, 50};
    int size = sizeof(arrayN)/sizeof(arrayN[0]);
    int *p;

    p = arrayN;

    std::cout<<"第一个的值:"<<*p<<"\n";
    std::cout<<"第二个的值:"<<*(p+1)<<std::endl;
    std::cout<<"第三个的值:"<<*(arrayN+2)<<std::endl;

    std::cout <<"数组的值为:";
    for(int i=0; i<size; i++){
        std::cout << *(p+i)<<" ";
    }
} */

#include <iostream>

int main(){
    char arrayN[6]={'a','b','c','d','e','\0'};
    std::cout<<arrayN;
}