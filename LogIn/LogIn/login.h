#ifndef LOGIN_H
#define LOGIN_H

#include <QtGui/QMainWindow>
#include "ui_login.h"

class LogIn : public QMainWindow
{
	Q_OBJECT

public:
	LogIn(QWidget *parent = 0, Qt::WFlags flags = 0);
	~LogIn();

private:
	Ui::LogInClass ui;
};

#endif // LOGIN_H
