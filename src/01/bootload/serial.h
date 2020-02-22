#ifndef _SERIAL_H_INCLUDED_
#define _SERIAL_H_INCLUDED_

int serial_init(int index); // initiate device
int serial_is_send_enable(int index); // check if sending can be done or not
int serial_send_byte(int index, unsigned char b); //1 character send

#endif
