#include "temperatura.h"
#include "ui_temperatura.h"
#include <QDebug>

Temperatura::Temperatura(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Temperatura)
{
    ui->setupUi(this);
    //CONEXION DE LOS SIGNALS Y SLOTS
    connect(ui->dialCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2Fahr(int)));
    connect(ui->dialFahr, SIGNAL(valueChanged(int)),
            this, SLOT(fahr2Cent(int)));
    connect(ui->dialKelv, SIGNAL(valueChanged(int)),
            this, SLOT(kelv2Cent(int)));

    //ESTABLESCO EL CAMBIO DEL CURSOR
    connect(ui->dialCent, SIGNAL(sliderPressed()), this, SLOT(cambiarCursor()));
    connect(ui->dialCent, SIGNAL(sliderReleased()), this, SLOT(cambiarCursor()));

    connect(ui->dialFahr, SIGNAL(sliderPressed()), this, SLOT(cambiarCursor()));
    connect(ui->dialFahr, SIGNAL(sliderReleased()), this, SLOT(cambiarCursor()));

    connect(ui->dialKelv, SIGNAL(sliderPressed()), this, SLOT(cambiarCursor()));
    connect(ui->dialKelv, SIGNAL(sliderReleased()), this, SLOT(cambiarCursor()));

    //ESTABLESCO LOS VALORERS INICIALES DE LOS "dial"

    ui->dialFahr->setValue(32);         //valor inicial de Fahrenheit en el dial
    ui->dialCent->setValue(0);          //valor inicial de Centigrados en el dial
    ui->dialKelv->setValue(273);        //valor inicial de Kelvin en el dial

    //ESTABLESCO LOS VALORERS INICIALES DE LOS "label"

    ui->lblFahr->setText("32 °F");      //valor inicial de Fahrenheit en el label
    ui->lblCent->setText("0 °C");       //valor inicial de Centigrados en el label
    ui->lblKelv->setText("273 K");      //valor inicial de Kelvin en el label
}

Temperatura::~Temperatura()
{
    delete ui;
}

void Temperatura::cent2Fahr(int valor)
{
    if(ui->dialCent->hasFocus()){
        float f = (valor * 9.0/5) + 32;
        ui->dialFahr->setValue(f);
        float k = valor + 273.15;
        ui->dialKelv->setValue(k);

        //Validar para imprimir en el label de float a QString
        QString Cent = QString::number(valor);
        QString Fahr = QString::number(f);
        QString Kelv = QString::number(k);
        //IMPRIMIR
        ui->lblCent->setText(Cent + " °C");
        ui->lblFahr->setText(Fahr + " °F");
        ui->lblKelv->setText(Kelv + "  K");
    }
}

void Temperatura::fahr2Cent(int valor)
{
    if(ui->dialFahr->hasFocus()){
        float c = (valor - 32) * 5.0/9;
        ui->dialCent->setValue(c);
        float k = (valor - 32) * 5.0/9 + 273.15;
        ui->dialKelv->setValue(k);

        //Validar para imprimir en el label de float a QString
        QString Fahr = QString::number(valor);
        QString Cent = QString::number(c);
        QString Kelv = QString::number(k);
        //IMPRIMIR
        ui->lblCent->setText(Cent + " °C");
        ui->lblFahr->setText(Fahr + " °F");
        ui->lblKelv->setText(Kelv + "  K");
    }
}

void Temperatura::kelv2Cent(int valor)
{
    if(ui->dialKelv->hasFocus()){
        float c = valor - 273.15;
        ui->dialCent->setValue(c);
        float f = (valor - 273.15) * 9.0/5 + 32;
        ui->dialFahr->setValue(f);

        //Validar para imprimir en el label de float a QString
        QString Kelv = QString::number(valor);
        QString Fahr = QString::number(f);
        QString Cent = QString::number(c);
        //IMPRIMIR
        ui->lblCent->setText(Cent + " °C");
        ui->lblFahr->setText(Fahr + " °F");
        ui->lblKelv->setText(Kelv + "  K");
    }
}

void Temperatura::cambiarCursor()
{
    if(ui->dialCent->hasFocus()){
        if(ui->dialCent->cursor()== Qt::OpenHandCursor){
            ui->dialCent->setCursor(Qt::ClosedHandCursor);
        }else
            ui->dialCent->setCursor(Qt::OpenHandCursor);

    }else if (ui->dialFahr->hasFocus()){
        if(ui->dialFahr->cursor()== Qt::OpenHandCursor){
            ui->dialFahr->setCursor(Qt::ClosedHandCursor);
        }else
            ui->dialFahr->setCursor(Qt::OpenHandCursor);

    }else if (ui->dialKelv->hasFocus()){
        if(ui->dialKelv->cursor()== Qt::OpenHandCursor){
            ui->dialKelv->setCursor(Qt::ClosedHandCursor);
        }else
            ui->dialKelv->setCursor(Qt::OpenHandCursor);
    }
}
