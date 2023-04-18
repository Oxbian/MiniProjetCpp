#ifndef FENETREPRINCIPALE_HPP
#define FENETREPRINCIPALE_HPP

#include <QMainWindow>
#include <QApplication>
#include <QObject>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QStatusBar>

#include "SceneCarte.hpp"
#include "MiniVue.hpp"
#include "GrandeVue.hpp"

#define WIDTH 800
#define HEIGHT 600

class FenetrePrincipale: public QMainWindow
{
    Q_OBJECT
public:
    FenetrePrincipale(QWidget *parent = nullptr);
    virtual ~FenetrePrincipale() {};
public slots:
    void affiche_pos_scene(QPointF pos);
    void calculate_dist();
private:
    QGroupBox *createLeftSide();
private:
    QWidget *central_widget;
    SceneCarte *scene;
    GrandeVue *great_view;
    MiniVue *small_view;
    QStatusBar *barre_status;
    QLineEdit *depart_edit;
    QLineEdit *arrivee_edit;
    QPushButton *calculate_btn;
};

#endif // FENETREPRINCIPALE_HPP