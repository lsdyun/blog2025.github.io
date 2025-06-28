#include<iostream>

/* int main(){
    int *b;
    int a = 100;

    std::cout << "a的值为:" << a << std::endl;
    std::cout << "&a的值为:" << &a << std::endl;

    b = &a; //把a的地址赋值给指针b

    std::cout << "b指针的值为:" << b <<std::endl;
    std::cout << "*b指针的值为:" << *b <<std::endl;

} */

/* int main(){
    int *x = NULL;
    std::cout << "x的值:" << x << std::endl;
} */

/* int main(){
    int *a;
    std::cout << "a的初始地址为:" << a <<std::endl;

    a--;
    std::cout << "a的新地址为:" << a <<std::endl;
}
 */

/* int main(){
    int x = 100;
    int y = 300;
    int *a;
    int *b;

    a = &x;
    b = &y;

    std::cout << "a为:"<< a <<std::endl;
    std::cout << "b为:"<< b <<std::endl;
    std::cout << "a-b为:"<< a-b <<std::endl;
    //std::cout << "a+b为:"<< a+b <<std::endl;
}
 */

/* int main(){
    int arrayN[]={10, 20, 30, 40, 50};
    int size = sizeof(arrayN)/sizeof(arrayN[0]);	//计算数组大小
    int *p;

    p = arrayN;

    std::cout<<"第一个的值:"<<*p<<"\n";
    std::cout<<"第二个的值:"<<*(p+1)<<std::endl;
    std::cout<<"第三个的值:"<<*(arrayN+2)<<std::endl;

    *(p + 4) = 100;

    std::cout <<"数组的值为:";
    for(int i=0; i<size; i++){
        std::cout << *(p+i)<<" ";
    }
} */

/* int main(){
    int arr[] = {10, 20, 30};

    int size = sizeof(arr)/sizeof(arr[0]);	//计算数组大小

    int *ptr[size]; 

    for(int i=0; i<size; i++){
        ptr[i] = &arr[i];   //把arr的地址赋值给ptr
    }

    for(int i=0; i<size; i++){
        std::cout << *ptr[i] <<" ";
    }
} */

/* int main(){
    const char *arr[] = {"10", "20", "30"};

    int size = sizeof(arr)/sizeof(arr[0]);	//计算数组大小

    for(int i=0; i<size; i++){
        std::cout << arr[i] <<" ";
    } 

} */

/* int main(){
    int x = 100;
    int *a;
    int **b;

    //将x的地址赋值给a
    a = &x;
    //将a的地址赋值给b
    b = &a;

    std::cout<<"x的地址为:"<< &x << std::endl;
    std::cout<<"a的地址为:"<< a << std::endl;
    std::cout<<"a的值为:"<< *a << std::endl;
    std::cout<<"b的地址为:"<< b << std::endl;
    std::cout<<"b的指向的地址为:"<< *b << std::endl;
    std::cout<<"b的值为:"<< **b << std::endl;
} */

/* int main(){
    int a = 100;

    int &x =a;  //引用

    std::cout << "a的地址为:" << &a << std::endl;
    std::cout << "a的值为:" << a << std::endl;
    std::cout << "x的地址为:" << &x << std::endl;
    std::cout << "x的值为:" << x << std::endl;
}
 */

/* #include<ctime>
int main(){
    //获取当前系统时间
    time_t now = time(0);
    
    //把now转化为字符串
    char *dt = ctime(&now);

    std::cout << "本地时间为:" << dt << std::endl;

    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    std::cout << "UTC 日期和时间："<< dt << std::endl;
}
 */

/* int main(){
    char word[100];
    std::cout << "请输入:" ;

    std::cin>>word;
    
    std::cout << "输入的文本为:" << word << std::endl;
} */

/* int main(){
    char word[] = "hahah";
    std::cerr << "Error:" << word;
} */

/* #include<cstring>
struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

int main(){
    Books book;    // 定义结构体类型 Books 的变量 book1
    
    //往结构体中添加数据
    strcpy(book.title,"C++ 教程");
    strcpy(book.author, "Runoob"); 
    strcpy(book.subject, "编程语言");
    book.book_id = 12345;

    //输出数据
    std::cout <<"标题:"<< book.title << std::endl;
    std::cout <<"作者:"<< book.author << std::endl;
    std::cout <<"类目:"<< book.subject << std::endl;
    std::cout <<"ID:"<< book.book_id << std::endl;
}
 */

/* #include<cstring>
struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

//函数声明
void printBook(struct  Books book);

int main(){
    Books test_book;    // 定义结构体类型 Books 的变量 book1
    
    //往结构体中添加数据
    strcpy(test_book.title,"C++ 教程");
    strcpy(test_book.author, "Runoob"); 
    strcpy(test_book.subject, "编程语言");
    test_book.book_id = 12345;

    //输出数据
    printBook(test_book);
}

void printBook(struct Books book){
    std::cout <<"标题:"<< book.title << std::endl;
    std::cout <<"作者:"<< book.author << std::endl;
    std::cout <<"类目:"<< book.subject << std::endl;
    std::cout <<"ID:"<< book.book_id << std::endl;
}; */


/* #include<string>

struct Books
{
    std::string title;
    std::string author;
    std::string subject;
    int book_id;
    //构造函数
    Books(std::string t, std::string a, std::string s, int id)
        : title(t), author(a), subject(s), book_id(id){}
};

//函数声明
void printBook(const Books *book);

int main(){
    //创建对象
    Books test_book("C++ 教程", "Runoob", "编程语言", 12345);

    //使用指针指向对象
    Books *ptrBook = &test_book;

    //输出信息
    printBook(ptrBook);
}

// 打印书籍信息的函数，接受一个指向 Books 结构体的指针
void printBook(const Books *book){
    std::cout <<"标题:"<< book->title << std::endl;
    std::cout <<"作者:"<< book->author << std::endl;
    std::cout <<"类目:"<< book->subject << std::endl;
    std::cout <<"ID:"<< book->book_id << std::endl;
}; */


/* #include<cstring>

typedef struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
}hah;

int main(){
    hah book;    // 定义结构体类型 Books 的变量 book1
    
    //往结构体中添加数据
    strcpy(book.title,"C++ 教程");
    strcpy(book.author, "Runoob"); 
    strcpy(book.subject, "编程语言");
    book.book_id = 12345;

    //输出数据
    std::cout <<"标题:"<< book.title << std::endl;
    std::cout <<"作者:"<< book.author << std::endl;
    std::cout <<"类目:"<< book.subject << std::endl;
    std::cout <<"ID:"<< book.book_id << std::endl;
} */

/* #include<cstring>

struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
}hah;

int main(){
    
    //往结构体中添加数据
    strcpy(hah.title,"C++ 教程");
    strcpy(hah.author, "Runoob"); 
    strcpy(hah.subject, "编程语言");
    hah.book_id = 12345;

    //输出数据
    std::cout <<"标题:"<< hah.title << std::endl;
    std::cout <<"作者:"<< hah.author << std::endl;
    std::cout <<"类目:"<< hah.subject << std::endl;
    std::cout <<"ID:"<< hah.book_id << std::endl;
} */

/* #include<vector>
int main(){
    // 创建空vector
    std::vector<int> myVector;

    //添加
    myVector.push_back(1);
    myVector.push_back(11);
    myVector.push_back(99);

    //迭代访问
    std::cout << "Vector包含:" ;
    for(int element : myVector){
        std::cout << element << " ";
    }
    std::cout <<"\n";   //换个行，等价于std::cout << std::endl;

    //访问元素
    std::cout << "第一个元素为:" << myVector[0] << std::endl;
    std::cout << "第二个元素为:" << myVector.at(1) << std::endl;

    //获取大小
    std::cout << "vector的大小为:" << myVector.size() << std::endl;

    //删除第三个元素
    myVector.erase(myVector.begin()+2);

    //输出删除后的vector
    std::cout << "删除元素后,Vector包含:" ;
    for(int element : myVector){
        std::cout << element << " ";
    }
    std::cout <<"\n";   //换个行，等价于std::cout << std::endl;

    //清空vector
    myVector.clear();
    std::cout << "vector已被清空,vector大小为:" << myVector.size() << std::endl;

} */

int main(){
    
}