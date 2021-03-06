#include "window.h"
#include "mcp3008Spi.h"
#include "ADCreader.h"

#include <cmath>  // for sine stuff

extern float read();

Window::Window() 
{


	// set up the thermometer
	thermo = new QwtThermo; 
	thermo->setFillBrush( QBrush(Qt::red) );
	thermo->setRange(0, 50);
	thermo->show();


	// set up the initial plot data
	for( int index=0; index<plotDataSize; ++index )
	{
		xData[index] = index;
		yData1[index] = 0;
	}

	curve = new QwtPlotCurve;
	plot = new QwtPlot;
	// make a plot curve from the data and attach it to the plot
	curve->setSamples(xData, yData1, plotDataSize);
	curve->attach(plot);

	plot->replot();
	plot->show();


	// set up the layout - knob above thermometer
	vLayout = new QVBoxLayout;
	vLayout->addWidget(thermo);

	// plot to the left of knob and thermometer
	hLayout = new QHBoxLayout;
	hLayout->addLayout(vLayout);
	hLayout->addWidget(plot);

	setLayout(hLayout);

	// This is a demo for a thread which can be
	// used to read from the ADC asynchronously.
	// At the moment it doesn't do anything else than
	// running in an endless loop and which prints out "tick"
	// every second.
	adcreader = new ADCreader();
	adcreader->start();
}

Window::~Window() {

}
void Window::timerEvent( QTimerEvent * )
{
       float inVal1 = adcreader ->Data1();

        memmove( yData1, yData1+1, (plotDataSize-1) * sizeof(double) );

        yData1[plotDataSize-1] = inVal1;

        curve->setSamples(xData, yData1, plotDataSize);

        plot->replot();
        
        thermo->setValue( inVal1 );

} 


