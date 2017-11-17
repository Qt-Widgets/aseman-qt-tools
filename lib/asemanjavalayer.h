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

#ifndef ASEMANJAVALAYER_H
#define ASEMANJAVALAYER_H

#include <QObject>

class AsemanJavaLayerPrivate;
class AsemanJavaLayer : public QObject
{
    Q_OBJECT
public:
    AsemanJavaLayer();
    virtual ~AsemanJavaLayer();

    static AsemanJavaLayer *instance();

    bool sharePaper( const QString & title, const QString & msg );
    bool shareFile( const QString & path, const QString & type );
    bool openFile( const QString & path, const QString & type );
    bool startCamera( const QString & output );
    bool callNumber( const QString & number );
    bool getOpenPictures();

    bool transparentStatusBar();
    bool transparentNavigationBar();

    int densityDpi();
    int screenSizeWidth();
    int screenSizeHeight();
    int getSizeName();
    int statusBarHeight();
    bool isTablet();
    qreal density();

    QString packageName();
    QString deviceName();
    QString deviceId();

    QRect keyboardRect();

    void setKeepScreenOn(bool stt);

public Q_SLOTS:
    bool startService();
    bool stopService();

Q_SIGNALS:
    void incomingShare( const QString & title, const QString & msg );
    void incomingImage( const QString & path );
    void selectImageResult( const QString & path );
    void keyboardVisiblityChanged(qint32 height);
    void activityPaused();
    void activityStopped();
    void activityResumed();
    void activityStarted();
    void activityRestarted();
    void activityDestroyed();

private Q_SLOTS:
    void load_buffer();

protected:
    void setImplemented(bool stt);

private:
    AsemanJavaLayerPrivate *p;
};

#endif // ASEMANJAVALAYER_H
