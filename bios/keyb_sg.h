/*
 * keyb_sg.h - Swiss-German keyboard layout definition
 *
 * Copyright (C) 2005-2020 The EmuTOS development team
 *
 * This file is distributed under the GPL, version 2 or at your
 * option any later version.  See doc/license.txt for details.
 *
 * Adapted from keyb_de.h. aug 2005 RCL
 */

static const UBYTE keytbl_sg_norm[] = {
    0x00, 0x1b,  '1',  '2',  '3',  '4',  '5',  '6',
     '7',  '8',  '9',  '0', '\'',  '^', 0x08, 0x09,
     'q',  'w',  'e',  'r',  't',  'z',  'u',  'i',
     'o',  'p', 0x81, 0xb9, 0x0d, 0x00,  'a',  's',
     'd',  'f',  'g',  'h',  'j',  'k',  'l', 0x94,
    0x84,  '$', 0x00,  '$',  'y',  'x',  'c',  'v',
     'b',  'n',  'm',  ',',  '.',  '-', 0x00, 0x00,
    0x00,  ' ', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00,  '-', 0x00, 0x00, 0x00, '+',  0x00,
    0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     '<', 0x00, 0x00,  '(',  ')',  '/',  '*',  '7',
     '8',  '9',  '4',  '5',  '6',  '1',  '2',  '3',
     '0',  '.', 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

static const UBYTE keytbl_sg_shft[] = {
    0x00, 0x1b,  '+', '\"',  '*', 0x87,  '%',  '&',
     '/',  '(',  ')',  '=',  '?',  '`', 0x08, 0x09,
     'Q',  'W',  'E',  'R',  'T',  'Z',  'U',  'I',
     'O',  'P', 0x8a,  '!', 0x0d, 0x00,  'A',  'S',
     'D',  'F',  'G',  'H',  'J',  'K',  'L', 0x82,
    0x85, 0x9c, 0x00, 0x9c,  'Y',  'X',  'C',  'V',
     'B',  'N',  'M',  ';',  ':',  '_', 0x00, 0x00,
    0x00,  ' ', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  '7',
     '8', 0x00,  '-',  '4', 0x00,  '6',  '+', 0x00,
     '2', 0x00,  '0', 0x7f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     '>', 0x00, 0x00,  '(',  ')',  '/',  '*',  '7',
     '8',  '9',  '4',  '5',  '6',  '1',  '2',  '3',
     '0',  '.', 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

static const UBYTE keytbl_sg_caps[] = {
    0x00, 0x1b,  '1',  '2',  '3',  '4',  '5',  '6',
     '7',  '8',  '9',  '0', '\'',  '^', 0x08, 0x09,
     'Q',  'W',  'E',  'R',  'T',  'Z',  'U',  'I',
     'O',  'P', 0x81, 0xb9, 0x0d, 0x00,  'A',  'S',
     'D',  'F',  'G',  'H',  'J',  'K',  'L', 0x94,
    0x84,  '$', 0x00,  '#',  'Y',  'X',  'C',  'V',
     'B',  'N',  'M',  ',',  '.',  '-', 0x00, 0x00,
    0x00,  ' ', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00,  '-', 0x00, 0x00, 0x00, '+',  0x00,
    0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     '#', 0x00, 0x00,  '(',  ')',  '/',  '*',  '7',
     '8',  '9',  '4',  '5',  '6',  '1',  '2',  '3',
     '0',  '.', 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};


static const UBYTE keytbl_sg_altnorm[] = {
    0x02, '|',          /* ST_1 */
    0x03, '@',          /* ST_2 */
    0x04, '#',          /* ST_3 */
    0x0d, '~',          /* ST_EQUAL */
    0x1a, '[',          /* ST_SQ-CLOSE */
    0x1b, ']',          /* ST_SQ_OPEN */
    0x28, '{',          /* ST_APOST */
    0x29, '}',          /* ST_GRAVE */
    0x2b, '\\',         /* ST_BACKSL */
    0x60, '\\',         /* ST_ISO */
    0,
};

static const UBYTE keytbl_sg_altshft[] = {
    0x1a, '{',
    0x1b, '}',
    0,
};

static const UBYTE keytbl_sg_altcaps[] = {
    0,
};

static const struct keytbl keytbl_sg = {
    keytbl_sg_norm,
    keytbl_sg_shft,
    keytbl_sg_caps,
    keytbl_sg_altnorm,
    keytbl_sg_altshft,
    keytbl_sg_altcaps,
    NULL,
    0
};