#include "arduino.h"
#include <QThread>
arduino::arduino()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}
QString arduino::getarduino_port_name()
{
    return arduino_port_name;
}
QSerialPort * arduino::getserial()
{return serial;}
int arduino::connect_arduino()
{

    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier()==
arduino_uno_producy_id)
{
arduino_is_available = true;
arduino_port_name=serial_port_info.portName();
}
}
    }
qDebug()<< "arduino_port_name is :" << arduino_port_name;
if(arduino_is_available){ // configuration de la communication ( débit...)
serial->setPortName(arduino_port_name);
if(serial->open(QSerialPort::ReadWrite))
{
serial->setBaudRate(QSerialPort::Baud9600); // débit : 9600 bits/s
serial->setDataBits(QSerialPort::Data8); //Longueur des données : 8 bits,
serial->setParity(QSerialPort::NoParity); //1 bit de parité optionnel
serial->setStopBits(QSerialPort::OneStop); //Nombre de bits de stop :l
serial->setFlowControl(QSerialPort::NoFlowControl);
return 0;
}

return 1;
}
return -1;
}
int arduino::close_arduino()
{
    if(serial->isOpen())
    {
        serial->close();
        return 0;
    }
    return 1;
}
//eya
QString arduino::read_from_arduino()
{
    static QByteArray buffer; // Buffer to accumulate data
    QString message;

    if (serial->isReadable()) {
        QByteArray data = serial->readAll();
        buffer.append(data); // Append new data to the buffer

        // Check for a complete message (ends with '\n')
        int endOfMessage = buffer.indexOf('\n');
        if (endOfMessage != -1) {
            // Extract the complete message (up to '\n')
            QByteArray completeMessage = buffer.left(endOfMessage);
            buffer.remove(0, endOfMessage + 1); // Remove processed data from the buffer

            message = QString::fromUtf8(completeMessage).simplified(); // Convert to QString and clean up
        }
    }

    return message; // Return the complete message or an empty string if no complete message is available
}
//aymen
int arduino::write_to_arduino( QByteArray d)

{

    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers Arduino
    }else{
        qDebug() << "Couldn't write to serial!";
    }

}
