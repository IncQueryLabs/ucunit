/*****************************************************************************
 *                                                                           *
 *  uCUnit - A unit testing framework for microcontrollers                   *
 *                                                                           *
 *  (C) 2007 - 2008 Sven Stefan Krauss                                       *
 *                  https://www.ucunit.org                                   *
 *  (C) 2020 - 2021 Balint Huszar - IncQuery Labs cPlc.                      *
 *  (C) 2020 - 2021 Zoltan Selmeczi - IncQuery Labs cPlc.                    *
 *                                                                           *
 *  File        : System.c                                                   *
 *  Description : System dependent functions used by uCUnit.                 *
 *                This file has to be customized for your hardware.          *
 *  Author      : Sven Stefan Krauss, Zoltan Selmeczi, Balint Huszar         *
 *  Contact     : www.ucunit.org                                             *
 *                                                                           *
 *****************************************************************************/

/*
 * This file is part of ucUnit.
 *
 * You can redistribute and/or modify it under the terms of the
 * Common Public License as published by IBM Corporation; either
 * version 1.0 of the License, or (at your option) any later version.
 *
 * uCUnit is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * Common Public License for more details.
 *
 * You should have received a copy of the Common Public License
 * along with uCUnit.
 *
 * It may also be available at the following URL:
 *       http://www.opensource.org/licenses/cpl1.0.txt
 *
 * If you cannot obtain a copy of the License, please contact the
 * author.
 */

#include <stdio.h>
#include <stdlib.h>
#include "../System.h"
#include "../uCUnit-xml.h"
#include "../uCUnit-v1.0.h"

#ifdef UCUNIT_MODE_XML
static void System_WriteXMLStringToFile(char *xmlString)
{
    char filename[MAX_PATH] = { 0 };

    GetModuleFileNameA(NULL, filename, MAX_PATH);
    char outputfile[strlen(filename) + 1];
    memset(outputfile, 0, sizeof(outputfile));
    strncat(outputfile, filename, strlen(filename) - 3);
    strcat(outputfile, "xml");

    FILE *fp;

    fp = fopen(outputfile, "w+");
    fprintf(fp, xmlString);
    fclose(fp);
}
#endif

/* Stub: Initialize your hardware here */
void System_Init(void)
{

    printf("Init of hardware finished.\n");
}

/* Stub: Shutdown your hardware here */
void System_Shutdown(void)
{

    /* asm("\tSTOP"); */
#ifdef UCUNIT_MODE_XML
    size_t bufferSize = 0;
    UCUNIT_XML_GetSizeOfTestsuite(&bufferSize);
    char buffer[bufferSize];
    memset(buffer, 0, sizeof(buffer));
    UCUNIT_XML_GetXmlObject(buffer);
    printf(buffer);
    System_WriteXMLStringToFile(buffer);
#endif
    printf("System shutdown.\n");
    //exit(0);
}

/* Stub: Recover your system from a safe state. */
void System_Recover(void)
{
    /* Stub: Recover the hardware */
    /* asm("\tRESET"); */
    printf("System recover.\n");
    exit(0);
}

/* Stub: Put system in a safe state */
void System_Safestate(void)
{
    /* Disable all port pins */
    /* PORTA = 0x0000; */
    /* PORTB = 0x0000; */
    /* PORTC = 0x0000; */

    /* Disable interrupts */
    /* DIE(); */

    /* Put processor into idle state */
    /* asm("\tIDLE"); */
    printf("System safe state.\n");
    exit(0);
}

/* Stub: Write a string to the host/debugger/simulator */
void System_WriteString(char *msg)
{
    printf(msg);
}

void System_WriteInt(int n)
{
    printf("%i", n);
}
