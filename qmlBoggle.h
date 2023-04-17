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
  int m_cpt;
  QObject *m_label;
  void setter(std::vector<QObject*> *Images,std::vector<QObject*> *LineEdits,QObject *btnSolve,QObject *btnPlay);
  bool isFilled();

public slots:
  void cppSlot(const QString &msg);
  void solveSlot(const QString &msg);
  void playSlot(const QString &msg);
private:
  std::vector<QObject*> *m_lesImages;
  std::vector<QObject*> *m_lesLineEdits;
  QObject *m_btnPlay;
  QObject *m_btnSolve;
  std::vector<QString> m_codes;
};
