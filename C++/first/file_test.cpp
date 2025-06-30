#include<iostream>
#include<fstream>
using namespace std;

int main(){
    string data;
    string filename = "test.txt";   //文件名

    //写文件
    ofstream outfile;           //创建输出文件流对象
    outfile.open(filename, ios::app);     //打开文件(不存在则创建)
    /*简写
    ofstream outfile(filename, ios::app); // 构造函数直接打开
    使用ios::app，写入的文件追加到原文后面
    */

    cout << "请输入要写的内容:" << endl;
    getline(cin,data);      //getline()保留空格

    outfile << data << endl;    //向文件写入数据
    outfile.close();        //关闭文件流


    //读文件
    ifstream infile;        //创建输入文件流对象
    infile.open(filename);  //打开文件(不存在则创建)

    cout<< "文件内容为:" << endl;
    //infile >> data;
    while(getline(infile,data)){
        cout << data << endl;
    }

    cout << data << endl;    //在屏幕上输出内容
    infile.close();     //关闭文件流
}   