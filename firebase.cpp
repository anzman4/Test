#include "firebase.h"

#include <QFile>
#include <QDebug>
#include <QVariant>
#include <QVariantMap>

#include "firebase/auth/user.h"
#include "firebase/database/data_snapshot.h"

Firebase::Firebase(QObject *parent) : QObject(parent)
{
    QFile file(":/win/google-services.json");
    if (file.exists() && file.open(QIODevice::ReadOnly)) {
        firebase::AppOptions *options =
                firebase::AppOptions::LoadFromJsonConfig(file.readAll().data());
        mApp = firebase::App::Create(*options);
        mAuth = firebase::auth::Auth::GetAuth(mApp);
    }
    else {
        qDebug() << "google-services.json not exits!";
    }
}
