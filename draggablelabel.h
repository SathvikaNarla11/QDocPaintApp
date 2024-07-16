#ifndef DRAGGABLELABEL_H
#define DRAGGABLELABEL_H

#include <QLabel>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QMimeData>

class DraggableLabel : public QLabel
{
    Q_OBJECT

public:
    DraggableLabel(QWidget *parent = nullptr);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    QRect m_rectangle;
    bool m_dragging;
    QPoint m_dragStartPos;
};

#endif // DRAGGABLELABEL_H

