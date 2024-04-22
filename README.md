# LiFePO4 UPS

This is a design of an uninterruptible power supply containing LiFePo4 battery cells instead of the commonly used regular LiPo battery cells. It is based around the BYD BM3451 battery management IC.

## Theory of operation

The UPS takes an input voltage of 16V and outputs about 13.3V. 

## Installation

To install the control software onto your Bluepill development board you have to download the Arduino IDE and add the BoardManagerFiles from stm32duino to your list of board manager files. Then install the STM32 MCU based boards package to you via your board manager.
After that simply open bluepill-control sketch, compile it and upload it to your Bluepill development board.