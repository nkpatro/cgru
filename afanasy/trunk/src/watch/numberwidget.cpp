#include "numberwidget.h"

#include <QtGui/QLayout>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>

#include "../libafqt/attrnumber.h"

#include "watch.h"

NumberWidget::NumberWidget( QWidget * parent, afqt::AttrNumber * attrNumber):
      QWidget( parent),
      num( attrNumber)
{
   QHBoxLayout * layout = new QHBoxLayout(this);
#if QT_VERSION >= 0x040300
   layout->setContentsMargins( 1, 1, 1, 1);
#endif
   layout->setSpacing( 2);
   QLabel * label = new QLabel( attrNumber->getLabel(), this);
   QSpinBox * spinbox = new QSpinBox( this);
   spinbox->setValue( attrNumber->n);
   spinbox->setMinimum( 1);
   connect( spinbox, SIGNAL( valueChanged( int)), this, SLOT( valueChanged(int)));

   layout->addWidget( label);
   layout->addWidget( spinbox);
}

NumberWidget::~NumberWidget()
{
}

void NumberWidget::valueChanged( int value)
{
   num->n = value;
   Watch::repaintStart();
}
