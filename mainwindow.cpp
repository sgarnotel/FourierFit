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

#include "mainwindow.h"

//Methods
void MainWindow::InitVar(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    //Widget
    WidgetCentral = new QWidget(this);

    //Menu
    MenuFile = menuBar()->addMenu("File");
    MenuSettings = menuBar()->addMenu("Settings");
    MenuActions = menuBar()->addMenu("Actions");
    MenuHelp = menuBar()->addMenu("Help");

    //Action
    ActionMenuFileInputFile = new QAction(this);
    ActionMenuFileQuit = new QAction(this);
    ActionMenuSettingsSettings = new QAction(this);
    ActionMenuActionsReadFile = new QAction(this);
    ActionMenuActionsFourierFit = new QAction(this);
    ActionMenuActionsExportCurve = new QAction(this);
    ActionMenuActionsExportCoefficients = new QAction(this);
    ActionMenuActionsExportFreeFem = new QAction(this);
    ActionMenuActionsExportFeel = new QAction(this);
    ActionMenuHelpAboutQt = new QAction(this);
    ActionMenuHelpAboutFourierFit = new QAction(this);

    //Grid
    GridCentral = new QGridLayout(WidgetCentral);

    //Frame
    FrameFileIn = new QFrame(GridCentral->widget());
    FrameFileDisplay = new QFrame(GridCentral->widget());
    FramePlot = new QFrame(GridCentral->widget());
    FrameInformations = new QFrame(GridCentral->widget());

    //Grid2
    GridFileIn = new QGridLayout(FrameFileIn);
    GridFileDisplay = new QGridLayout(FrameFileDisplay);
    GridPlot = new QGridLayout(FramePlot);
    GridInformations = new QGridLayout(FrameInformations);

    //Label
    LabelFileIn = new QLabel(GridFileIn->widget());

    //LineEdit
    LineEditFileIn = new QLineEdit(GridFileIn->widget());

    //PushButton
    PushButtonFileIn = new QPushButton(GridFileIn->widget());
    PushButtonReadFileIn = new QPushButton(GridFileIn->widget());
    PushButtonFourierFit = new QPushButton(GridPlot->widget());
    PushButtonExportCurve = new QPushButton(GridInformations->widget());
    PushButtonExportCoefficients = new QPushButton(GridInformations->widget());
    PushButtonExportFreeFem = new QPushButton(GridInformations->widget());
    PushButtonExportFeel = new QPushButton(GridInformations->widget());

    //ListWidget
    ListWidgetFileDisplay = new QListWidget(GridFileDisplay->widget());

    //SpinBox
    SpinBoxFourierFit = new QSpinBox(GridPlot->widget());

    //Vector
    VectorSignalX = new QVector<double>;
    VectorSignalY = new QVector<double>;
    VectorFourierFitX = new QVector<double>;
    VectorFourierFitY = new QVector<double>;
    VectorCoefficients = new QVector<double>;

    //CustomPlot
    CustomPlot = new QCustomPlot(GridPlot->widget());

    //TextEdit
    TextEditInformations = new QTextEdit(GridInformations->widget());

    //String
    StringCurrentDirectory = DEFAULT_DIRECTORY;
    StringCurrentSeparator = DEFAULT_SEPARATOR;

    //Int
    IntCurrentOrder = DEFAULT_ORDER;
}

void MainWindow::InitWin(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    //MainWindow
    setCentralWidget(WidgetCentral);

    //Menu
    MenuFile->addAction(ActionMenuFileInputFile);
    MenuFile->addAction(ActionMenuFileQuit);
    MenuSettings->addAction(ActionMenuSettingsSettings);
    MenuActions->addAction(ActionMenuActionsReadFile);
    MenuActions->addAction(ActionMenuActionsFourierFit);
    MenuActions->addAction(ActionMenuActionsExportCurve);
    MenuActions->addAction(ActionMenuActionsExportCoefficients);
    MenuActions->addAction(ActionMenuActionsExportFreeFem);
    MenuActions->addAction(ActionMenuActionsExportFeel);
    MenuHelp->addAction(ActionMenuHelpAboutQt);
    MenuHelp->addAction(ActionMenuHelpAboutFourierFit);

    //Action
    ActionMenuFileInputFile->setText("Import file");
    ActionMenuFileInputFile->setIcon(QIcon("img/dir.png"));
    ActionMenuFileQuit->setText("Quit");
    ActionMenuFileQuit->setIcon(QIcon("img/quit.png"));
    ActionMenuSettingsSettings->setText("Settings");
    ActionMenuSettingsSettings->setIcon(QIcon("img/settings.png"));
    ActionMenuActionsReadFile->setText("Read file");
    ActionMenuActionsReadFile->setIcon(QIcon("img/readfile.png"));
    ActionMenuActionsFourierFit->setText("Fourier fit");
    ActionMenuActionsFourierFit->setIcon(QIcon("img/fourierfit.png"));
    ActionMenuActionsExportCurve->setText("Export curve");
    ActionMenuActionsExportCurve->setIcon(QIcon("img/curve.png"));
    ActionMenuActionsExportCoefficients->setText("Export coefficients");
    ActionMenuActionsExportCoefficients->setIcon(QIcon("img/coefficients.png"));
    ActionMenuActionsExportFreeFem->setText("Export FreeFem++");
    ActionMenuActionsExportFreeFem->setIcon(QIcon("img/freefem.png"));
    ActionMenuActionsExportFeel->setText("Export Feel++");
    ActionMenuActionsExportFeel->setIcon(QIcon("img/feel.png"));
    ActionMenuHelpAboutQt->setText("About Qt");
    ActionMenuHelpAboutQt->setIcon(QIcon("img/Qt.png"));
    ActionMenuHelpAboutFourierFit->setText("About FourierFit");
    ActionMenuHelpAboutFourierFit->setIcon(QIcon("img/fourierfit.png"));

    //Widget
    WidgetCentral->setLayout(GridCentral);

    //Grid
    GridCentral->addWidget(FrameFileIn, 0, 0, 1, 1);
    GridCentral->addWidget(FrameFileDisplay, 1, 0, 1, 1);
    GridCentral->addWidget(FramePlot, 0, 1, 2, 1);
    GridCentral->addWidget(FrameInformations, 0, 2, 2, 1);

    GridFileIn->addWidget(LabelFileIn, 0, 0, 1, 1);
    GridFileIn->addWidget(LineEditFileIn, 0, 1, 1, 1);
    GridFileIn->addWidget(PushButtonFileIn, 0, 2, 1, 1);
    GridFileIn->addWidget(PushButtonReadFileIn, 1, 0, 1, 3);

    GridFileDisplay->addWidget(ListWidgetFileDisplay, 0, 0, 1, 1);

    GridPlot->addWidget(PushButtonFourierFit, 0, 0, 1, 1);
    GridPlot->addWidget(SpinBoxFourierFit, 0, 1, 1, 1);
    GridPlot->addWidget(CustomPlot, 1, 0, 1, 2);

    GridInformations->addWidget(TextEditInformations, 0, 0, 4, 1);
    GridInformations->addWidget(PushButtonExportCurve, 0, 1, 1, 1);
    GridInformations->addWidget(PushButtonExportCoefficients, 1, 1, 1, 1);
    GridInformations->addWidget(PushButtonExportFreeFem, 2, 1, 1, 1);
    GridInformations->addWidget(PushButtonExportFeel, 3, 1, 1, 1);

    //Frame
    FrameFileIn->setLayout(GridFileIn);
    FrameFileDisplay->setLayout(GridFileDisplay);
    FramePlot->setLayout(GridPlot);

    //Label
    LabelFileIn->setText("Input file");

    //LineEdit
    //...

    //PushButton
    PushButtonFileIn->setIcon(QIcon("img/dir.png"));
    PushButtonFileIn->setToolTip("Input file directory");
    PushButtonReadFileIn->setText("Read file");
    PushButtonReadFileIn->setIcon(QIcon("img/readfile.png"));
    PushButtonFourierFit->setText("Fourier Fit");
    PushButtonFourierFit->setIcon(QIcon("img/fourierfit.png"));
    PushButtonExportCurve->setIcon(QIcon("img/curve.png"));
    PushButtonExportCurve->setToolTip("Export curve");
    PushButtonExportCurve->setIconSize(QSize(36, 36));
    PushButtonExportCoefficients->setIcon(QIcon("img/coefficients.png"));
    PushButtonExportCoefficients->setToolTip("Export coefficients");
    PushButtonExportCoefficients->setIconSize(QSize(36, 36));
    PushButtonExportFreeFem->setIcon(QIcon("img/freefem.png"));
    PushButtonExportFreeFem->setToolTip("Export FreeFem++");
    PushButtonExportFreeFem->setIconSize(QSize(36, 36));
    PushButtonExportFeel->setIcon(QIcon("img/feel.png"));
    PushButtonExportFeel->setToolTip("Export Feel++");
    PushButtonExportFeel->setIconSize(QSize(36, 36));

    //ListWidget
    //...

    //SpinBox
    SpinBoxFourierFit->setToolTip("Fourier fit order");
    SpinBoxFourierFit->setRange(1, 100);
    SpinBoxFourierFit->setValue(IntCurrentOrder);

    //Vector
    //...

    //CustomPlot
    CustomPlot->addGraph(); //Signal
    CustomPlot->addGraph(); //FourierFit

    //TextEdit
    TextEditInformations->setReadOnly(true);


    //String
    bool Res;
    QString TMPCurrentDirectory = GetCurrentDirectory(&Res);
    if (Res) StringCurrentDirectory = TMPCurrentDirectory;
    QString TMPCurrentSeparator = GetCurrentSeparator(&Res);
    if (Res) StringCurrentSeparator = TMPCurrentSeparator;
    if (StringCurrentSeparator.contains("\\")){
        if (StringCurrentSeparator.compare("\\t") == 0){
            StringCurrentSeparator = "\t";
        }
        else if (StringCurrentSeparator.compare("\\n") == 0){
            StringCurrentSeparator = "\n";
        }
    }

    //Int
    int TMPCurrentOrder = GetCurrentOrder(&Res);
    if (Res){
        IntCurrentOrder = TMPCurrentOrder;
        SpinBoxFourierFit->setValue(IntCurrentOrder);
    }
}

void MainWindow::InitSig(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    //Action
    connect(ActionMenuFileInputFile, SIGNAL(triggered(bool)), this, SLOT(DoFileDirectory()));
    connect(ActionMenuFileQuit, SIGNAL(triggered(bool)), this, SLOT(DoQuit()));
    connect(ActionMenuSettingsSettings, SIGNAL(triggered(bool)), this, SLOT(DoSettings()));
    connect(ActionMenuActionsReadFile, SIGNAL(triggered(bool)), this, SLOT(DoReadFile()));
    connect(ActionMenuActionsFourierFit, SIGNAL(triggered(bool)), this, SLOT(DoFourierFit()));
    connect(ActionMenuActionsExportCurve, SIGNAL(triggered(bool)), this, SLOT(DoExportCurve()));
    connect(ActionMenuActionsExportCoefficients, SIGNAL(triggered(bool)), this, SLOT(DoExportCoefficients()));
    connect(ActionMenuActionsExportFreeFem, SIGNAL(triggered(bool)), this, SLOT(DoExportFreeFem()));
    connect(ActionMenuActionsExportFeel, SIGNAL(triggered(bool)), this, SLOT(DoExportFeel()));
    connect(ActionMenuHelpAboutQt, SIGNAL(triggered(bool)), this, SLOT(DoAboutQt()));
    connect(ActionMenuHelpAboutFourierFit, SIGNAL(triggered(bool)), this, SLOT(DoAboutFourierFit()));

    //PushButton
    connect(PushButtonFileIn, SIGNAL(clicked(bool)), this, SLOT(DoFileDirectory()));
    connect(PushButtonReadFileIn, SIGNAL(clicked(bool)), this, SLOT(DoReadFile()));
    connect(PushButtonFourierFit, SIGNAL(clicked(bool)), this, SLOT(DoFourierFit()));
    connect(PushButtonExportCurve, SIGNAL(clicked(bool)), this, SLOT(DoExportCurve()));
    connect(PushButtonExportCoefficients, SIGNAL(clicked(bool)), this, SLOT(DoExportCoefficients()));
    connect(PushButtonExportFreeFem, SIGNAL(clicked(bool)), this, SLOT(DoExportFreeFem()));
    connect(PushButtonExportFeel, SIGNAL(clicked(bool)), this, SLOT(DoExportFeel()));

    //ListWidget
    connect(ListWidgetFileDisplay, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(DoConvertData()));
}

void MainWindow::InitCss(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    //MainWindow
    this->setWindowIcon(QIcon("img/fourierfit.png"));
    this->setWindowTitle("FourierFit -- version " + VERSION);
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    this->move(x, y);
    this->show();

    //Frame
    FrameFileIn->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
    FrameFileDisplay->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
    FramePlot->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);

    //CustomPlot
    QPen BluePen;
    BluePen.setColor(Qt::blue);
    QPen RedDotPen;
    RedDotPen.setColor(Qt::red);
    RedDotPen.setStyle(Qt::DashDotLine);
    CustomPlot->graph(0)->setPen(BluePen);
    CustomPlot->graph(1)->setPen(RedDotPen);
}

void MainWindow::DoFillFileList(const QStringList *Lines){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    ListWidgetFileDisplay->blockSignals(true);
    for (int i = 0; i < Lines->size(); i++){
            QListWidgetItem *Item = new QListWidgetItem(ListWidgetFileDisplay);
            Item->setText(Lines->at(i));
            Item->setFlags(Item->flags() | Qt::ItemIsUserCheckable);
            Item->setCheckState(Qt::Checked);
            ListWidgetFileDisplay->addItem(Item);
    }
    ListWidgetFileDisplay->blockSignals(false);
}

void MainWindow::DoPlotSignal(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    int NX = VectorSignalX->size();
    int NY = VectorSignalY->size();

    if ((NX > 0) && (NY > 0) && (NX == NY)){
        CustomPlot->graph(0)->setData(*VectorSignalX, *VectorSignalY);
        CustomPlot->xAxis->rescale();
        CustomPlot->yAxis->rescale();
        CustomPlot->replot();
    }
}

void MainWindow::DoPlotFourierFit(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    int NX = VectorFourierFitX->size();
    int NY = VectorFourierFitY->size();

    if ((NX > 0) && (NY > 0) && (NX == NY)){
        CustomPlot->graph(1)->setData(*VectorFourierFitX, *VectorFourierFitY);
        CustomPlot->xAxis->rescale();
        CustomPlot->yAxis->rescale();
        CustomPlot->replot();
    }
}

void MainWindow::DoFillInformations(const int Order){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    double Error = CalculateError(VectorSignalY, VectorFourierFitY);

    int N = VectorCoefficients->size();
    int k = 0;

    QString Text = "error = ";
    Text += QString::number(Error);
    Text += "\n\n";

    if (N == (2*Order+2)){
        Text += "omega = ";
        Text += QString::number(VectorCoefficients->at(k));    k++;
        Text += "\n";
        Text += "a0 = ";
        Text += QString::number(VectorCoefficients->at(k));    k++;
        Text += "\n";

        for (int i = 1; i <= Order; i++){
            Text += "a" + QString::number(i) + " = ";
            Text += QString::number(VectorCoefficients->at(k));    k++;
            Text += "\n";
            Text += "b" + QString::number(i) + " = ";
            Text += QString::number(VectorCoefficients->at(k));    k++;
            Text += "\n";
        }
    }

    TextEditInformations->setText(Text);
}

//Constructor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    InitVar();
    InitWin();
    InitSig();
    InitCss();
}

//Slots
void MainWindow::DoFileDirectory(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    QString FileName = QFileDialog::getOpenFileName(this, "Select input file", StringCurrentDirectory);

    if (!FileName.isEmpty()) LineEditFileIn->setText(FileName);
}

void MainWindow::DoReadFile(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    //Get FileName
    QString FileName = LineEditFileIn->text();

    if (FileName.isEmpty()){
        QMessageBox::warning(this, "Warning", "Empty file name");
        return;
    }

    //Read File
    bool Res;
    QStringList *Lines = ReadFile(FileName, &Res);

    if (!Res){
        QMessageBox::warning(this, "Warning", "Unable to read:\n" + FileName);
        return;
    }

    //Fill List
    DoFillFileList(Lines);

    //Convert to "double" data
    DoConvertData();
}

void MainWindow::DoSettings(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    DialogSettings *Dialog = new DialogSettings(this);
    int Result = Dialog->exec();

    if (Result == QDialog::Accepted){
        bool Res;
        QString TMPCurrentDirectory = GetCurrentDirectory(&Res);
        if (Res) StringCurrentDirectory = TMPCurrentDirectory;

        int TMPCurrentOrder = GetCurrentOrder(&Res);
        if (Res) IntCurrentOrder = TMPCurrentOrder;
        SpinBoxFourierFit->setValue(IntCurrentOrder);
    }
}

void MainWindow::DoConvertData(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    VectorSignalX->clear();
    VectorSignalY->clear();

    int NItems = ListWidgetFileDisplay->count();

    for (int i = 0; i < NItems; i++){
        if (ListWidgetFileDisplay->item(i)->checkState() == Qt::Checked){
            QString Line = ListWidgetFileDisplay->item(i)->text();
            QStringList Words = Line.split(StringCurrentSeparator);

            if (Words.size() == 2){
                bool Res1;
                bool Res2;

                double X = Words.at(0).toDouble(&Res1);
                double Y = Words.at(1).toDouble(&Res2);

                if (Res1 && Res2){
                    VectorSignalX->append(X);
                    VectorSignalY->append(Y);
                }
            }
        }
    }

    //Plot signal
    DoPlotSignal();
}

void MainWindow::DoFourierFit(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    VectorFourierFitX->clear();
    VectorFourierFitY->clear();
    VectorCoefficients->clear();

    int Order = SpinBoxFourierFit->value();

    bool Res = FourierFit(Order, VectorSignalX, VectorSignalY, VectorFourierFitX, VectorFourierFitY, VectorCoefficients);

    if (Res){
        //Plot Fourier fit
        DoPlotFourierFit();

        //Fill informations
        DoFillInformations(Order);
    }
}

void MainWindow::DoExportCurve(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    QStringList ItemList;
    ItemList.append("Signal");;
    ItemList.append("Fourier fit");

    bool Res;
    QString Item = QInputDialog::getItem(this, "Export curve", "Choose one of the curves", ItemList, 0, false, &Res);

    if (!Res) return;

    QString FileName = QFileDialog::getSaveFileName(this, "Choose a file", StringCurrentDirectory);

    if (FileName.isEmpty()) return;

    if (Item == ItemList.at(0)){
        Res = ExportCurve(FileName, VectorSignalX, VectorSignalY);
        if (!Res) QMessageBox::warning(this, "Warning", "Unbale to write:\n" + FileName);
    }
    else{
        Res = ExportCurve(FileName, VectorFourierFitX, VectorFourierFitY);
        if (!Res) QMessageBox::warning(this, "Warning", "Unbale to write:\n" + FileName);
    }
}

void MainWindow::DoExportCoefficients(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    QString FileName = QFileDialog::getSaveFileName(this, "Choose a file", StringCurrentDirectory);

    if (FileName.isEmpty()) return;

    bool Res = ExportCoefficients(FileName, VectorCoefficients);
    if (!Res) QMessageBox::warning(this, "Warning", "Unbale to write:\n" + FileName);
}

void MainWindow::DoExportFreeFem(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    QString FileName = QFileDialog::getSaveFileName(this, "Choose a FreeFem++ file", StringCurrentDirectory, "Edp (*.edp)");

    if (FileName.isEmpty()) return;

    bool Res = ExportFreeFem(FileName, VectorCoefficients);
    if (!Res) QMessageBox::warning(this, "Warning", "Unbale to write:\n" + FileName);
}

void MainWindow::DoExportFeel(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    QString FileName = QFileDialog::getSaveFileName(this, "Choose a Feel++ file", StringCurrentDirectory, "JSON (*.json)");

    if (FileName.isEmpty()) return;

    bool Res = ExportFeel(FileName, VectorCoefficients);
    if (!Res) QMessageBox::warning(this, "Warning", "Unbale to write:\n" + FileName);
}

void MainWindow::DoAboutQt(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    QMessageBox::aboutQt(this, "About Qt");
}

void MainWindow::DoAboutFourierFit(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    QString Text = "<h2>About FourierFit</h2><br/>"
                   "FourierFit provide an open source solution to calculate the fit of a curve using Fourier model and export results for FreeFem++ or Feel++ usage<br/>"
                   "<a href=\"http://www.freefem.org/\">http://www.freefem.org/</a><br/>"
                   "<a href=\"http://www.feelpp.org/\">http://www.feelpp.org/</a><br/><br/>"
                   "This software is licensed under GNU GPL version 3<br/><br/>"
                   "Thank to :"
                   "<ul>"
                   "<li>Emanuel Eichhammer for the QCustomPlot widget<br/><a href=\"http://www.qcustomplot.com/\">http://www.qcustomplot.com/</a><li/>"
                   "<li>Everaldo Coelho for the Crystal Clear icon set<br/><a href=\"https://commons.wikimedia.org/wiki/Crystal_Clear\">https://commons.wikimedia.org/wiki/Crystal_Clear</a></li>"
                   "</ul>"
                   "Author: Simon Garnotel<br/>"
                   "Year: 2016<br/>"
                   "Version: 1.0<br/>";
    QMessageBox::about(this, "About FourierFit", Text);
}

void MainWindow::DoQuit(){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    qApp->quit();
}

void MainWindow::resizeEvent(QResizeEvent *){
#if DEBUG
    qInfo() << "Info: " << Q_FUNC_INFO;
#endif

    int Width = this->width();

    FramePlot->setMinimumWidth(Width/2);
}


