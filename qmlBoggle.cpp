#include <QtQuick>
#include <QGuiApplication>
#include <QQmlComponent>
#include <QQmlEngine>

#include <stdio.h>

#include "qmlBoggle.h"
#include "libBoggle.h"

#define SETPROPERTY(o,l,v) {if (!(o->setProperty(l,v))) {fprintf(stderr,#l);exit(-1);};}
#define STOP(a) {fprintf(stderr,a);exit(-1);}

laClasse::laClasse()
{
  m_cpt=0;
  for(uint i=0;i<4*4;i++)
    m_codes.push_back("_");
}     // FIN laClasse::laClasse()
// *****************************************************************************

laClasse::laClasse(QObject *o)
{
  m_cpt=0;
  m_label = o;
}     // FIN laClasse::laClasse()
// *****************************************************************************

laClasse::~laClasse()
{
}     // FIN laClasse::laClasse()
// *****************************************************************************

void laClasse::setter(std::vector<QObject*> *Images,std::vector<QObject*> *LineEdits,QObject *btnPlay,QObject *btnSolve)
{
  m_lesImages = Images;
  m_lesLineEdits = LineEdits;
  m_btnPlay = btnPlay;
  m_btnSolve = btnSolve;
}     // FIN void laClasse::setter((std::vector<QObject*> *Images,std::vector<QObject*> *LineEdits)
// *****************************************************************************

bool laClasse::isFilled()
{
  for (uint i=0;i<4*4;i++)
    {
      if (m_codes[i]=="_")
	 return false;
    }
  return true;
}     // FIN bool laClasse::isFilled()
// *****************************************************************************

void laClasse::cppSlot(const QString &msg)
{
  int k = msg.toInt();
  QObject *aux = (*m_lesLineEdits)[k];
  auto val = aux->property("text");
  QString valQString = val.toString().toUpper();
  m_codes[k] = valQString;
  SETPROPERTY(aux,"text",valQString);
  if (isFilled())
    {
      fprintf(stderr," PLAIN\n");
    }
  if (k<15)
    {
      QObject *aux = (*m_lesLineEdits)[k+1];
      SETPROPERTY(aux,"focus",true);
    }
}    // FIN void laClasse::cppSlot(const QString &msg)
// *************************************************************************************

void laClasse::solveSlot(const QString &msg)
{
  fprintf(stderr,"solveSlot called the C++ slot with message: %s\n",msg.toStdString().c_str());
  QObject *aux = (*m_lesLineEdits)[2];
  SETPROPERTY(aux,"focus",true);
}    // FIN void laClasse::solveSlot(const QString &msg)
// *************************************************************************************

void laClasse::playSlot(const QString &msg)
{
  fprintf(stderr,"playSlot called the C++ slot with message: %s\n",msg.toStdString().c_str());
}    // FIN void laClasse::solveSlot(const QString &msg)
// *************************************************************************************

int main (int argc,char *argv[])
{
  QGuiApplication app(argc,argv);
  laClasse lc;
  QQuickView view;
  view.setSource(QUrl("qmlBoggle.qml"));
  view.show();
  QObject *root = view.rootObject();
  std::vector<QObject*> lesImages;
  std::vector<QObject*> lesLineEdits;
  
  // CREATION DES HANDLES VERS LES OBJETS QML
  QObject *btnSolve = root->findChild<QObject*>("solve");
  if (btnSolve==NULL)
    STOP("btnSolve est nul\n");
  QObject *btnPlay = root->findChild<QObject*>("play");
  if (btnPlay==NULL)
    STOP("btnPly est nul\n");
  lc.setter(&lesImages,&lesLineEdits,btnSolve,btnPlay);

  for (uint i=0;i<4*4;i++)
    {
      QString name="image"+QString::number(i/4)+QString::number(i%4);
      QObject *aux = root->findChild<QObject*>(name);
      if (aux==NULL)
	exit(1);
      name = "text"+QString::number(i/4)+QString::number(i%4);
      QObject *bux = root->findChild<QObject*>(name);
      if (bux==NULL)
	exit(1);
      lesImages.push_back(aux);
      lesLineEdits.push_back(bux);
    }
  // POSITIONNEMENT DES OBJETS
  int LX=50,LY=50,spacer=1;
  for(uint i=0;i<4*4;i++)
    {
      QObject *aux = lesImages[i];
      QObject *bux = lesLineEdits[i];
      uint x = i/4;uint y = i%4;
      SETPROPERTY(aux,"x",x*(LX+spacer));
      SETPROPERTY(aux,"y",y*(LY+spacer));
      SETPROPERTY(aux,"width",LX);
      SETPROPERTY(aux,"height",LY);
      SETPROPERTY(bux,"x",x*(LX+spacer));
      SETPROPERTY(bux,"y",y*(LY+spacer));
      SETPROPERTY(bux,"width",LX);
      SETPROPERTY(bux,"height",LY);
      QString src = "file:///mnt/diskc/1/dauriac/games/qtBoggle/qml/qmlBoggle/resources/_0.png";
      SETPROPERTY(aux,"source",src);
      SETPROPERTY(bux,"text","");
      QObject::connect(bux,SIGNAL(qmlSignal(QString)),&lc, SLOT(cppSlot(QString)));
    }
  QObject::connect(btnPlay,SIGNAL(qmlSignal(QString)),&lc, SLOT(playSlot(QString)));
  QObject::connect(btnSolve,SIGNAL(qmlSignal(QString)),&lc, SLOT(solveSlot(QString)));
  /*   
      for (const char *p : {"x","y","width","height"})
	if (!bux->setProperty(p,aux->property(p)))
	  exit(5);
   QObject *auxI = root->findChild<QObject*>("text00");
   if (auxI==NULL)
     STOP("auxI");
   auxI->setProperty("focus",true);
   auxI->setProperty("visible",true);
   lesChamps[0]->setProperty("visible",true);
   //   boggleSolver* bs;

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
