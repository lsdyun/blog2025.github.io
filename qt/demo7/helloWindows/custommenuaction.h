// custommenuaction.h
#ifndef CUSTOMMENUACTION_H
#define CUSTOMMENUACTION_H

#include <QWidgetAction>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>

class CustomMenuAction : public QWidgetAction
{
    Q_OBJECT
public:
    explicit CustomMenuAction(QObject *parent = nullptr);

protected:
    QWidget *createWidget(QWidget *parent) override;

signals:
    void textEntered(const QString &text);

private slots:
    void handleReturnPressed();
};

#endif // CUSTOMMENUACTION_H
