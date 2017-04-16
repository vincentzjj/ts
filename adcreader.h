/*
  MCP3008.h - Library for communicating with MCP3008 Analog to digital converter.
  Created by Uros Petrevski, Nodesign.net 2013
  Released into the public domain.
  
  ported from Python code originaly written by Adafruit learning system for rPI :
  http://learn.adafruit.com/send-raspberry-pi-data-to-cosm/python-script
*/

#ifndef adcreader_h
#define adcreader_h

#include "Arduino.h"

#include <QThread>

class ADCreader : public QThread

class adcreader
{
  public:
    adcreader(int clockpin, int mosipin, int misopin, int cspin);
    int readADC(int adcnum);
  private:
      int _clockpin, _mosipin, _misopin, _cspin;
};


#endif
