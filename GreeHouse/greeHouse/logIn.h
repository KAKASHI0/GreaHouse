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
	void mousePressEvent(QMouseEvent *);//��д�����������ƶ�ʵ�ִ��ڵ��϶�
	void mouseMoveEvent(QMouseEvent *);
	void paintEvent(QPaintEvent *);//���Ʊ���ͼƬ
private:
	QPoint dragPosition;
	QLabel *m_pTitle ;//�Զ����½���ڵı���
	QLabel *m_pIcon;//�Զ��崰�ڵ�ͼ��

	QLabel *m_pUser;
	QLabel *m_pPwd;
	QLineEdit *m_pUserEdit;
	QLineEdit * m_pPwdEdit;
	QPushButton	 *m_pQuitBtn;
	QPushButton	 *m_pLogBtn;
public slots:
	void accept();
};

