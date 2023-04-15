#include <QtQuick>
#include <QGuiApplication>
#include <QQmlComponent>
#include <QQmlEngine>

#include <stdio.h>

#include "qmlBoggle.h"

laClasse::laClasse(){m_cpt=0;}
laClasse::laClasse(QObject *o){m_cpt=0;m_label = o;}
laClasse::~laClasse(){}
void laClasse::incr(){m_cpt++;}
void laClasse::cppSlot(const QString &msg)
{
  fprintf(stderr,"called the C++ slot with message: %s",msg.toStdString().c_str());
  m_label->setProperty("text",QString::number(m_cpt++));
  //fprintf(stderr,"called the C++ slot with message");
}    // FIN void laClasse::cppSlot(const QString &msg)
// *************************************************************************************

int main (int argc,char *argv[])
{
  QGuiApplication app(argc,argv);
  QQuickView view;
  view.setSource(QUrl("qmlBoggle.qml"));
  view.show();
  QObject *root = view.rootObject();
  std::vector<QObject*> lesChamps;
 
  for (uint i=0;i<4*4;i++)
    {
      QString name="image"+QString::number(i/4)+QString::number(i%4);
      fprintf(stderr,"%s\n",name.toStdString().c_str());
      QObject *aux = root->findChild<QObject*>(name);
      if (aux==NULL)
	exit(1);
      lesChamps.push_back(aux);
    }
   for(uint i=0;i<4*4;i++)
    {
      QObject *aux = lesChamps[i];
      auto src = aux->property("source");
      std::string source = src.toString().toStdString();
      fprintf(stderr,"Il y avait %s\n",(char*)source.c_str());
      // chgt
      src = ":resources/A0.png";
      src = "file:///mnt/diskc/1/dauriac/games/qtBoggle/qml/qmlBoggle/resources/A0.png";
      bool ok = aux->setProperty("source",src);
      if (!ok)
	exit(3);
      src = aux->property("source");
      source = src.toString().toStdString();
      fprintf(stderr,"Il y a maintenant %s\n",(char*)source.c_str());
    }
  
  /*
  QObject *label = root->findChild<QObject*>("labelle");
  QObject *button = root->findChild<QObject*>("bouton");
  laClasse lc(label); 
  if ((!label) || (!button))
    {
      fprintf(stderr,"oops label ou bouton est nul \n!");
      exit(0);
    }
  bool ok = label->setProperty("text","Change depuis cpp");
  if (!ok)
    {
      fprintf(stderr,"oops pas pu setProperty\n");
      exit(1);
    }
  QObject::connect(button,SIGNAL(qmlSignal(QString)),&lc, SLOT(cppSlot(QString)));
  */
  return app.exec();
 
}

/*
  https://doc.qt.io/qt-6/qtqml-cppintegration-interactqmlfromcpp.html
*/
