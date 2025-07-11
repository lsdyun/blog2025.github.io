#include "widget.h"

#include <QApplication>
#include <QStandardItem>
#include <QTreeView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // 创建标准项模型
    QStandardItemModel model;
    // 获取模型的根项（Root Item），根项是不可见的
    QStandardItem *parentItem = model.invisibleRootItem();
    // 创建标准项item0，并设置显示文本，图标和工具提示
    QStandardItem *item0 = new QStandardItem;
    item0->setText("A");
    QPixmap pixmap0(50, 50);
    pixmap0.fill("red");
    item0->setIcon(QIcon(pixmap0));
    item0->setToolTip("indexA");
    // 将创建的标准项作为根项的子项
    parentItem->appendRow(item0);

    // 创建第二个项(B)作为A的子项
    parentItem = item0;
    // 创建新的标准项，它将作为item0的子项
    QStandardItem *item1 = new QStandardItem;
    item1->setText("B");
    QPixmap pixmap1(50,50);
    pixmap1.fill("blue");
    item1->setIcon(QIcon(pixmap1));
    item1->setToolTip("indexB");
    parentItem->appendRow(item1);
    // 在树视图中显示模型
    QTreeView view;
    view.setModel(&model);
    view.show();

    return a.exec();
}
