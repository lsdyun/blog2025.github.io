#include <QApplication>
#include <QSqlQuery>
#include <QDebug>
#include <QInputDialog>
#include "connection.h"
#include <QSqlError>

// 显示所有学生信息
void showAllStudents() {
    QSqlQuery query;
    query.exec("SELECT * FROM student");

    qDebug() << "\n学生列表:";
    qDebug() << "ID\t姓名";
    qDebug() << "----------------";

    while(query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        qDebug() << id << "\t" << name;
    }
}

// 添加学生
void addStudent() {
    bool ok;
    QString name = QInputDialog::getText(nullptr, "添加学生", "请输入学生姓名:",
                                         QLineEdit::Normal, "", &ok);
    if (!ok || name.isEmpty()) return;

    QSqlQuery query;
    query.prepare("INSERT INTO student (name) VALUES (?)");
    query.addBindValue(name);

    if (query.exec()) {
        qDebug() << "添加成功!";
    } else {
        qDebug() << "添加失败:" << query.lastError().text();
    }
}

// 删除学生
void deleteStudent() {
    bool ok;
    int id = QInputDialog::getInt(nullptr, "删除学生", "请输入学生ID:",
                                  0, 0, 100, 1, &ok);
    if (!ok) return;

    QSqlQuery query;
    query.prepare("DELETE FROM student WHERE id = ?");
    query.addBindValue(id);

    if (query.exec()) {
        if (query.numRowsAffected() > 0) {
            qDebug() << "删除成功!";
        } else {
            qDebug() << "未找到该ID的学生";
        }
    } else {
        qDebug() << "删除失败:" << query.lastError().text();
    }
}

// 修改学生信息
void updateStudent() {
    bool ok;
    int id = QInputDialog::getInt(nullptr, "修改学生", "请输入要修改的学生ID:",
                                  0, 0, 100, 1, &ok);
    if (!ok) return;

    QString newName = QInputDialog::getText(nullptr, "修改学生", "请输入新的姓名:",
                                            QLineEdit::Normal, "", &ok);
    if (!ok || newName.isEmpty()) return;

    QSqlQuery query;
    query.prepare("UPDATE student SET name = ? WHERE id = ?");
    query.addBindValue(newName);
    query.addBindValue(id);

    if (query.exec()) {
        if (query.numRowsAffected() > 0) {
            qDebug() << "修改成功!";
        } else {
            qDebug() << "未找到该ID的学生";
        }
    } else {
        qDebug() << "修改失败:" << query.lastError().text();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 创建数据库连接
    if (!createConnection()) {
        qDebug() << "数据库连接失败，程序退出";
        return 1;
    }

    // 主菜单循环
    while (true) {
        qDebug() << "\n===== 学生信息管理系统 =====";
        qDebug() << "1. 显示所有学生";
        qDebug() << "2. 添加学生";
        qDebug() << "3. 删除学生";
        qDebug() << "4. 修改学生信息";
        qDebug() << "0. 退出";

        bool ok;
        int choice = QInputDialog::getInt(nullptr, "主菜单", "请选择操作:",
                                          0, 0, 4, 1, &ok);
        if (!ok) choice = 0;

        switch (choice) {
        case 1:
            showAllStudents();
            break;
        case 2:
            addStudent();
            break;
        case 3:
            deleteStudent();
            break;
        case 4:
            updateStudent();
            break;
        case 0:
            qDebug() << "程序已退出";
            return 0;
        default:
            qDebug() << "无效选择，请重新输入";
        }
    }

    return a.exec();
}
