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

#ifndef HEADER_H
#define HEADER_H

#define DEBUG   1

//C++
#include <cmath>

//Qt
#include <QMainWindow>
#include <QApplication>
#include <QtWidgets>

//QCustomPlot
#include "qcustomplot.h"

//Define
#define VERSION             QString::fromStdString("1.0")
#define DEFAULT_DIRECTORY   QString::fromStdString("/home")
#define DEFAULT_ORDER       (int)7
#define DEFAULT_SEPARATOR   QString::fromStdString("\\t")

//io.cpp
bool SetCurrentDirectory(QString Directory);
QString GetCurrentDirectory(bool *Res);
bool SetCurrentOrder(int Order);
int GetCurrentOrder(bool *Res);
bool SetCurrentSeparator(QString Separator);
QString GetCurrentSeparator(bool *Res);
QStringList *ReadFile(const QString FileName, bool *Res);
bool ExportCurve(const QString FileName, const QVector<double> *X, const QVector<double> *Y);
bool ExportCoefficients(const QString FileName, const QVector<double> *Coefficients);
bool ExportFreeFem(const QString FileName, const QVector<double> *Coefficients);
bool ExportFeel(const QString FileName, const QVector<double> *Coefficients);

//fouerifit.cpp
bool FourierFit(const int Order,
                const QVector<double> *SignalX, const QVector<double> *SignalY,
                QVector<double> *FourierFitX, QVector<double> *FourierFitY,
                QVector<double> *Coefficients
                );
double CalculateError(const QVector<double> *Signal, const QVector<double> *FourierFit);

#endif // HEADER_H


