#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QActionGroup"
#include "QToolButton"
#include "QSpinBox"
#include "QTextEdit"
#include "QMdiSubWindow"
#include "QLabel"
#include "custommenuaction.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //编辑菜单
    QMenu *editMenu = ui->menuBar->addMenu(tr("编辑(&E)"));
    QAction *action_Open = editMenu->addAction(  QIcon(":/images/open.png"), tr("打开文件(&O)"));
    action_Open->setShortcut(QKeySequence("Ctrl+O"));
    ui->mainToolBar->addAction(action_Open);

    //勾选菜单
    QActionGroup *group = new QActionGroup(this);
    QAction *action_L = group->addAction(tr("左对齐(&L)"));
    action_L->setCheckable(true);
    QAction *action_R = group->addAction(tr("右对齐(&R)"));
    action_R->setCheckable(true);
    QAction *action_C = group->addAction(tr("居中(&C)"));
    action_C->setCheckable(true);
    action_L->setChecked(true);

    editMenu->addSeparator();
    editMenu->addAction(action_L);
    editMenu->addAction(action_R);
    editMenu->addAction(action_C);

    //移动菜单
    QToolButton *toolBtn = new QToolButton(this);
    toolBtn->setText(tr("颜色"));
    QMenu *colorMenu = new QMenu(this);
    colorMenu->addAction(tr("红色"));
    colorMenu->addAction(tr("绿色"));
    toolBtn->setMenu(colorMenu);
    toolBtn->setPopupMode(QToolButton::MenuButtonPopup);
    ui->mainToolBar->addWidget(toolBtn);
    QSpinBox *spinBox = new QSpinBox(this);
    ui->mainToolBar->addWidget(spinBox);

    // 新增QTextEdit作为中央部件
    /*
    QTextEdit *textEdit = new QTextEdit(this);
    setCentralWidget(textEdit); // 设置为中央部件
    */

    //状态栏

    ui->statusbar->showMessage(tr("欢迎使用多文档编辑器"), 2000);
    QLabel *permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permanent->setText("www.qter.org");
    ui->statusbar->addPermanentWidget(permanent);

    // 创建自定义菜单项并添加到编辑菜单
    CustomMenuAction *customAction = new CustomMenuAction(this);
    editMenu->addAction(customAction);

    // 连接信号到槽函数
    connect(customAction, &CustomMenuAction::textEntered,
            this, &MainWindow::insertTextToActiveEditor);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_New_triggered()
{
    QTextEdit *edit = new QTextEdit(this);
    QMdiSubWindow *child = ui->mdiArea->addSubWindow(edit);
    child->setWindowTitle(tr("多文档编辑器子窗口"));
    child->show();
}

// 在MainWindow类中添加新的槽函数
void MainWindow::insertTextToActiveEditor(const QString &text)
{
    // 获取当前活动的MDI子窗口
    QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow();
    if (activeSubWindow) {
        // 获取子窗口中的文本编辑器
        QTextEdit *textEdit = qobject_cast<QTextEdit*>(activeSubWindow->widget());
        if (textEdit) {
            // 插入文本到光标位置
            textEdit->insertPlainText(text);
        }
    }
}

