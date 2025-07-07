// custommenuaction.cpp
#include "custommenuaction.h"

CustomMenuAction::CustomMenuAction(QObject *parent)
    : QWidgetAction(parent)
{
}

QWidget *CustomMenuAction::createWidget(QWidget *parent)
{
    QWidget *container = new QWidget(parent);
    QHBoxLayout *layout = new QHBoxLayout(container);
    layout->setContentsMargins(5, 2, 5, 2); // 调整边距使其更紧凑

    QLabel *label = new QLabel("输入文本:", container);
    QLineEdit *lineEdit = new QLineEdit(container);

    layout->addWidget(label);
    layout->addWidget(lineEdit);
    container->setLayout(layout);

    connect(lineEdit, &QLineEdit::returnPressed, this, &CustomMenuAction::handleReturnPressed);
    connect(lineEdit, &QLineEdit::returnPressed, lineEdit, &QLineEdit::clear);

    return container;
}

void CustomMenuAction::handleReturnPressed()
{
    QLineEdit *lineEdit = qobject_cast<QLineEdit*>(sender());
    if (lineEdit) {
        emit textEntered(lineEdit->text());
    }
}
