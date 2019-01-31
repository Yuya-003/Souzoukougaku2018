#include <BlackGPIO/BlackGPIO.h>

#include <util/Timer.h>
#include <util/Console.h>

#include <iostream>


int main()
{
	//BlackLib::BlackGPIO sensor(BlackLib::GPIO_47, BlackLib::input);
	BlackLib::BlackGPIO sensor(BlackLib::GPIO_45, BlackLib::input);
	
	Timer timer;

	std::cout << "   Ultrasonic Sensor Test   " << std::endl;
	double distance = 0;
	while(true){

		if(Console::kbhit()){
			if(getchar() == 'q'){
				break;
			}
		}

		while(sensor.isHigh());
		while(!sensor.isHigh());
		timer.start();
		while(sensor.isHigh());
		timer.stop();

		distance = 340.0 * 100 * timer.getElapsedTime() * 1E-9 / 2;
		std::cout << "distance : " << distance << "[cm]" << std::endl;
		Timer::waitTime(1000);
	}

	return 0;
}


/*
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <poll.h>
#include <time.h>

void gpio_export(int n){
	int fd;
	char buf[40];
	
	sprintf(buf,"%d",n);

	fd=open("/sys/class/gpio/export",O_WRONLY);
	write(fd,buf,strlen(buf));
	close(fd);
}

void gpio_unexport(int n){
	int  fd;
	char buf[40];

	sprintf(buf,"%d",n);

	fd=open("/sys/class/gpio/unexport",O_WRONLY);
	write(fd,buf,strlen(buf));
	close(fd);
}

int gpio_open(int n,char *file,int flag){
	int fd;
	char buf[40];

	sprintf(buf, "/sys/class/gpio/gpio%d/%s", n, file);

	fd = open(buf, flag);
	return fd;
}

double convToDistance(int time){
	return 0.1679*time;
}

#define RC_LAP(n, o) \
  ((n.tv_sec - o.tv_sec) * 1000000 + \
  (n.tv_nsec - o.tv_nsec) / 1000)

int main()
{
	int fd;
	int Ion;
	int gpio_number = 30;
	int ret, i;
	char c;
	struct timespec origin;
	struct timespec now;
	struct pollfd pfd;

	gpio_export(gpio_number);

	fd = gpio_open(gpio_number, "direction", O_WRONLY);
	write(fd, "in", 2);
	close(fd);

	fd = gpio_open(gpio_number, "edge", O_WRONLY);
	write(fd, "both", 4);
	close(fd);

	fd=gpio_open(gpio_number,"value",O_RDONLY);

	pfd.fd=fd;
	pfd.events=POLLPRI;

	while(1){
		lseek(fd,0,SEEK_SET);
		ret=poll(&pfd,1,-1);
		read(fd,&c,1);
		if(c=='1'){
			clock_gettime(CLOCK_MONOTONIC_RAW,&origin);
		}
		else continue;

		lseek(fd,0,SEEK_SET);
		ret=poll(&pfd,1,-1);
		read(fd,&c,1);
		if(c=='0'){
			clock_gettime(CLOCK_MONOTONIC_RAW,&now);
		}
		else continue;

		Ion=RC_LAP(now,origin);
		printf("distance=%lf[mm]\n",convToDistance(Ion));
		usleep(500000);
	}

	close(fd);

	gpio_unexport(gpio_number);

	return 0;
}
*/
