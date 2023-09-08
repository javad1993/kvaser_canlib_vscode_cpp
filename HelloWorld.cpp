/**
 *******************************************************************************
 * @file    HelloWorld.cpp
 * @authors Javad Dehghan
 * @brief   This project show how to use Kvaser CANlib in Visual Studio Code
 *          https://github.com/javad1993/kvaser_canlib_vscode_cpp
 * @date    Date: 2023
 * @version 1.0.0
 */

#include <stdio.h>
// To use CANlib, we need to include canlib.h and also link to canlib32.lib
// when compiling.
#include "canlib.h"

int main()
{
  // Status returned by the Canlib calls
  canStatus stat;
  // The number of CANlib channel
  int number_of_channels;
  //version of library
  unsigned int version;

  // Initial Library
  canInitializeLibrary();
  version = canGetVersionEx(canVERSION_CANLIB32_PRODVER32);
  printf("%s %d.%d\n", "Found CANLib version", (version & 0xFF0000) >> 16, (version & 0xFF00) >> 8);
	stat = canGetNumberOfChannels(&number_of_channels);
	printf("%s %d %s\n", "Found", number_of_channels, "channels");

  return 0;
}