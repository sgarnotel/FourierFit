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

bool FourierFit(const int Order,
                const QVector<double> *SignalX, const QVector<double> *SignalY,
                QVector<double> *FourierFitX, QVector<double> *FourierFitY,
                QVector<double> *Coefficients
                ){
    int NX = SignalX->size();
    int NY = SignalY->size();

    if ((NX > 0) && (NX == NY)){
        //Omega
        double Period = SignalX->at(NX-1);
        double Omega = 2. * M_PI / Period;

        //First coefficient
        double A0 = 0.;
        for (int i = 0; i < NX-1; i++){  //Trapezoidal rule
            A0 += (SignalX->at(i+1) - SignalX->at(i)) * (SignalY->at(i+1) + SignalY->at(i)) / 2.;
        }
        A0 = A0 / Period;

        //Other coefficients
        double *A = new double[Order];
        double *B = new double[Order];
        for (int i = 0; i < Order; i++){
            A[i] = 0.;
            B[i] = 0.;
            for (int j = 0; j < NX-1; j++){  //Trapezoidal rule (again)
                A[i] += (SignalX->at(j+1) - SignalX->at(j)) * (SignalY->at(j+1)*cos((i+1) * Omega * SignalX->at(j+1)) + SignalY->at(j)*cos((i+1) * Omega * SignalX->at(j))) / 2.;
                B[i] += (SignalX->at(j+1) - SignalX->at(j)) * (SignalY->at(j+1)*sin((i+1) * Omega * SignalX->at(j+1)) + SignalY->at(j)*sin((i+1) * Omega * SignalX->at(j))) / 2.;
            }
            A[i] = 2. * A[i] / Period;
            B[i] = 2. * B[i] / Period;
        }

        //Fill Coefficients
        Coefficients->append(Omega);
        Coefficients->append(A0);
        for (int i = 0; i < Order; i++){
            Coefficients->append(A[i]);
            Coefficients->append(B[i]);
        }

        //Construct Curve
        for (int i = 0; i < NX; i++){
            FourierFitX->append(SignalX->at(i));
            double FFY = A0;
            for (int j = 0; j < Order; j++){
                FFY += A[j] * cos((j+1) * Omega * SignalX->at(i));
                FFY += B[j] * sin((j+1) * Omega * SignalX->at(i));
            }
            FourierFitY->append(FFY);
        }

        //Delete
        delete[] A;
        delete[] B;

        return true;
    }
    else{
        qWarning() << Q_FUNC_INFO;
        qWarning() << "Null or non coherent size";

        return false;
    }
}

double CalculateError(const QVector<double> *Signal, const QVector<double> *FourierFit){
    int NS = Signal->size();
    int NFF = FourierFit->size();

    if ((NS > 0) && (NS == NFF)){
        double Error = 0.;

        for (int i = 0; i < NS; i++){
            Error += qAbs(Signal->at(i) - FourierFit->at(i)) / qAbs(Signal->at(i));
        }
        Error = Error / NS;

        return Error;
    }
    else{
        qWarning() << Q_FUNC_INFO;
        qWarning() << "Null or non coherent size";
        return -1.;
    }
}


