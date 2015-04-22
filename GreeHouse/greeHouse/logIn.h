#pragma once
#include <QtGui/QDialog>

class QLabel;
class QPushButton;
class QLineEdit;

class logIn :
	public QDialog
{
	Q_OBJECT
public:
	logIn( QWidget * parent = 0,Qt::WindowFlags f = 0);
	~logIn(void);
protected:
	//bool winEvent ( MSG * message, long * result );
	void mousePressEvent(QMouseEvent *);//从写鼠标点击和鼠标移动实现窗口的拖动
	void mouseMoveEvent(QMouseEvent *);
	void paintEvent(QPaintEvent *);//绘制背景图片
private:
	QPoint dragPosition;
	QLabel *m_pTitle ;//自定义登陆窗口的标题
	QLabel *m_pIcon;//自定义窗口的图标

	QLabel *m_pUser;
	QLabel *m_pPwd;
	QLineEdit *m_pUserEdit;
	QLineEdit * m_pPwdEdit;
	QPushButton	 *m_pQuitBtn;
	QPushButton	 *m_pLogBtn;
public slots:
	void accept();
};

