#include "line_tracer.h"

#include <util/Console.h>
#include <util/timer.h>

void LineTracer::run()
{
    int lineFlag = 0;

    this->driveMotor.setSpeed(0, 0);
    this->driveMotor.setOffset(35.0, 40.0);

    while(true){

        if(Console::kbhit()){
            if(getchar() == 'q'){
                break;
            }
        }

        lineFlag = this->lineSensor.getLineState();

        switch(lineFlag){
        case 0b001100: //ど真ん中
            driveMotor.setSpeed(100, 100);
            break;

        case 0b000100: //左よりの場合右へ
            driveMotor.setSpeed(100, 90);
            break;
    
        case 0b000110:
            driveMotor.setSpeed(98, 85);
            break;

        case 0b000010:
            driveMotor.setSpeed(95, 78);
            break;

        case 0b000011:
            driveMotor.setSpeed(85, 60);
            break;

        case 0b000001:
            driveMotor.setSpeed(70, 40);
            break;

        case 0b000111: //右カーブ
            driveMotor.setSpeed(0, 0);
            Timer::waitTime(100);
            driveMotor.setSpeed(40, -50);
            Timer::waitTime(600);
            break;

        case 0b001000: //右寄りの場合左へ
            driveMotor.setSpeed(90, 100);
            break;
    
        case 0b011000:
            driveMotor.setSpeed(85, 98);
            break;

        case 0b010000:
            driveMotor.setSpeed(78, 95);
            break;

        case 0b110000:
            driveMotor.setSpeed(60, 85);
            break;

        case 0b100000:
            driveMotor.setSpeed(40, 70);
            break;

        case 0b111000: //左カーブ
            driveMotor.setSpeed(0, 0);
            Timer::waitTime(100);
            driveMotor.setSpeed(-50, 40);
            Timer::waitTime(600);
            break;

        case 0b001111: //トの字右折
            driveMotor.setSpeed(0, 0);
            Timer::waitTime(100);
            driveMotor.setSpeed(40, -50);
            Timer::waitTime(700);
            break;
/*
        case 0b111111: //T字路右折
            driveMotor.setSpeed(40, -30);
            Timer::waitTime(600);
            break;
*/
        case 0b111100: //逆トの字左折
            driveMotor.setSpeed(0, 0);
            Timer::waitTime(100);
            driveMotor.setSpeed(-50, 40);
            Timer::waitTime(700);
            break;
/*
        case 0b111111: //T字路左折
            driveMotor.setSpeed(-30, 40);
            Timer::waitTime(600);
            break;
*/
        default:
            //driveMotor.setSpeed(50, 50);
            break;
        }
    }
}
