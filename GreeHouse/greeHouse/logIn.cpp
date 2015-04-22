#include "logIn.h"
#include <QDesktopWidget>
#include <QApplication>
#include <Qt>
#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QLabel>
#include  "const.h"
#include <QLineEdit>
 #include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QBitmap>
#include <qDebug>
#include "MainWindow.h"

logIn::logIn( QWidget * parent,Qt::WindowFlags):QDialog(parent,Qt::FramelessWindowHint)
{
	//setWindowTitle(QObject::tr("��½����"));
	QDesktopWidget *desktop = QApplication::desktop();  
	setGeometry(desktop->width()/3,desktop->height()/2,400,200);//���ô��ڵ�λ�úʹ�С
	//setWindowFlags(Qt::FramelessWindowHint);	//�����ޱ߿�Ĵ���
	m_pTitle = new QLabel;
	m_pIcon = new QLabel;
	m_pPwd = new QLabel(QObject::tr("����"));
	m_pUser = new QLabel(QObject::tr("�û���"));
	m_pPwdEdit = new QLineEdit;
	m_pUserEdit = new QLineEdit;
	m_pLogBtn = new QPushButton(QObject::tr("��½"));
	m_pQuitBtn = new QPushButton(QObject::tr("�˳�"));

	m_pTitle->setText(QObject::tr("ϵͳ��½����"));
	m_pTitle->setAlignment(Qt::AlignHCenter);
	//m_pIcon->setPixmap(QPixmap(":/data/logIcon"));
	//m_pIcon->resize(1,1);
	
	//����ˮƽ���ֹ�����
	//QHBoxLayout * m_pTitleLayout = new QHBoxLayout;
	//m_pTitleLayout->setSpacing(0);
	//m_pTitleLayout->addWidget(m_pIcon);
	//m_pTitleLayout->addWidget(m_pTitle);

	//�������񲼾ֹ�����
	QGridLayout *m_pGridLayout = new QGridLayout;
	m_pGridLayout->setSpacing(10);
	m_pGridLayout->setMargin(20);
	m_pGridLayout->addWidget(m_pUser,0,1,1,2);
	m_pGridLayout->addWidget(m_pUserEdit,0,3,1,3);
	m_pGridLayout->addWidget(m_pPwd,1,1,1,2);
	m_pGridLayout->addWidget(m_pPwdEdit,1,3,1,3);

	//����ˮƽ�������ֹ�����
	QHBoxLayout *btnLayout = new QHBoxLayout;
	btnLayout->setMargin(20);
	btnLayout->setSpacing(20);//�ڲ��ؼ����Ϊ20����ˮƽ
	btnLayout->addWidget(m_pLogBtn);
	btnLayout->addWidget(m_pQuitBtn);

	//������ֱ�����ֹ�����
	QVBoxLayout *m_pMainLayout = new QVBoxLayout;
	//m_pMainLayout->setSpacing(0);
	//m_pMainLayout->setContentsMargins(0,0,0,0);
	m_pMainLayout->addWidget(m_pTitle);
	//m_pMainLayout->addLayout(m_pTitleLayout);
	//m_pMainLayout->stretch(40);
	m_pMainLayout->addLayout(m_pGridLayout);
	//m_pMainLayout->stretch(20);
	m_pMainLayout->addLayout(btnLayout);
	setLayout(m_pMainLayout);

	/*���´���ʵ��Բ�Ǿ��εĴ���*/

	//����һ��λͼ
	QBitmap objBitmap(size());
	//QPainter������λͼ�ϻ滭
	QPainter painter(&objBitmap); 
	//���λͼ���ο�(�ð�ɫ���)
	painter.fillRect(rect(),Qt::white);
	painter.setBrush(QColor(0,0,0));
	//��λͼ�ϻ�Բ�Ǿ���(�ú�ɫ���)
	painter.drawRoundedRect(this->rect(),10,10);
	//ʹ��setmask���˼���
	setMask(objBitmap);

	connect(m_pLogBtn,SIGNAL(clicked()),this,SLOT(accept()));
	connect(m_pQuitBtn,SIGNAL(clicked()),this,SLOT(close()));
}

void logIn::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		dragPosition = event->globalPos() - frameGeometry().topLeft();
		event->accept();
	}
}

void logIn::mouseMoveEvent(QMouseEvent *event) {
	if (event->buttons() & Qt::LeftButton) {
		move(event->globalPos() - dragPosition);
		event->accept();
	}
}

void logIn::accept()
{
	//FIXME ������֤ ��ȡ�ļ�
	qDebug()<<"OK\n";
	this->close();
	MainWindow *mainWin = new MainWindow;
	
	mainWin->show();
}

void logIn::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	
	painter.drawPixmap(0,0,width(),height(),QPixmap(":/data/logImage"));//���ñ���ͼƬ
}
logIn::~logIn(void)
{
}
