#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //qDebug() << QDir::currentPath();

    if(fileName == "") {
        QMessageBox messBox;
        messBox.critical(0, "Error", "Nie znaleziono pliku");
        messBox.setFixedSize(500, 200);
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    int lines = 0;

    QString content = "";

    QString nameOfCharacter = "";

    while (!file.atEnd()) {
        lines++;
        QByteArray line = file.readLine();

        if(lines == 237) {
            int startOfName = line.lastIndexOf("NodeAttribute") + 14;
            int endOfName = line.indexOf(':', startOfName+1);

            for(int i = 0; i < line.length(); i++) {
                if((i > startOfName)&&(i < endOfName)) {
                    nameOfCharacter += line[i];
                }
            }
        }

        content += line;
    }

    for (auto name : bones) {
        qDebug() << nameOfCharacter + ":" + name.first, name.second + "\n";
        content.replace(nameOfCharacter + ":" + name.first, name.second);
    }

    //qDebug() << content;

    QString name = "";

    for(int i = 0; i < fileName.split("/").length()-1; i++) {
        name += fileName.split("/")[i] += "/";
    }

    for(int i = 0; i < fileName.split("/").last().length(); i++) {
        if(i < fileName.split("/").last().length() - 4) {
            name += fileName.split("/").last()[i];
        }
    }

    name += "_modified.fbx";

    QFile fileOut(name);
    if (!fileOut.open(QIODevice::WriteOnly | QIODevice::Text))
           return;

    QTextStream out(&fileOut);

    out << content;

    if(lines < 237) {
        QMessageBox messBox;
        messBox.critical(0, "Error", "Nie znaleziono animacji w pliku");
        messBox.setFixedSize(500, 200);
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open FBX"), "output.fbx", tr("FBX Files (*.fbx)"));
    ui->lineEdit->setText(fileName);
}

