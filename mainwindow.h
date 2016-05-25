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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "header.h"
#include "dialogsettings.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

private:
    //Methods
    void InitVar();
    void InitWin();
    void InitSig();
    void InitCss();
    void DoFillFileList(const QStringList *Lines);
    void DoPlotSignal();
    void DoPlotFourierFit();
    void DoFillInformations(const int Order);

    //Widget
    QWidget *WidgetCentral;

    //Menu
    QMenu *MenuFile;
    QMenu *MenuSettings;
    QMenu *MenuActions;
    QMenu *MenuHelp;

    //Action
    QAction *ActionMenuFileInputFile;
    QAction *ActionMenuFileQuit;
    QAction *ActionMenuSettingsSettings;
    QAction *ActionMenuActionsReadFile;
    QAction *ActionMenuActionsFourierFit;
    QAction *ActionMenuActionsExportCurve;
    QAction *ActionMenuActionsExportCoefficients;
    QAction *ActionMenuActionsExportFreeFem;
    QAction *ActionMenuActionsExportFeel;
    QAction *ActionMenuHelpAboutQt;
    QAction *ActionMenuHelpAboutFourierFit;

    //Grid
    QGridLayout *GridCentral;
    QGridLayout *GridFileIn;
    QGridLayout *GridFileDisplay;
    QGridLayout *GridPlot;
    QGridLayout *GridInformations;

    //Frame
    QFrame *FrameFileIn;
    QFrame *FrameFileDisplay;
    QFrame *FramePlot;
    QFrame *FrameInformations;

    //Label
    QLabel *LabelFileIn;

    //LineEdit
    QLineEdit *LineEditFileIn;

    //PushButton
    QPushButton *PushButtonFileIn;
    QPushButton *PushButtonReadFileIn;
    QPushButton *PushButtonFourierFit;
    QPushButton *PushButtonExportCurve;
    QPushButton *PushButtonExportCoefficients;
    QPushButton *PushButtonExportFreeFem;
    QPushButton *PushButtonExportFeel;

    //ListWidget
    QListWidget *ListWidgetFileDisplay;

    //ComboBox
    QSpinBox *SpinBoxFourierFit;

    //Vector
    QVector<double> *VectorSignalX;
    QVector<double> *VectorSignalY;
    QVector<double> *VectorFourierFitX;
    QVector<double> *VectorFourierFitY;
    QVector<double> *VectorCoefficients;

    //CustomPlot
    QCustomPlot *CustomPlot;

    //TextEdit
    QTextEdit *TextEditInformations;

    //String
    QString StringCurrentDirectory;
    QString StringCurrentSeparator;

    //Int
    int IntCurrentOrder;

signals:

public slots:

private slots:
    void DoFileDirectory();
    void DoReadFile();
    void DoSettings();
    void DoConvertData();
    void DoFourierFit();
    void DoExportCurve();
    void DoExportCoefficients();
    void DoExportFreeFem();
    void DoExportFeel();
    void DoAboutQt();
    void DoAboutFourierFit();
    void DoQuit();

    void resizeEvent(QResizeEvent*);
};

#endif // MAINWINDOW_H


