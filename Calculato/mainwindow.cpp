#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Foonctions.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->but_0, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_1, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_2, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_3, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_4, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_5, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_6, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_7, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_8, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_9, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_dot, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_plus, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_min, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_umn, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_del, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_sqrt, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_step, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_ravn, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_sin, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_cos, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_tg, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_ctg, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_bracket_open, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_bracket_closed, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->but_clear, SIGNAL(clicked()), this, SLOT(clearLabelAndLine()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitNumbers()
{
    QPushButton *button = (QPushButton *)sender();
    QString str = "", lblString = "";

    str += (ui->line_entry->text() + button->text());
    ui->line_entry->setText(str);

    if(button->text() == '+' || button->text() == '-' || button->text() == '*' || button->text() == '/' || button->text() == '=') {
        ui->line_entry->clear();
        lblString += (ui->lbl_temp->text()) + str;
        ui->lbl_temp->setText(lblString);

        if(button->text() == '='){
            str = ui->lbl_temp->text();
            QString buffer = "";
            std::string res;
            int counter = 0;

            while (str[counter] != '=') {
                buffer += str[counter];
                counter++;
            }

            double result = exitString(buffer.toStdString());
            if(result == 0.111) QMessageBox::critical(this, "Ошибка!", "Вы ввели неправильное значение!");
            else {
                res = valueProcessing(result);
            str = QString::fromStdString(res);
            }

            ui->line_entry->setText(str);
        }
    }
}

void MainWindow::clearLabelAndLine()
{
    ui->line_entry->clear();
    ui->lbl_temp->clear();
}



