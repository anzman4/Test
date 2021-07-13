#ifndef FIREBASE_H
#define FIREBASE_H

#include <QObject>

#include "firebase/auth.h"
#include "firebase/app.h"
#include "firebase/database.h"

class Firebase : public QObject
{
    Q_OBJECT
public:
    explicit Firebase(QObject *parent = nullptr);

signals:

private:
    firebase::auth::Auth* mAuth = nullptr;
    firebase::App* mApp = nullptr;
    firebase::database::Database* mDatabase = nullptr;

};

#endif // FIREBASE_H
