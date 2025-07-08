#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>  // 包含文本编辑控件

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;  // 拖动进入事件
    void dropEvent(QDropEvent *event) override;            // 放下事件

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
