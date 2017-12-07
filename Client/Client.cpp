#include "Client.h"

#include <QTcpSocket>
#include <QPainter>
#include <QMessageBox>
#include <QPixmap>
#include <QKeyEvent>
#include <QTimer>

struct Client::Data
{
	QTcpSocket *socket;
	QTimer *timer;
	QPoint team1;
	QPoint hero;
	QPoint team2;
	QPoint enemy;
	QPoint blueBuff1;
	QPoint redBuff1;
	QPoint blueBuff2;
	QPoint redBuff2;
	QPoint Nashor;
	QPoint Dragon;
};

Client::Client(QWidget *parent): QWidget(parent)
{
	data = new Data;
	
	setMaximumSize(640, 640);
	setMinimumSize(640,640);

	data->hero = QPoint(480, 480);
	data->timer = new QTimer(this);
	
	connect(data->timer, &QTimer::timeout, [this]() {update(); });
	data->timer->start(16);
	
	data->socket = new QTcpSocket(this);
	data->socket->abort();
	data->socket->connectToHost("127.0.0.1", 9754);

	connect(data->socket, &QTcpSocket::readyRead, this, &Client::getMsg);
	connect(data->socket, &QTcpSocket::disconnected, [this]() 
	{
		QMessageBox::warning(this, u8"错误",u8"与服务器失去连接");
		exit(0);
	});

	data->team1 = QPoint(40, 600);
	data->hero = QPoint(40, 500);
	data->blueBuff1 = QPoint(180, 320);
	data->redBuff1 = QPoint(640 - 320, 640 - 180);

	data->team2 = QPoint(600, 40);
	data->enemy = QPoint(600, 140);
	data->blueBuff2 = QPoint(640 - 180, 640 - 320);
	data->redBuff2 = QPoint(320, 180);

	data->Nashor = QPoint(160, 160);
	data->Dragon = QPoint(480, 480);
}

Client::~Client()
{
	delete data;
}

void Client::paintEvent(QPaintEvent * e)
{
	QPixmap canvas(640,640);
	QPainter painter(&canvas);

	painter.fillRect(0, 0, 640, 640, Qt::white);
	painter.fillRect(data->team1.x()-40, data->team1.y() -40, 80, 80,Qt::blue);
	painter.fillRect(data->team2.x() -40, data->team2.y() -40, 80, 80, Qt::red);

	painter.fillRect(20,20,40,520,Qt::black);
	painter.fillRect(580, 100, 40, 520, Qt::black);
	painter.fillRect(100, 580, 520, 40, Qt::black);
	painter.fillRect(20, 20, 520, 40, Qt::black);
	painter.setPen(QPen(Qt::black, 40));
	painter.drawLine(100, 540, 540, 100);

	painter.fillRect(data->hero.x()-10, data->hero.y() - 10,20,20,QColor(102,204,250));
	painter.fillRect(data->enemy.x() - 10, data->enemy.y() - 10, 20, 20, QColor(255, 192, 203));

	painter.fillRect(data->redBuff1.x() - 10, data->redBuff1.y() - 10, 20, 20, Qt::red);
	painter.fillRect(data->redBuff2.x() - 10, data->redBuff2.y() - 10, 20, 20, Qt::red);
	painter.fillRect(data->blueBuff1.x() - 10, data->blueBuff1.y() - 10, 20, 20, Qt::blue);
	painter.fillRect(data->blueBuff2.x() - 10, data->blueBuff2.y() - 10, 20, 20, Qt::blue);

	painter.fillRect(data->Nashor.x() - 10, data->Nashor.y() - 10, 20, 20, QColor(255, 0, 255));
	painter.fillRect(data->Dragon.x() - 10, data->Dragon.y() - 10, 20, 20, QColor(240,230,140));

	QPainter p1(this);
	p1.drawPixmap(rect(), canvas);
}

void Client::keyPressEvent(QKeyEvent * e)
{
	int key = e->key();

	if (key == 'W')
	{
		data->socket->write("W");
	}
	else if (key == 'A')
	{
		data->socket->write("A");
	}
	else if (key == 'S')
	{
		data->socket->write("S");
	}
	else if (key == 'D')
	{
		data->socket->write("D");
	}
}

void Client::getMsg()
{
	QByteArray result = data->socket->readAll();
	QByteArrayList list = result.split('+');

	data->team1.setX(list[0].toInt());
	data->team1.setY(list[1].toInt());
	data->hero.setX(list[2].toInt());
	data->hero.setY(list[3].toInt());
	data->blueBuff1.setX(list[4].toInt());
	data->blueBuff1.setY(list[5].toInt());
	data->redBuff1.setX(list[6].toInt());
	data->redBuff1.setY(list[7].toInt());
	data->team2.setX(list[8].toInt());
	data->team2.setY(list[9].toInt());
	data->enemy.setX(list[10].toInt());
	data->enemy.setY(list[11].toInt());
	data->blueBuff2.setX(list[12].toInt());
	data->blueBuff2.setY(list[13].toInt());
	data->redBuff2.setX(list[14].toInt());
	data->redBuff2.setY(list[15].toInt());
	data->Nashor.setX(list[16].toInt());
	data->Nashor.setY(list[17].toInt());
	data->Dragon.setX(list[18].toInt());
	data->Dragon.setY(list[19].toInt());
}
