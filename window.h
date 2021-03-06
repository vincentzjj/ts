#ifndef WINDOW_H
#define WINDOW_H

#include <qwt/qwt_thermo.h>
#include <qwt/qwt_knob.h>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>

#include <QBoxLayout>

#include "mcp3008Spi.h"
#include "ADCreader.h"
// class definition 'Window'
class Window : public QWidget
{
	// must include the Q_OBJECT macro for for the Qt signals/slots framework to work with this class
	Q_OBJECT

public:
	Window(); // default constructor - called when a Window is declared without arguments

	~Window();

	void timerEvent( QTimerEvent * );



// internal variables for the window class
private:
	QwtKnob      *knob;
	QwtThermo    *thermo;
	QwtPlot      *plot;
	QwtPlotCurve *curve;

	// layout elements from Qt itself http://qt-project.org/doc/qt-4.8/classes.html
	QVBoxLayout  *vLayout;  // vertical layout
	QHBoxLayout  *hLayout;  // horizontal layout

	static const int plotDataSize = 100;

	// data arrays for the plot
	double xData[plotDataSize];
	double yData0[plotDataSize];
	double yData1[plotDataSize];

	
int normtemp;
        int moistlev;
ADCreader *adcreader;
	
};

#endif // WINDOW_H
