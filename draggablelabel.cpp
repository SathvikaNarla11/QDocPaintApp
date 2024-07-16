#include "draggablelabel.h"
#include <QDebug>

DraggableLabel::DraggableLabel(QWidget *parent)
    : QLabel(parent), m_dragging(false)
{
    setAcceptDrops(true);
}

void DraggableLabel::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasText() && event->mimeData()->text() == "rectangle")
    {
        event->acceptProposedAction();
    }
}

void DraggableLabel::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasText() && event->mimeData()->text() == "rectangle")
    {
        m_rectangle = QRect(event->pos(), QSize(100, 50));
        update(); // Ensure the label updates after dropping
        event->acceptProposedAction();
    }
}

void DraggableLabel::mousePressEvent(QMouseEvent *event)
{
    if (m_rectangle.contains(event->pos()))
    {
        m_dragging = true;
        m_dragStartPos = event->pos() - m_rectangle.topLeft();
    }
}

void DraggableLabel::mouseMoveEvent(QMouseEvent *event)
{
    if (m_dragging)
    {
        m_rectangle.moveTopLeft(event->pos() - m_dragStartPos);
        update(); // Ensure the label updates while moving
    }
}

void DraggableLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);

    if (!m_rectangle.isNull())
    {
        QPainter painter(this);
        painter.setPen(Qt::blue);
        painter.drawRect(m_rectangle);
    }
}
