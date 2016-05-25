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

#include "header.h"

bool SetCurrentDirectory(QString Directory){
    QFile File("system/directory.dat");
    if (File.open(QIODevice::WriteOnly)){
        File.write(Directory.toStdString().c_str());
        File.close();
        return true;
    }
    else{
        qWarning() << "Warning: " << Q_FUNC_INFO;
        qWarning() << "Warning: " << "Unable to write system/directory.dat";
        return false;
    }
}

QString GetCurrentDirectory(bool *Res){
    QString Directory;

    QFile File("system/directory.dat");
    if (File.open(QIODevice::ReadOnly)){
        Directory = File.readLine();
        Directory = Directory.remove("\n");
        File.close();
        (*Res) = true;
    }
    else{
        qWarning() << "Warning: " << Q_FUNC_INFO;
        qWarning() << "Warning: " << "Unable to read system/directory.dat";
        (*Res) = false;
    }
    return Directory;
}

bool SetCurrentOrder(int Order){
    QFile File("system/order.dat");
    if (File.open(QIODevice::WriteOnly)){
        File.write(QString::number(Order).toStdString().c_str());
        File.close();
        return true;
    }
    else{
        qWarning() << "Warning: " << Q_FUNC_INFO;
        qWarning() << "Warning: " << "Unable to write system/order.dat";
        return false;
    }
}

int GetCurrentOrder(bool *Res){
    int Order;

    QFile File("system/order.dat");
    if (File.open(QIODevice::ReadOnly)){
        QString TMP = File.readLine();
        TMP = TMP.remove("\n");

        Order = TMP.toInt(Res);
        if (!(*Res)) return Order;

        File.close();
        (*Res) = true;
    }
    else{
        qWarning() << "Warning: " << Q_FUNC_INFO;
        qWarning() << "Warning: " << "Unable to read system/order.dat";
        (*Res) = false;
    }
    return Order;
}

bool SetCurrentSeparator(QString Separator){
    QFile File("system/separator.dat");
    if (File.open(QIODevice::WriteOnly)){
        File.write(Separator.toStdString().c_str());
        File.close();
        return true;
    }
    else{
        qWarning() << "Warning: " << Q_FUNC_INFO;
        qWarning() << "Warning: " << "Unable to write system/separator.dat";
        return false;
    }
}

QString GetCurrentSeparator(bool *Res){
    QString Separator;

    QFile File("system/separator.dat");
    if (File.open(QIODevice::ReadOnly)){
        Separator = File.readLine();
        Separator = Separator.remove("\n");
        File.close();
        (*Res) = true;
    }
    else{
        qWarning() << "Warning: " << Q_FUNC_INFO;
        qWarning() << "Warning: " << "Unable to read system/separator.dat";
        (*Res) = false;
    }

    return Separator;
}

QStringList *ReadFile(const QString FileName, bool *Res){
    QStringList *Lines = new QStringList;

    QFile File(FileName);
    if (File.open(QIODevice::ReadOnly)){
        while(!File.atEnd()){
            QString Line = File.readLine();
            Line = Line.remove("\n");
            Lines->append(Line);
        }
        File.close();
        (*Res) = true;
    }
    else{
        qWarning() << "Warning: " << Q_FUNC_INFO;
        qWarning() << "Warning: " << "Unable to read " << FileName;
        (*Res) = false;
    }

    return Lines;
}

bool ExportCurve(const QString FileName, const QVector<double> *X, const QVector<double> *Y){
    int NX = X->size();
    int NY = Y->size();

    if ((NX > 0) && (NY == NX)){
        QFile File(FileName);
        if (File.open(QIODevice::WriteOnly)){
            QTextStream Stream(&File);
            for (int i = 0; i < NX; i++){
                Stream << X->at(i) << "\t" << Y->at(i) << endl;
            }
            File.close();
            return true;
        }
        else{
            qWarning() << "Warning: " << Q_FUNC_INFO;
            qWarning() << "Unable to write " << FileName;
            return false;
        }
    }
    else{
        qWarning() << "Warning: " << Q_FUNC_INFO;
        qWarning() << "Null size";
        return false;
    }
}


bool ExportCoefficients(const QString FileName, const QVector<double> *Coefficients){
    int N = Coefficients->size();
    int Order = (N-2)/2;

    if (N > 1){
        QFile File(FileName);
        if (File.open(QIODevice::WriteOnly)){
            QTextStream Stream(&File);
            int k = 0;

            Stream << "omega = " << Coefficients->at(k) << endl;
            k++;
            Stream << "a0 = " << Coefficients->at(k) << endl;
            k++;

            for (int i = 1; i <= Order; i++){
                Stream << "a" << i << " = " << Coefficients->at(k) << endl;
                k++;
                Stream << "b" << i << " = " << Coefficients->at(k) << endl;
                k++;
            }

            File.close();
            return true;
        }
        else{
            qWarning() << "Warning: " << Q_FUNC_INFO;
            qWarning() << "Warning: " << "Unable to write " << FileName;
            return false;
        }
    }
    else{
        qWarning() << "Warning: " << Q_FUNC_INFO;
        qWarning() << "Warning: " << "Non coherent size";
        return false;
    }
}




bool ExportFreeFem(const QString FileName, const QVector<double> *Coefficients){
    int N = Coefficients->size();
    int Order = (N-2) / 2;

    if (N > 1){
        QFile File(FileName);
        if (File.open(QIODevice::WriteOnly)){
            QTextStream Stream(&File);

            int k = 0;
            Stream << "real omega = " << Coefficients->at(k) << ";" << endl;
            k++;
            Stream << "real a0 = " << Coefficients->at(k) << ";" << endl;
            k++;

            for (int i = 1; i <= Order; i++){
                Stream << "real a" << i << " = " << Coefficients->at(k) << ";" << endl;
                k++;
                Stream << "real b" << i << " = " << Coefficients->at(k) << ";" << endl;
                k++;
            }

            Stream << endl;
            Stream << "func real FourierFit (real t){" << endl;
            Stream << "\treturn a0" << endl;
            for (int i = 1; i <= Order; i++){
                Stream << "\t\t+ a" << i << " * cos(" << i << ".*omega*t)";
                Stream << " + b" << i << " * sin(" << i << ".*omega*t)";
                Stream << endl;
            }
            Stream << "\t\t;" << endl;
            Stream << "}" << endl;
            Stream << "\n\n\n" << endl;

            File.close();
            return true;
        }
        else{
            qWarning() << "Warning: " << Q_FUNC_INFO;
            qWarning() << "Warning: " << "Unable to write " << FileName;
            return false;
        }
    }
    else{
        qWarning() << "Warning: " << Q_FUNC_INFO;
        qWarning() << "Warning: " << "Non coherent size";
        return false;
    }
}


bool ExportFeel(const QString FileName, const QVector<double> *Coefficients){
    int N = Coefficients->size();
    int Order = (N-2)/2;

    if (N > 1){
        QFile File(FileName);
        if (File.open(QIODevice::WriteOnly)){
            QTextStream Stream(&File);
            int k = 0;

            Stream << "\"Parameters\":" << endl;
            Stream << "{" << endl;
            Stream << "\t\"omega\":\"" << Coefficients->at(k) << "\"," << endl;
            k++;
            Stream << "\t\"a0\":\"" << Coefficients->at(k) << "\"," << endl;
            k++;
            for (int i = 1; i <= Order; i++){
                Stream << "\t\"a" << i << "\":\"" << Coefficients->at(k) << "\"," << endl;
                k++;
                if (k != (N-1)){
                    Stream << "\t\"b" << i << "\":\"" << Coefficients->at(k) << "\"," << endl;
                    k++;
                }
                else{
                    Stream << "\t\"b" << i << "\":\"" << Coefficients->at(k) << "\"" << endl;
                }
            }
            Stream << "}\n" << endl;

            Stream << "\n{" << endl;
            Stream << "\t\"expr\":\"{a0";
            for (int i = 1; i <= Order; i++){
                Stream << " + a" << i << "*cos(" << i << ".*omega*t)";
                Stream << " + b" << i << "*sin(" << i << ".*omega*t)";
            }
            Stream << ",0,0}:omega:a0";
            for (int i = 1; i <= Order; i++){
                Stream << ":a" << i << ":b" << i;
            }
            Stream << "\"" << endl;
            Stream << "}" << endl;

            File.close();
            return true;
        }
        else{
            qWarning() << "Warning: " << Q_FUNC_INFO;
            qWarning() << "Warning: " << "Unable to write " << FileName;
            return false;
        }
    }
    else{
        qWarning() << "Warning: " << Q_FUNC_INFO;
        qWarning() << "Warning: " << "Non coherent size";
        return false;
    }
}


