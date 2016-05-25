/****************************************************************************
**  This is a part of FourierFit                                           **
**  Copyright (C) 2016  Simon Garnotel                                     **
**                                                                         **
**  This program is free software: you can redistribute it and/or modify   **
**  it under the terms of the GNU General Public License as published by   **
**  the Free Software Foundation, either version 3 of the License, or      **
**  (at your option) any later version.                                    **
**                                                                         **
**  This program is distributed in the hope that it will be useful,        **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of         **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          **
**  GNU General Public License for more details.                           **
**                                                                         **
**  You should have received a copy of the GNU General Public License      **
**  along with this program.  If not, see <http://www.gnu.org/licenses/>.  **
**                                                                         **
** **************************************************************************
**                                                                         **
** Author: Simon Garnotel                                                  **
** Contact: simon.garnotel@gmail.com                                       **
** Date: 06/2016                                                           **
** Version: 1.0                                                            **
****************************************************************************/

#include "dialogsettings.h"

void DialogSettings::InitVar(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    //Grid
    Grid = new QGridLayout(this);

    //Label
    LabelCurrentDirectory = new QLabel(Grid->widget());
    LabelCurrentOrder = new QLabel(Grid->widget());
    LabelLanguage = new QLabel(Grid->widget());
    LabelSeparator = new QLabel(Grid->widget());

    //LineEdit
    LineEditCurrentDirectory = new QLineEdit(Grid->widget());
    LineEditSeparator = new QLineEdit(Grid->widget());

    //PushButton
    PushButtonCurrentDirectory = new QPushButton(Grid->widget());
    PushButtonCancel = new QPushButton(Grid->widget());
    PushButtonValid = new QPushButton(Grid->widget());

    //SpinBox
    SpinBoxCurrentOrder = new QSpinBox(Grid->widget());

    //ComboBox
    ComboBoxLanguage = new QComboBox(Grid->widget());
}

void DialogSettings::InitWin(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    //Dialog
    this->setLayout(Grid);

    //Grid
    Grid->addWidget(LabelCurrentDirectory, 0, 0, 1, 1);
    Grid->addWidget(LineEditCurrentDirectory, 0, 1, 1, 2);
    Grid->addWidget(PushButtonCurrentDirectory, 0, 3, 1, 1);
    Grid->addWidget(LabelCurrentOrder, 1, 0, 1, 1);
    Grid->addWidget(SpinBoxCurrentOrder, 1, 1, 1, 3);
    Grid->addWidget(LabelLanguage, 2, 0, 1, 1);
    Grid->addWidget(ComboBoxLanguage, 2, 1, 1, 3);
    Grid->addWidget(LabelSeparator, 3, 0, 1, 1);
    Grid->addWidget(LineEditSeparator, 3, 1, 1, 3);
    //
    Grid->addWidget(PushButtonCancel, 10, 0, 1, 2);
    Grid->addWidget(PushButtonValid, 10, 2, 1, 2);

    //Label
    LabelCurrentDirectory->setText("Current directory");
    LabelCurrentOrder->setText("Default order");
    LabelLanguage->setText("Language");
    LabelSeparator->setText("File separator");

    //LineEdit
    bool Res;
    QString CurrentDirectory = GetCurrentDirectory(&Res);
    if (Res){
        LineEditCurrentDirectory->setText(CurrentDirectory);
    }
    else{
        LineEditCurrentDirectory->setText(DEFAULT_DIRECTORY);
    }
    QString CurrentSeparator = GetCurrentSeparator(&Res);
    if (Res){
        LineEditSeparator->setText(CurrentSeparator);
    }
    else{
        LineEditSeparator->setText(DEFAULT_SEPARATOR);
    }

    //PushButton
    PushButtonCurrentDirectory->setIcon(QIcon("img/dir.png"));
    PushButtonCurrentDirectory->setToolTip("Current directory");
    PushButtonCancel->setText("Cancel");
    PushButtonValid->setText("Valid");

    //SpinBox
    SpinBoxCurrentOrder->setRange(0, 100);
    int CurrentOrder = GetCurrentOrder(&Res);
    if (Res){
        SpinBoxCurrentOrder->setValue(CurrentOrder);
    }
    else{
        SpinBoxCurrentOrder->setValue(DEFAULT_ORDER);
    }

    //ComboBox
    ComboBoxLanguage->addItem("English");
}

void DialogSettings::InitSig(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    //PushButton
    connect(PushButtonCurrentDirectory, SIGNAL(clicked(bool)), this, SLOT(DoCurrentDirectory()));
    connect(PushButtonCancel, SIGNAL(clicked(bool)), this, SLOT(DoCancel()));
    connect(PushButtonValid, SIGNAL(clicked(bool)), this, SLOT(DoValid()));
}

void DialogSettings::InitCss(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    //Dialog
    this->setWindowTitle("Settings");
}

DialogSettings::DialogSettings(QWidget *parent) : QDialog(parent){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    InitVar();
    InitWin();
    InitSig();
    InitCss();
}

void DialogSettings::DoCurrentDirectory(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    QString Directory = QFileDialog::getExistingDirectory(this, "Current directory", LineEditCurrentDirectory->text());
    LineEditCurrentDirectory->setText(Directory);
}

void DialogSettings::DoCancel(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    reject();
}

void DialogSettings::DoValid(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    bool Res = SetCurrentDirectory(LineEditCurrentDirectory->text());
    if (!Res) qWarning() << "Warning: " << "Unable to set current directory";
    Res = SetCurrentOrder(SpinBoxCurrentOrder->value());
    if (!Res) qWarning() << "Warning: " << "Unable to set current order";
    Res = SetCurrentSeparator(LineEditSeparator->text());
    if (!Res) qWarning() << "Warning: " << "Unable to set current separator";

    accept();
}


