#include "Motors.h"

// Motors::Motors() {}

Motors::Motors(int A1, int A2, int B1, int B2, int C1, int C2) 
{
    Omni3 = true;
    Omni4 = false;
    MotorLeft1 = A1;
    MotorLeft2 = A2;
    MotorRight1 = B1;
    MotorRight2 = B2;
    MotorBack1 = C1;
    MotorBack2 = C2;

}

Motors::Motors(int A1, int A2, int B1, int B2, int C1, int C2, int D1, int D2)
{
    Omni3 = false;
    Omni4 = true;
    MotorLeftF1 = A1;
    MotorLeftF2 = A2;
    MotorRightF1 = B1;
    MotorRightF2 = B2;
    MotorRightB1 = C1; 
    MotorRightB2 = C2;
    MotorLeftB1 = D1;
    MotorLeftB2 = D2;
} 

void Motors::InitializeMotors()
{
    if(Omni3){
        pinMode(MotorLeft1, OUTPUT);
        pinMode(MotorLeft2, OUTPUT);
        pinMode(MotorRight1, OUTPUT);
        pinMode(MotorRight2, OUTPUT);
        pinMode(MotorBack1, OUTPUT);
        pinMode(MotorBack2, OUTPUT);
    }
    else if (Omni4){
        pinMode(MotorLeftF1, OUTPUT);
        pinMode(MotorLeftF2, OUTPUT);
        pinMode(MotorRightF1, OUTPUT);
        pinMode(MotorRightF2, OUTPUT);
        pinMode(MotorRightB1, OUTPUT);
        pinMode(MotorRightB2, OUTPUT);
        pinMode(MotorLeftB1, OUTPUT);
        pinMode(MotorLeftB2, OUTPUT);
    }
}

void Motors::turnLeft(int speed)
{
    if(Omni3){
        analogWrite(MotorLeft1, speed);
        analogWrite(MotorLeft2, 0);
        analogWrite(MotorRight1, speed);
        analogWrite(MotorRight2, 0);
        analogWrite(MotorBack1, speed);
        analogWrite(MotorBack2, 0);
    }
    else if (Omni4){
        analogWrite(MotorLeftF1, speed);
        analogWrite(MotorLeftF2, 0);
        analogWrite(MotorRightF1, speed);
        analogWrite(MotorRightF2, 0);
        analogWrite(MotorRightB1, speed);
        analogWrite(MotorRightB2, 0);
        analogWrite(MotorLeftB1, speed);
        analogWrite(MotorLeftB2, 0);
    }
}

void Motors::turnRight(int speed)
{
    if(Omni3){
        analogWrite(MotorLeft1, 0);
        analogWrite(MotorLeft2, speed);
        analogWrite(MotorRight1, 0);
        analogWrite(MotorRight2, speed);
        analogWrite(MotorBack1, 0);
        analogWrite(MotorBack2, speed);
    }
    else if (Omni4){
        analogWrite(MotorLeftF1, 0);
        analogWrite(MotorLeftF2, speed);
        analogWrite(MotorRightF1, 0);
        analogWrite(MotorRightF2, speed);
        analogWrite(MotorRightB1, 0);
        analogWrite(MotorRightB2, speed);
        analogWrite(MotorLeftB1, 0);
        analogWrite(MotorLeftB2, speed); 
    }
}

void Motors::stopMotors()
{
    if(Omni3){
        analogWrite(MotorLeft1, 0);
        analogWrite(MotorLeft2, 0);
        analogWrite(MotorRight1, 0);
        analogWrite(MotorRight2, 0);
        analogWrite(MotorBack1, 0);
        analogWrite(MotorBack2, 0);
    }
    else if(Omni4){
        analogWrite(MotorLeftF1, 0);
        analogWrite(MotorLeftF2, 0);
        analogWrite(MotorRightF1, 0);
        analogWrite(MotorRightF2, 0);
        analogWrite(MotorRightB1, 0);
        analogWrite(MotorRightB2, 0);
        analogWrite(MotorLeftB1, 0);
        analogWrite(MotorLeftB2, 0);
    }
}

void Motors::moveMotors(int degree, int speed)
{
    if(Omni3){
        float m1 = cos(((150-degree) * M_PI / 180));
        float m2 = cos(((30-degree) * M_PI / 180));;
        float m3 = cos(((270-degree) * M_PI / 180));
        int speedA = int(m1*speed);
        int speedB = int(m2*speed);
        int speedC = int(m3*speed);
        
        if (m1 >= 0){
            analogWrite(MotorLeft1, speedA);
            analogWrite(MotorLeft2, 0);
        }
        else {
            analogWrite(MotorLeft1, 0);
            analogWrite(MotorLeft2, -speedA);
        }
        if (m2 >= 0){
            analogWrite(MotorRight1, speedB);
            analogWrite(MotorRight2, 0);
        }
        else {
            analogWrite(MotorRight1, 0);
            analogWrite(MotorRight2, -speedB);
        }
        if (m3 >= 0){
            analogWrite(MotorRightB1, speedC);
            analogWrite(MotorRightB2, 0);
        }
        else {
            analogWrite(MotorRightB1, 0);
            analogWrite(MotorRightB2, -speedC);
        }
    }
    else if(Omni4){
        float m1 = -cos(((45-degree) * M_PI / 180));
        float m2 = -cos(((135-degree) * M_PI / 180));
        float m3 = -cos(((225-degree) * M_PI / 180));
        float m4 = -cos(((315-degree) * M_PI / 180));
        int speedA = int(m1*speed);
        int speedB = int(m2*speed);
        int speedC = int(m3*speed);
        int speedD = int(m4*speed);

        if (m1 >= 0){
            analogWrite(MotorLeftF1, speedA);
            analogWrite(MotorLeftF2, 0);
        }
        else {
            analogWrite(MotorLeftF1, 0);
            analogWrite(MotorLeftF2, -speedA);
        }
        if (m2 >= 0){
            analogWrite(MotorRightF1, speedB);
            analogWrite(MotorRightF2, 0);
        }
        else {
            analogWrite(MotorRightF1, 0);
            analogWrite(MotorRightF2, -speedB);
        }
        if (m3 >= 0){
            analogWrite(MotorBack1, speedC);
            analogWrite(MotorBack2, 0);
        }
        else {
            analogWrite(MotorBack1, 0);
            analogWrite(MotorBack2, -speedC);
        }
        if (m4 >= 0){
            analogWrite(MotorLeftB1, speedD);
            analogWrite(MotorLeftB2, 0);
        }
        else {
            analogWrite(MotorLeftB1, 0);
            analogWrite(MotorLeftB2, -speedD);
        }
    }
}