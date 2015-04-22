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
	//setWindowTitle(QObject::tr("登陆界面"));
	QDesktopWidget *desktop = QApplication::desktop();  
	setGeometry(desktop->width()/3,desktop->height()/2,400,200);//设置窗口的位置和大小
	//setWindowFlags(Qt::FramelessWindowHint);	//创建无边框的窗口
	m_pTitle = new QLabel;
	m_pIcon = new QLabel;
	m_pPwd = new QLabel(QObject::tr("密码"));
	m_pUser = new QLabel(QObject::tr("用户名"));
	m_pPwdEdit = new QLineEdit;
	m_pUserEdit = new QLineEdit;
	m_pLogBtn = new QPushButton(QObject::tr("登陆"));
	m_pQuitBtn = new QPushButton(QObject::tr("退出"));

	m_pTitle->setText(QObject::tr("系统登陆界面"));
	m_pTitle->setAlignment(Qt::AlignHCenter);
	//m_pIcon->setPixmap(QPixmap(":/data/logIcon"));
	//m_pIcon->resize(1,1);
	
	//创建水平布局管理器
	//QHBoxLayout * m_pTitleLayout = new QHBoxLayout;
	//m_pTitleLayout->setSpacing(0);
	//m_pTitleLayout->addWidget(m_pIcon);
	//m_pTitleLayout->addWidget(m_pTitle);

	//创建网格布局管理器
	QGridLayout *m_pGridLayout = new QGridLayout;
	m_pGridLayout->setSpacing(10);
	m_pGridLayout->setMargin(20);
	m_pGridLayout->addWidget(m_pUser,0,1,1,2);
	m_pGridLayout->addWidget(m_pUserEdit,0,3,1,3);
	m_pGridLayout->addWidget(m_pPwd,1,1,1,2);
	m_pGridLayout->addWidget(m_pPwdEdit,1,3,1,3);

	//创建水平按键布局管理器
	QHBoxLayout *btnLayout = new QHBoxLayout;
	btnLayout->setMargin(20);
	btnLayout->setSpacing(20);//内部控件间隔为20像素水平
	btnLayout->addWidget(m_pLogBtn);
	btnLayout->addWidget(m_pQuitBtn);

	//创建垂直主布局管理器
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

	/*以下代码实现圆角矩形的窗口*/

	//生成一张位图
	QBitmap objBitmap(size());
	//QPainter用于在位图上绘画
	QPainter painter(&objBitmap); 
	//填充位图矩形框(用白色填充)
	painter.fillRect(rect(),Qt::white);
	painter.setBrush(QColor(0,0,0));
	//在位图上画圆角矩形(用黑色填充)
	painter.drawRoundedRect(this->rect(),10,10);
	//使用setmask过滤即可
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
	//FIXME 密码验证 读取文件
	qDebug()<<"OK\n";
	this->close();
	MainWindow *mainWin = new MainWindow;
	
	mainWin->show();
}

void logIn::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	
	painter.drawPixmap(0,0,width(),height(),QPixmap(":/data/logImage"));//设置背景图片
}
logIn::~logIn(void)
{
}
