/*
    Copyright (C) 2017 Aseman Team
    http://aseman.co

    AsemanQtTools is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    AsemanQtTools is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ASEMANCAMERACAPTURE_H
#define ASEMANCAMERACAPTURE_H

#include <QObject>

#include "asemantools_global.h"

class AsemanCameraCapturePrivate;
class LIBASEMANTOOLSSHARED_EXPORT AsemanCameraCapture : public QObject
{
    Q_OBJECT
public:
    enum CameraFace {
        CameraFacingFront,
        CameraFacingBack
    };

    AsemanCameraCapture(QObject *parent = 0);
    virtual ~AsemanCameraCapture();

public Q_SLOTS:
    int capture(const QString &dest, AsemanCameraCapture::CameraFace face);

Q_SIGNALS:
    void imageCaptured(int id, const QString &path);

private:
    AsemanCameraCapturePrivate *p;
};

#endif // ASEMANCAMERACAPTURE_H
