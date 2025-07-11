#include <QApplication>
#include <QTableView>
#include <QStandardItemModel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 创建模型并填充数据
    QStandardItemModel *model = new QStandardItemModel(10, 3);
    for(int row = 0; row < 10; ++row) {
        for(int col = 0; col < 3; ++col) {
            QStandardItem *item = new QStandardItem(QString("行%1 列%2").arg(row).arg(col));
            model->setItem(row, col, item);
        }
    }

    // 创建视图并设置模型
    QTableView *tableView = new QTableView;
    tableView->setModel(model);

    // 设置选择
    QItemSelectionModel *selectionModel = tableView->selectionModel();
    QModelIndex topLeft = model->index(1, 1);
    QModelIndex bottomRight = model->index(5, 2);
    QItemSelection selection(topLeft, bottomRight);
    selectionModel->select(selection, QItemSelectionModel::Select);

    tableView->show();
    return a.exec();
}
