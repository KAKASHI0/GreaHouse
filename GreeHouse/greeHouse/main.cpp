
#include <QtCore/QTextCodec>
#include <QtGui/QApplication>
#include <QString>
#include "logIn.h"
#include "MainWindow.h"
int main(int argc, char *argv[])
{
	QTextCodec::setCodecForTr(QTextCodec::codecForName("gb18030"));//ÏÔÊ¾ÖÐÎÄ
	QApplication a(argc, argv);
	logIn *userLog = new logIn;
	userLog->show();
	
	//MainWindow *mainWin = new MainWindow;
	
	//mainWin->show();
	return a.exec();
}
