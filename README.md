# LiFePO4 UPS

This is a design of an uninterruptible power supply containing LiFePo4 battery cells instead of the commonly used regular LiPo battery cells. It is based around the BYD BM3451 battery management IC.

## Theory of operation

The UPS takes an input voltage of 16V and outputs about 13.3V.
When connected to power, the charging current to the BYD BM3451 gets limited by the current limiting ciruit created with the transistors Q1 and Q2.
Two TI INA169 are used to measure the current into and out of the battery. And the charging level of the battery gets calulated by the integral of the diference of both measurements.
Th Diode D1 prevents the power supply from directly charging the battery cells.
The Transistor Q3 gets used to cut off the power from the load, in case the charging level of the battery falls below a predefined threshold.

## Installation

To install the control software onto your Bluepill development board you have to download the Arduino IDE and add the BoardManagerFiles from stm32duino to your list of board manager files. Then install the STM32 MCU based boards package to you via your board manager.
After that simply open bluepill-control sketch, compile it and upload it to your Bluepill development board.