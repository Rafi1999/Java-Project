#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>
#include <QSqlQueryModel>
#include <QTableView>
#include <QDialog>

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

    void on_pushButton_3_clicked();

    void on_label_3_linkActivated(const QString &link);

    void on_pushButton_9_clicked();

    void on_Back_admin_clicked();

    void on_Customer_Page_back_clicked();

    void on_CREATE_PRODUCT_clicked();

    void on_Back_admin_2_clicked();

    void on_Back_Create_P_clicked();

    void on_DISPLAY_A_P_back_clicked();

    void on_DISPLAY_ALL_PRODUCTS_clicked();

    void on_MODIFY_P_page_back_clicked();

    void on_MODIFY_PRODUCT_clicked();

    void on_DELETE_P_page_back_clicked();

    void on_DELETE_PRODUCT_clicked();

    void on_CREATE_PRODUCT_Update_clicked();

    void on_DELETE_P_page_btn_clicked();

    void on_MODIFY_P_page_btn_clicked();

    void on_ADMINISTRATOR_btn_clicked();

    void on_ADMINISTRATOR_back_clicked();

    void on_Customer_Page_btn_clicked();

    void on_Customer_Page_payment_clicked();

    void on_PAMENY_page_back_clicked();

    void on_PAMENY_page_btn_clicked();

    void on_Cash_memo_back_exit_btn_clicked();

    void on_CUSTOMER_INFO_2_clicked();

    void on_CUSTOMER_INFO_btn_clicked();

    void on_actionHelp_triggered();

    void on_actionExit_triggered();

    void on_actionInfo_triggered();

private:
    Ui::MainWindow *ui;
    QString str_Product_no, str_Product_name, str_Produce_Price, str_Product_Discount, str_delete_product_no, path="D:/DB/Hello.db";
    QString customer_name, customer_mobile, name_product;
    QSqlDatabase DB, list;
    QSqlQueryModel model;
    int price = 0, sum = 0;

};
#endif // MAINWINDOW_H
