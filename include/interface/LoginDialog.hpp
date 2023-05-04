#ifndef LOGINDIALOG_HPP
#define LOGINDIALOG_HPP

/* Importations des headers nécessaires */
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QString>

/* Classe LoginDialog */
class LoginDialog : public QDialog
{
    Q_OBJECT

private:
    QLineEdit *hostEdit;
    QLineEdit *databaseEdit;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;

public:
    LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

public:
    void getResult(std::string &host, std::string &database, std::string &username, std::string &password);

};

#endif // LOGINDIALOG_HPP