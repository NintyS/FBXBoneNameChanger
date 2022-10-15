#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMessageBox>
#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QDebug>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    QString fileName = "";

    std::map<QString, QString> bones = {
        {"Hips", "J_Bip_C_Hips"},
        {"LeftUpLeg", "J_Bip_L_UpperLeg"},
        {"LeftLeg", "J_Bip_L_LowerLeg"},
        {"LeftFoot", "J_Bip_L_Foot"},
        {"leftToeBase", "J_Bip_L_ToeBase"},
        {"RightUpLeg", "J_Bip_R_UpperLeg"},
        {"RightLeg", "J_Bip_R_LowerLeg"},
        {"RightFoot", "J_Bip_R_Foot"},
        {"RightToeBase", "J_Bip_R_ToeBase"},
        {"Spine", "J_Bip_C_Spine"},
        {"Neck", "J_Bip_C_Neck"},
        {"Head", "J_Bip_C_Head"},
        {"RightShoulder", "J_Bip_R_Shoulder"},
        {"RightArm", "J_Bip_R_UpperArm"},
        {"RightForeArm", "J_Bip_R_LowerArm"},
        {"RightHand", "J_Bip_R_Hand"},
        {"LeftShoulder", "J_Bip_L_Shoulder"},
        {"LeftArm", "J_Bip_L_UpperArm"},
        {"LeftForeArm", "J_Bip_L_LowerArm"},
        {"leftHand", "J_Bip_L_Hand"}
    };

};
#endif // MAINWINDOW_H
