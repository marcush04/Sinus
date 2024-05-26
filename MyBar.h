#include <QProgressBar>
#include <QTimer>

class MyBar : public QProgressBar {
    Q_OBJECT;

    public:
        MyBar (QWidget *parent);
        int valor;
        float amplitud;
        float fase;
        bool rellotge;
        int w;
        QTimer timer;

    public slots:
        void inici();
        void amplitudchange(int n);
        void fasechange(int n);
        void animacio();
        void tictac();
};