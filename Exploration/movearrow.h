#ifndef MOVEARROW_H
#define MOVEARROW_H
#include <QObject>
#include <QPushButton>

class MoveArrow : public QObject, public QPushButton
{
public:
    MoveArrow();
};

#endif // MOVEARROW_H
