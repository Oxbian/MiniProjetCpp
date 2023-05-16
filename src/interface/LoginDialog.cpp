#include "LoginDialog.hpp"

/**
 * @brief Constructeur de LoginDialog
 * @param parent Pointeur vers le widget parent
 */
LoginDialog::LoginDialog(QWidget *parent) : QDialog(parent)
{
    /* Info principales de la fenêtre */
    setWindowTitle("Connexion à la base de données");
    setFixedSize(LOGIN_WIDTH, LOGIN_HEIGHT);

    /* Création des QLineEdit */
    hostEdit = new QLineEdit("localhost");
    databaseEdit = new QLineEdit("miniprojet");
    usernameEdit = new QLineEdit("miniprojet");
    passwordEdit = new QLineEdit("miniprojet");
    passwordEdit->setEchoMode(QLineEdit::Password);

    /* Création des boutons */
    QPushButton *okBtn = new QPushButton("OK");
    QPushButton *cancelBtn = new QPushButton("Annuler");

    /* Création du layout */
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(new QLabel("Hôte:"), 0, 0);
    layout->addWidget(hostEdit, 0, 1);
    layout->addWidget(new QLabel("Nom base de données:"), 1, 0);
    layout->addWidget(databaseEdit, 1, 1);
    layout->addWidget(new QLabel("Nom d'utilisateur:"), 2, 0);
    layout->addWidget(usernameEdit, 2, 1);
    layout->addWidget(new QLabel("Mot de passe:"), 3, 0);
    layout->addWidget(passwordEdit, 3, 1);
    layout->addWidget(okBtn, 4, 0);
    layout->addWidget(cancelBtn, 4, 1);

    setLayout(layout);

    /* Connection des signaux */
    connect(okBtn, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(reject()));
}


/**
 * @brief Destructeur de LoginDialog
 */
LoginDialog::~LoginDialog()
{
    delete hostEdit;
    delete databaseEdit;
    delete usernameEdit;
    delete passwordEdit;
}

/**
 * @brief Fonction pour récupérer les informations de connexion
 * @param host String qui contiendra l'hôte
 * @param base String qui contiendra le nom de la base de données
 * @param user String qui contiendra le nom d'utilisateur
 * @param pwd String qui contiendra le mot de passe
 */
void LoginDialog::getResult(std::string &host, std::string &base, std::string &user, std::string &pwd)
{
    host = hostEdit->text().toStdString();
    base = databaseEdit->text().toStdString();
    user = usernameEdit->text().toStdString();
    pwd = passwordEdit->text().toStdString();
}