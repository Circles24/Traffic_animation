/*

			Computer Graphics lab mini project --- animation with mouse and keyboard interaction



			this program uses mutiple ways to interact with you such as mouse and keyboard

			upon reaching the traffic light either by mouse select the light or else enter 

			the color to be chosen or else enter the -> key


*/


/*********************************  Headers  ***************************************/

// thes are important header files necessary for this code to run properly

#include <iostream> 
#include <GL/glut.h>
#include <vector>
#include <string>
#include <math.h>


/*********************************   Maros    ***************************************/

using namespace std;  //using standard namespace 


// defining some of our own macros to shorten some of the code

#define pb push_back
#define mp make_pair
#define F first 
#define S second

/******************************* universal varibales **********************************/

int offset;              // offset of car ie x coordinate distance of car

int mouse_x1,mouse_x2,mouse_y1,mouse_y2; // some of variables for use in mouse()

float light_x,light_y;  // these are co-ordinates for the traffic light

float window_width,window_height; // just same as name

bool show_light , light_done ;  // boolean necessary for traffic light functionality

string keyborad_choice;     // string which records keyboard input

vector <pair<float,float> >  car_points;   // this vector stores border points of the car


/*******************************  utility func **********************************/


void init_para(){

	cout<<"@ init_para() "<<endl;

	offset = -200;  // initial offset is negative for entrace effect

	show_light = false;  

	window_width = 1600.00; // win size

	window_height = 800.00; // win size

	light_x = 1275;  

	light_y = 700;

	light_done = false;

	keyborad_choice = "";

	glutInitWindowSize(window_width,window_height); //initializing the window size

	glutInitWindowPosition(0,0);                     //initializing the window posiiton

	// all the boundry points of the car
	car_points.pb(mp(10,20));      // 1st point
	car_points.pb(mp(175,20));     // 2nd point
	car_points.pb(mp(175,30));     // 3rd point
	car_points.pb(mp(170,45));     // 4th point
	car_points.pb(mp(150,55));     // 5th point
	car_points.pb(mp(95,70));      // 6th point
	car_points.pb(mp(40,70));      // 7th point 
	car_points.pb(mp(15,50));      // 8th point
	car_points.pb(mp(10,36));      // 9th point
}

void init(){

	// first function to be called after creating window

	cout<<"@ init() "<<endl;
	
	glClearColor(1.0, 1.0, 1.0, 0.0);		 // clear the color
	glPointSize(1.0f);				 		// resize the points 
	gluOrtho2D(0.0f, window_width, 0.0f, window_height); // set the current ortho

	
}
void GoMenu(int value)
{

	if(value == 4 )exit(0);

	if( show_light == false || light_done )return ;

	switch(value)
	{
		case 1: break;

		case 2:  {
				system("sleep 2");

				light_done = true;
				
				break;	

			}

		case 3: light_done=true;break;

		case 4:exit(0);
	}
}
void do_animation(void){

	// our ideal function it does offset computation and logical reason

	if( offset == light_x-200 && light_done == false )show_light = true; // case when car arrived at traffic light

	else offset++;  // just some regular case

	if( offset > 1600 )exit(0);  // car exits the scene

	glutPostRedisplay();  // call to update the display

}
void road()// function to draw the road
{
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2i(0,0);
	glVertex2i(0,50);
	glVertex2i(2000,50);
	glVertex2i(2000,0);
	glEnd();
}
void draw_car(){

	// our function which draws the car on the buffer

	// drawing the car
	glBegin(GL_POLYGON);    
    
    glColor3f(0.7f,0.1f,0.1f);   // setting the orange color
   	for(auto i:car_points)
	{	
		glVertex2i(i.F+offset,i.S); // it iteratesover the vector and draws the polygon
	}		

    glEnd();


	// drawing the black wind screen
 	glBegin(GL_POLYGON);  

 	glColor3f(0.1f,0.1f,0.1f);  // black color
 	glVertex2i(car_points[5].F+offset,car_points[5].S);
 	glVertex2i(car_points[5].F+offset,car_points[5].S-15);
 	glVertex2i(car_points[5].F+offset+10,car_points[3].S);
 	glVertex2i(car_points[3].F+offset,car_points[3].S);
 	glVertex2i(car_points[4].F+offset,car_points[4].S);

 	glEnd();

}
void draw_circle1()
{
	float theta;
		glBegin(GL_POLYGON);
		glColor3f(0.3f,0.3f,0.3f);
		for(int j=0;j<360;j++)
		{
			theta=j*3.14/180;
			glVertex2f(offset+50+15*cos(theta),20+15*sin(theta));// draw wheel of radius 15
		}
		glEnd();
}
void draw_circle2()
{
	float theta;
		glBegin(GL_POLYGON);
		glColor3f(0.3f,0.3f,0.3f);
		for(int j=0;j<360;j++)
		{
			theta=j*3.14/180;
			glVertex2f(offset+125+15*cos(theta),20+15*sin(theta));// draw wheel of radius 15
		}
		glEnd();
}
void sun()
{
	float theta;
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,0.0);
		for(int j=0;j<360;j++)
		{
			theta=j*3.14/180;
			glVertex2f(500+50*cos(theta),500+50*sin(theta));// draw sun
		}
		glEnd();
}
void bush1() // draw a push
{
	float theta;
		glBegin(GL_POLYGON);
		glColor3f(0.0,1.0,0.0);
		for(int j=0;j<360;j++)
		{
			theta=j*3.14/180;
			glVertex2f(100+50*cos(theta),80+50*sin(theta));
		}
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.0,1.0,0.0);
		for(int j=0;j<360;j++)
		{
			theta=j*3.14/180;
			glVertex2f(170+50*cos(theta),80+50*sin(theta));
		}
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.0,1.0,0.0);
		for(int j=0;j<360;j++)
		{
			theta=j*3.14/180;
			glVertex2f(135+50*cos(theta),110+50*sin(theta));
		}
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.0,1.0,0.0);
		for(int j=0;j<360;j++)
		{
			theta=j*3.14/180;
			glVertex2f(200+50*cos(theta),80+50*sin(theta));
		}
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.0,1.0,0.0);
		for(int j=0;j<360;j++)
		{
			theta=j*3.14/180;
			glVertex2f(270+50*cos(theta),80+50*sin(theta));
		}
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.0,1.0,0.0);
		for(int j=0;j<360;j++)
		{
			theta=j*3.14/180;
			glVertex2f(235+50*cos(theta),110+50*sin(theta));
		}
		glEnd();
}

void bush2() // draw a bush
{
	float theta;
		glBegin(GL_POLYGON);
		glColor3f(0.0,1.0,0.0);
		for(int j=0;j<360;j++)
		{
			theta=j*3.14/180;
			glVertex2f(900+50*cos(theta),80+50*sin(theta));
		}
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.0,1.0,0.0);
		for(int j=0;j<360;j++)
		{
			theta=j*3.14/180;
			glVertex2f(970+50*cos(theta),80+50*sin(theta));
		}
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.0,1.0,0.0);
		for(int j=0;j<360;j++)
		{
			theta=j*3.14/180;
			glVertex2f(935+50*cos(theta),110+50*sin(theta));
		}
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.0,1.0,0.0);
		for(int j=0;j<360;j++)
		{
			theta=j*3.14/180;
			glVertex2f(1000+50*cos(theta),80+50*sin(theta));
		}
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.0,1.0,0.0);
		for(int j=0;j<360;j++)
		{
			theta=j*3.14/180;
			glVertex2f(1070+50*cos(theta),80+50*sin(theta));
		}
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.0,1.0,0.0);
		for(int j=0;j<360;j++)
		{
			theta=j*3.14/180;
			glVertex2f(1035+50*cos(theta),110+50*sin(theta));
		}
		glEnd();
}


void show_tlight(){

	// our function that draws the traffic light

	glBegin(GL_POLYGON); // this draws grey background

	glColor3f(0.3,0.3,0.3); // grey color
	glVertex2i(light_x-10,light_y-10);
	glVertex2i(light_x+240,light_y-10);
	glVertex2i(light_x+240,light_y+60);
	glVertex2i(light_x-10,light_y+60);

	glEnd();

	glBegin(GL_POLYGON);  // red light

	glColor3f(1,0,0); // red color
	glVertex2i(light_x,light_y);
	glVertex2i(light_x+70,light_y);
	glVertex2i(light_x+70,light_y+50);
	glVertex2i(light_x,light_y+50);
	glEnd();

	glBegin(GL_POLYGON); //yellow light

	glColor3f(0.97,0.92,0.4); // yellow color
	glVertex2i(light_x+80,light_y);
	glVertex2i(light_x+150,light_y);
	glVertex2i(light_x+150,light_y+50);
	glVertex2i(light_x+80,light_y+50);
	glEnd();

	glBegin(GL_POLYGON); //green light

	glColor3f(0,1,0); //green color
	glVertex2i(light_x+160,light_y);
	glVertex2i(light_x+230,light_y);
	glVertex2i(light_x+230,light_y+50);
	glVertex2i(light_x+160,light_y+50);
	glEnd();
}

void display(void){

	// main display callback function

	glClear(GL_COLOR_BUFFER_BIT ); // clearing previous buffer
	bush1();
	bush2();
	road();
	
	draw_car();   // drawing the car

	draw_circle1();  //drawing the circle1

	draw_circle2();  //drawing the circle2
	
	sun();
  
	if(show_light && light_done == false)show_tlight();  // logic wheather to show traffic light

 	glClearColor(0.1f, 0.1f, 0.3f, 0.4f);   

	

	glutSwapBuffers();  // swapping the buffers

	system("sleep 0.008");  // this is done to get smooth animation not fast nor slow
}

void keyboard(unsigned char key ,int x,int y){

	// this is our main keyboard callback function

	if(key == 13)cout<<endl;  // when enter key is pressed

	else if(key !=27 ) cout<<key;  // normal key

	if(key == 27)exit(0);  // when escape key is pressed

	else if(key == 13 && show_light == true && light_done == false ){  // case when traffic light is on

		if(keyborad_choice == "red" ){ // when choice is red

			system("sleep 2");
		}

		else if(keyborad_choice == "yellow" ){ // when choice is yelloe

			system("sleep 2");  // waiting time for yellow

			light_done = true;
		}

		else if(keyborad_choice == "green"){ // when green is selected

			cout<<"@ green"<<endl;

			light_done = true;
		}

		keyborad_choice = "";  // resetting the choice
	}

	else keyborad_choice.push_back(key); // accumlating the keys to foarm a string

}


void signal(){

	// it checks wether mouse click is valid or not

	if(mouse_y1 > 100 || mouse_y2 > 100 ){ // case when click is  up of signel

		return ;
	}

	if(mouse_y1 < 50 || mouse_y2 < 50 ){ // case when click is on bottom of signel

		return ;
	}

	if(mouse_x1 > 1505 || mouse_x2 > 1505 ){  // case when click is on right of signel

		return ;
	}

	if(mouse_x1 < 1275 || mouse_x2 < 1275 ){ // case when click is on left of signel

		return ;
	}

	if( mouse_x2 < 1345 && mouse_x1 < 1345 ){ // when  red is clicked

		cout<<"attempted red"<<endl;

		system("sleep 2");

		
	}

	if( mouse_x2 < 1425 && mouse_x2 > 1355 && mouse_x1 < 1425 && mouse_x1 > 1355  ){ // when choice is yellow

		cout<<"attempted yellow"<<endl;

		system("sleep 2"); // waiting time

		light_done = true;
		glutPostRedisplay();

	}

	if( mouse_x2 > 1435 && mouse_x1 > 1435 ){ // when green is clicked

		cout<<"attempted green"<<endl;

		light_done = true;
		glutPostRedisplay();

	}
		

	cout<<"@ signal() "<<mouse_x1<<" "<<mouse_y1<<" "<<mouse_x2<<" "<<mouse_y2<<endl;
	
	
}

void mouse(int button,int state,int x,int y){

	// our main mouse callback function

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) // when key is just pressed
	{
	    mouse_x1 = x;
	    mouse_y1 = y;
    } 
    else if(button == GLUT_LEFT_BUTTON && state == GLUT_UP) // when key is just released
    {
        mouse_x2 = x;
	    mouse_y2 = y;

	    if(show_light)signal(); // check weather the click is valid or not and take appt action

    }

    
}

void special(int key,int x,int y){

	// cout main special key callback funtion

	cout<<"@ special() "<<(int)key<<endl;

	if( key ==102 && show_light == true && light_done == false )light_done = true; // when arrow right -> is pressed

}


int main(int argc,char **argv){

	// our main

	cout<<"@ Main() "<<endl;
		
	glutInit( &argc, argv );

	cout<<"glut initalized "<<endl;

	init_para();              // call to set all the constants

	glutCreateWindow("CAR_AND_TRAFFIC_LIGHT"); // naming of the window

	int sub=glutCreateMenu(GoMenu);
	glutAddMenuEntry("Red",1);
	glutAddMenuEntry("Yellow",2);
	glutAddMenuEntry("Green",3);
	glutCreateMenu(GoMenu);
	glutAddSubMenu("Color",sub);
	glutAddMenuEntry("Exit",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(display); // linking display function

	glutKeyboardFunc(keyboard); // linking keyboard function

	glutIdleFunc(do_animation);  // linking idle function

	glutMouseFunc(mouse);      // linking mouse function

	glutSpecialFunc(special);  // linking special function

	init();					// call to set ortho and clear buffer

	glutMainLoop(); // glut inf loop()

	return 0;
}
