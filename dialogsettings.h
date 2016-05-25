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

#ifndef DIALOGSETTINGS_H
#define DIALOGSETTINGS_H

#include "header.h"

class DialogSettings : public QDialog
{
    Q_OBJECT
public:
    explicit DialogSettings(QWidget *parent = 0);

private:
    void InitVar();
    void InitWin();
    void InitSig();
    void InitCss();

    //Grid
    QGridLayout *Grid;

    //Label
    QLabel *LabelCurrentDirectory;
    QLabel *LabelCurrentOrder;
    QLabel *LabelLanguage;
    QLabel *LabelSeparator;

    //LineEdit
    QLineEdit *LineEditCurrentDirectory;
    QLineEdit *LineEditSeparator;

    //PushButton
    QPushButton *PushButtonCurrentDirectory;
    QPushButton *PushButtonCancel;
    QPushButton *PushButtonValid;

    //SpinBox
    QSpinBox *SpinBoxCurrentOrder;

    //ComboBox
    QComboBox *ComboBoxLanguage;

signals:

public slots:

private slots:
    void DoCurrentDirectory();
    void DoCancel();
    void DoValid();
};

#endif // DIALOGSETTINGS_H


