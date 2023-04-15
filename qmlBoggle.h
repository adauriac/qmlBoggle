#include <QObject>

class laClasse : public QObject
{
  Q_OBJECT  // compile si cette ligne est commentee mais pb execution
  //   Q_PROPERTY(int m_cpt READ m_cpt WRITE setCounter NOTIFY incr) // this makes counter available as a QML property
  // QML_ELEMENT
public:
  laClasse();
  laClasse(QObject* label);
  ~laClasse();
  void setCounter(int a);
  void incr();
  int m_cpt;
  QObject *m_label;
public slots:
  void cppSlot(const QString &msg);

};
