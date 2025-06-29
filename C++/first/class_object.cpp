#include<iostream>
/* 
class Box{
    public:
        //成员变量
        double length;
        double breadth;
        double height;
        //成员函数声明
        double get(void);
        void set(double l, double b, double h); 
};
//成员函数定义
double Box::get(void){
    return length * breadth * height;
}

void Box::set(double l, double b, double h){
    length = l;
    breadth = b;
    height = h;
}

int main(){
    double volume = 0; //体积
    //方法一
    Box box1;    //定义对象一

    box1.length = 10;
    box1.breadth = 20;
    box1.height = 30;

    volume = box1.length * box1.breadth * box1.height;
    std::cout << "体积为:" << volume << std::endl;

    //方法二
    Box box2;
    box2.set(1,2,3);
    volume = box2.get();
    std::cout<< "体积为:" << volume << std::endl;
} */

/* class Box{
    public:
        //成员变量
        double length;
        double breadth;
        double height;
        //成员函数声明
        double get(void)
        {
            return length * breadth * height;
        };
        void set(double l, double b, double h)
        {
            length = l;
            breadth = b;
            height = h;
        }; 
};
 */
/* class Box{
    public:
        //成员变量
        double length;
        double height;
        //成员函数声明
        double getLength(void);
        double getHeight(void);
        void setLength(double l); 
        void setHeight(double h); 

        double getBreadth(void);
        void setBreadth(double b); 
    private:
        double breadth;
       
};
//成员函数定义
double Box::getLength(void){
    return length;
}
double Box::getBreadth(void){
    return breadth;
}
double Box::getHeight(void){
    return height;
}

void Box::setLength(double l){
    length = l;
}
void Box::setBreadth(double b){
    breadth = b;
}
void Box::setHeight(double h){
    height = h;
}

int main(){
    Box box;

    //public 赋值
    std::cout <<"public:" << std::endl;
    //不使用get和set方法
    box.length = 1;
    std::cout << "不使用get和set方法:" << box.length << std::endl;
    //使用get和set方法
    box.setLength(100);
    std::cout << "使用get和set方法:" << box.getLength() << std::endl;

    //private 赋值
    std::cout <<"private:" << std::endl;
    //box.breadth = 2;  //不能使用，因为私有
    box.setBreadth(200);
    std::cout << "使用get和set方法:" << box.getBreadth() << std::endl;
} */

/* class Box{
    protected:
        //成员变量
        double height;     
};

// 继承
class OtherBox:Box{
    public:
        //成员函数声明
        double getHeight(void);
        void setHeight(double h);   
};

//成员函数定义
double OtherBox::getHeight(void){
    return height;
}

void OtherBox::setHeight(double h){
    height = h;
}

int main(){
    OtherBox otherBox;

    otherBox.setHeight(3);
    std::cout << "protected:" << otherBox.getHeight() << std::endl;
}
 */

/* using namespace std;
 
class Line
{
   public:
      void setLength( double len );
      double getLength( void );
      Line(double len);  // 这是构造函数
 
   private:
      double length;
};
 
// 成员函数定义，包括构造函数
Line::Line(double len): length(len)
{
    //length = len;
    cout << "构造函数:" << len << endl;
}
 
void Line::setLength( double len )
{
    length = len;
}
 
double Line::getLength( void )
{
    return length;
}
// 程序的主函数
int main( )
{
   Line line(10.0);
 
   // 设置长度
   line.setLength(6.0); 
   cout << "长度为:" <<line.getLength() <<endl;
 
   return 0;
} */

/* using namespace std;
 
class Line
{
   public:
      void setLength( double len );
      double getLength( void );
      Line();   // 这是构造函数声明
      ~Line();  // 这是析构函数声明
 
   private:
      double length;
};
 
// 成员函数定义，包括构造函数
Line::Line(void)
{
    cout << "构造函数" << endl;
}
Line::~Line(void)
{
    cout << "析构函数" << endl;
}
 
void Line::setLength( double len )
{
    length = len;
}
 
double Line::getLength( void )
{
    return length;
}
// 程序的主函数
int main( )
{
   Line line;
 
   // 设置长度
   line.setLength(6.0); 
   cout << "长度为 : " << line.getLength() <<endl;
 
   return 0;
} */

/* using namespace std;

class Line {
private:
    int* ptr;  // 指针成员（需要特殊处理）

public:
    // 普通构造函数
    Line(int len) {
        cout << "调用构造函数" << endl;
        ptr = new int;  // 动态分配内存
        *ptr = len;
    }
    
    // 拷贝构造函数（深拷贝）
    Line(const Line& obj) {
        cout << "调用拷贝构造函数（深拷贝）" << endl;
        ptr = new int;        // 创建新内存
        *ptr = *obj.ptr;      // 复制值（而非指针地址）
    }
    
    // 析构函数
    ~Line() {
        cout << "释放内存: " << *ptr << endl;
        delete ptr;  // 释放分配的内存
    }
    
    int getLength() { return *ptr; }
};

// 按值传递对象（触发拷贝构造）
void display(Line obj) {
    cout << "长度: " << obj.getLength() << endl;
}

int main() {
    Line line(10);  // 调用普通构造函数
    display(line);  // 参数传递时调用拷贝构造函数
    
    return 0;
} */

/* class Box{
    public:
        static int count;
};

//初始化静态成员
int Box::count = 10;

int main(){
    std::cout << "静态成员值为:" << Box::count <<std::endl;
} */

/* class Box{
    public:
        static int count;
    static int getCount()
    {
        return count;
    }
};

//初始化静态成员
int Box::count = 10;

int main(){
    std::cout << "使用静态变量，静态成员值为:" << Box::count <<std::endl;
    std::cout << "使用静态函数，静态成员值为:" << Box::getCount() <<std::endl;
} */

#include <iostream>
using namespace std;
class Animal {
    public:
        virtual void makeSound() {  // 虚函数
            cout << "动物发出声音" << endl;
        }
    };

    class Dog : public Animal {
    public:
        void makeSound() override {  // 重写虚函数
            cout << "汪汪！" << endl;
        }
    };

    class Cat : public Animal {
    public:
        void makeSound() override {  // 重写虚函数
            cout << "喵喵！" << endl;
        }
};
int main() {
    Animal *animal_dog = new Dog();
    animal_dog->makeSound();  // 输出: Dog barks
    delete animal_dog;

    Animal *animal_cat = new Cat();
    animal_cat->makeSound();
    delete animal_cat;
}