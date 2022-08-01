#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    DB = QSqlDatabase::addDatabase ( "QSQLITE" );
    DB.setDatabaseName (path);
    DB.open();
}

MainWindow::~MainWindow()
{
    DB.close();
    delete ui;
    QSqlQuery pro_no;
    pro_no.exec("DELETE FROM customer");
}


void MainWindow::on_pushButton_clicked()
{
//    QString str = "Tahsin Abrar";
//    qDebug() << str;
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *quary = new QSqlQuery(DB);
    quary->exec("SELECT * FROM Product");
//    qDebug() << quary->exec();

    model->setQuery(*quary);
    ui->Customer_Page_table->setModel(model);

    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_3_clicked()
{
    exit(0);
}

void MainWindow::on_Back_admin_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Customer_Page_back_clicked()
{
    QSqlQuery pro_no;
    pro_no.exec("DELETE FROM customer");
    ui->Pro->clear();
    sum = price =0;
    name_product = "";
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_CREATE_PRODUCT_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Back_Create_P_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_DISPLAY_A_P_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_DISPLAY_ALL_PRODUCTS_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *quary = new QSqlQuery(DB);
    quary->exec("SELECT * FROM Product");
//    qDebug() << quary->exec();

    model->setQuery(*quary);
    ui->DISPLAY_A_P_table->setModel(model);

    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_MODIFY_P_page_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_MODIFY_PRODUCT_clicked()
{

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *quary = new QSqlQuery(DB);
    quary->exec("SELECT * FROM Product");
    model->setQuery(*quary);
    ui->MODIFY_P_page_table->setModel(model);


    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_DELETE_P_page_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_DELETE_PRODUCT_clicked()
{
//    DELETE_P_page_table
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *quary = new QSqlQuery(DB);
    quary->exec("SELECT * FROM Product");

    model->setQuery(*quary);
    ui->DELETE_P_page_table->setModel(model);

    ui->stackedWidget->setCurrentIndex(3);

    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_CREATE_PRODUCT_Update_clicked()
{
    str_Product_no = ui->C_P_product_no->text();
    str_Product_name = ui -> C_P_product_name -> text();
    str_Produce_Price = ui->C_P_product_price-> text();
    str_Product_Discount = ui->C_P_product_price_2-> text();

    QSqlQuery h;

    if (str_Product_no == "" && str_Product_name == "" && str_Produce_Price == "" && str_Product_Discount == "")
    {
         QMessageBox::warning(this , "ERROR", "This product wasn't created");
    }
    else
    {
        h.exec("INSERT INTO Product (no, name, price, discount) VALUES ('"+str_Product_no+"', '"+str_Product_name+"', '"+str_Produce_Price+"', '"+str_Product_Discount+"')");
        QMessageBox::information(this , "Success", "Product created successfully");
        ui->stackedWidget->setCurrentIndex(4);
    }
    ui->C_P_product_no->clear();
    ui->C_P_product_name->clear();
    ui->C_P_product_price->clear();
    ui->C_P_product_price_2->clear();

}

void MainWindow::on_DELETE_P_page_btn_clicked()
{
    str_delete_product_no = ui->DELETE_P_page_P_No->text();
//    qDebug() << str_delete_product_no ;

    QSqlQuery pro_no;
    pro_no.prepare("DELETE FROM Product WHERE no = '"+str_delete_product_no+"'");

    if (pro_no.exec())
    {
        QMessageBox::information(this, "Deleted", "Successfully Deleted");
    }

    else
    {
        QMessageBox::warning(this, "Error", "Product Not Found");
    }

//    qDebug() << pro_no.exec();

    ui->DELETE_P_page_P_No->clear();

    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_MODIFY_P_page_btn_clicked()
{
    QString str_input_product_no,  str_input_product_price, str_input_product_Discount;
    str_input_product_no = ui->MODIFY_P_page_input_no->text();
    str_input_product_price = ui->MODIFY_P_page_input_price->text();
    str_Product_Discount = ui->MODIFY_P_page_input_discount->text();


    QSqlQuery q, j;
    q.prepare("SELECT * FROM Product WHERE no = '"+str_input_product_no+"'");

    if (str_input_product_no == "" && str_input_product_price == "" && str_Product_Discount == "")
    {
        QMessageBox::warning(this, "UPDATE", "Invalid Product Number");
    }
    else
    {
        j.exec("UPDATE Product SET price = '"+str_input_product_price+"', discount = '"+str_Product_Discount+"' WHERE no = '"+str_input_product_no+"'");
        QMessageBox::information(this, "Update", "Product Updated");
    }

    ui->MODIFY_P_page_input_no->clear();
    ui->MODIFY_P_page_input_price->clear();
    ui->MODIFY_P_page_input_discount->clear();

    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_ADMINISTRATOR_btn_clicked()
{
    QString userName, password;
    userName = ui->ADMINISTRATOR_username->text();
    password = ui->ADMINISTRATOR_password->text();

    if ((userName == "Tahsin" && password == "C193084") || (userName == "Rafi" && password == "C193079") || (userName == "Ifti" && password == "C193074") || (userName == "Turag" && password == "C193078") || (userName == "Shuvo" && password == "C193057"))
    {
         ui->stackedWidget->setCurrentIndex(4);
    }
    else
    {
        QMessageBox::warning(this, "LOGIN", "Password and username error!\nplease try again !!");
    }
    ui->ADMINISTRATOR_username->clear();
    ui->ADMINISTRATOR_password->clear();

}

void MainWindow::on_ADMINISTRATOR_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Customer_Page_btn_clicked()
{
    QString pro, input_product_no, input_product_name, input_product_price, input_product_discount, price_after_discount;
    double Quantity;
    pro = ui->Customer_Page_product->text();
    Quantity = ui->Customer_Page_quantity->text().toInt();

    QSqlQuery k, customer;
    k.exec("SELECT * FROM Product WHERE no = '"+pro+"'");

    while(k.next())
    {
        input_product_no = k.value(0).toString();
        input_product_name = k.value(1).toString();
        input_product_price = k.value(2).toString();
        input_product_discount = k.value(3).toString();
    }

//     int sum =0;
    if (!Quantity) sum = sum;
    else
    {
        if (input_product_no != "" )
        {
            sum += 1;

            QString Quan = QString::number(Quantity);

            double dis;
            int pri;
            pri = (input_product_price.toDouble() - (input_product_price.toDouble() * (input_product_discount.toDouble() / 100.0))) * Quantity ;
            price_after_discount = QString::number(pri);
            price += pri;
            name_product += input_product_name +"="+QString::number(Quantity)+" , ";
            customer.exec("INSERT INTO customer (no, name, price, discount,quantity, after_discount) VALUES('"+input_product_no+"', '"+input_product_name+"', '"+input_product_price+"', '"+input_product_discount+"', '"+Quan+"', '"+price_after_discount+"')");

        }
        else
        {
            QMessageBox::warning(this, "SELECTION", "Could Not Find the Selected Product");
        }
    }

    QString s = QString::number(sum);
    ui->Pro->setText(s);

    ui->Customer_Page_product->clear();
    ui->Customer_Page_quantity->clear();
//    qDebug() << sum;

}

void MainWindow::on_Customer_Page_payment_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *quary = new QSqlQuery(DB);
    quary->exec("SELECT * FROM customer");

    model->setQuery(*quary);
    ui->PAMENY_page_table->setModel(model);

//    ui->PAMENY_page_total_input->setText(QString::number(totalPrice));
//    ui->PAMENY_page_discount_input->setText(QString::number(productDiscount));

    ui->PAMENY_page_total_input->setText(QString::number(price));
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_PAMENY_page_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_PAMENY_page_btn_clicked()
{

    customer_name = ui->PAMENY_page_name->text();
    customer_mobile = ui->PAMENY_page_mobile->text();
    if (customer_name != "" && customer_mobile != "")
    {
        QString str;
        QSqlQuery admin;

        admin.exec("INSERT INTO customer_info (name, item, mobile_no, Paid) VALUES ('"+customer_name+"','"+name_product+"' ,'"+customer_mobile+"', '"+QString::number(price)+"')");
        str = "Congratulation " + customer_name + " , " + customer_mobile +" \nPlease pay " + QString::number(price) + " Tk !!\nThank you !!";
        qDebug() << name_product;
        ui->Cash_memo_Congratulation->setText(str);
        QSqlQuery pro_no;
        pro_no.exec("DELETE FROM customer");
        price = sum = 0;
        ui->stackedWidget->setCurrentIndex(9);
    }
    else
    {
        QMessageBox::information(this, "INFORMATION", "Please give your Information");
    }
}

void MainWindow::on_Cash_memo_back_exit_btn_clicked()
{
    exit(0);
}

void MainWindow::on_CUSTOMER_INFO_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_CUSTOMER_INFO_btn_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *quary = new QSqlQuery(DB);
    quary->exec("SELECT * FROM customer_info");
//    qDebug() << quary->exec();
    model->setQuery(*quary);
    ui->CUSTOMER_INFO_table->setModel(model);
    ui->stackedWidget->setCurrentIndex(10);

}

void MainWindow::on_actionHelp_triggered()
{
   QMessageBox msgBox(this);
    msgBox.setWindowTitle("Help");
    msgBox.setText("Instruction\n\nHotash department store\n\nPlease follow given steps\n\n1. Select customer panel.\n\n2. "
                   "Select the product of your choice according to the product number.\n\n3. Select add to cart.\n\n4. "
                   "Select the payment option to see the total cost.\n\n5. Give your name and mobile number cash memo.\n\n6. "
                   "Select exit to leave this page.");
    msgBox.exec();

}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_actionInfo_triggered()
{
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Info");
    msgBox.setText("International Islamic University Chittagong\n\nSbapno department store\n\nTEAM NAME : 'HHJN'\n\n1. Tahsin Abrar\n2. Al Rafi\n3. Iftikhar Mahmud\n4. Asadujjaman Turag\n5. Shuvo Das");
    msgBox.exec();
}
