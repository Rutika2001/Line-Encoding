#include<iostream>
#include<graphics.h>
#include<math.h>
#include <iomanip>
#define width 50
int n;
using namespace std;

void convert_to_binary(int n,int *arr);
void draw_axes();
int *getDetails();
//----------------------------------------------------------------------------------

void draw_axes1()
{
    setlinestyle(0, 0, 1);
    //setcolor(WHITE);
    line(100,0,100,getmaxy());                     //y axis
    line(0,getmaxy()-320,getmaxx(),getmaxy()-320); //upper x axis
    line(0,getmaxy()-100,getmaxx(),getmaxy()-100);  //lower x axis
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
}
void draw_axes()
{
  setlinestyle(0, 0, 1);
  setcolor(WHITE);
  line(100,0,100,getmaxy()); //y-axis
  settextstyle(BOLD_FONT, HORIZ_DIR, 2);
  line(0,getmaxy()/2+100,getmaxx(),getmaxy()/2+100); // x-axis
}
//-----------------------------------------------------------------------------------
int *getDetails()
{
    static int arr[8];
    int i;
    int n;
    printf("  Enter data to be presented (0 to 255)  : ");

    scanf("%d",&n);

    convert_to_binary(n,arr);
    return arr;
}
//------------------------------------------------------------------------------------
void convert_to_binary(int n,int *arr)
{
    int i = 7;
    while(i >= 0)
    {
        arr[i]=(n%2);
        n=n/2;
        i--;
    }
}

void show_input(int *arr)
{
     //settextstyle(0, VERT_DIR, 1.5);
    //outtextxy(50,10,"Binary Representation");
    setlinestyle(0, 0, 1);
    int x0=100, y0=getmaxy()-320,height=60;
    int i,amp = 0;
    settextstyle(0, HORIZ_DIR, 1);
    for(i=0; i<8 ;i++)
    { setlinestyle(0, 0, 1);
        if(arr[i] == 0)
        {
            outtextxy(x0+20,40,"0");
            setcolor(YELLOW);
            line(x0,y0,x0+width,y0);
            x0=x0+width;
            setcolor(WHITE);
            //line(x0,y0+3,x0,y0-3);

        }
        if(arr[i] == 1)
        {
            outtextxy(x0+20,40,"1");
            setcolor(YELLOW);
            if(arr[i-1] == 0 && i>0)
            {
              //setcolor(BLUE);      remove comment
              line(x0,y0,x0,y0-height);
            }

            line(x0,y0-height,x0+width,y0-height);     // upper horizontal line 1111
            if((arr[i+1] == 0 )){
                //setcolor(RED);      remove comment
              line(x0+width,y0,x0+width,y0-height);
            }

            x0=x0+width;
            setcolor(WHITE);
            //line(x0,y0+3,x0,y0-3);


        }
        setcolor(WHITE);
      circle(x0,getmaxy()/2+135,2);
      setlinestyle(4, 0, 1);

    line(x0,y0+300,x0,y0-100);      //vertical dotted lines
    }
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);

}

//--------------------------------Manchester-Diff_Manchester-------------------------------
void manchester(int *arr)
{

   int offset=n+60;
   int gd=DETECT,gm;
   initgraph(&gd,&gm,NULL);
   draw_axes1();
   setcolor(WHITE);

   outtextxy(450,30,"Manchester");
   outtextxy(450,250,"Diff-Manchester");
   int amp=35;
   int x0=100;

   for(int i=1;i<9;i++)
   {
      setlinestyle(0, 0, 1);
      settextstyle(0, HORIZ_DIR, 1);
      if(arr[i-1]==0)
      {

         outtextxy(x0+20,120-amp-30,"0");

         setcolor(YELLOW);
         line(x0,150-amp,x0+(width/2),150-amp);//create horizontal line
         line(x0+(width/2),150-amp,x0+(width/2),150+amp);     //vertical line
         line(x0+(width/2),150+amp,x0+width,150+amp);        //___
      }
      if (arr[i-1]==1)
      {

         outtextxy(x0+20,120-amp-30,"1");

         line(x0,150+amp,x0+(width/2),150+amp);
         line(x0+(width/2),150+amp,x0+(width/2),150-amp);
         line(x0+(width/2),150-amp,x0+width,150-amp);
      }

      x0=x0+width;
      if(arr[i-1]==arr[i])
      {
         //setcolor(RED);
         line(x0,150+amp,x0,150-amp);

      }
      setcolor(WHITE);
      setlinestyle(4, 0, 1);
      line(x0,getmaxy()/2+200,x0,getmaxy()/2-170);

   }

   /*------Differential manchester-------*/
   x0=100;
   int y0=getmaxy()-offset-45,state=1;
   for(int i=1;i<9;i++)
   {
      setlinestyle(0, 0, 1);
      if(arr[i-1]==0)
      {
            setcolor(YELLOW);
         //outtextxy(x0,150-amp-25,"0");

         line(x0,y0-amp,x0+(width/2),y0-amp);//create horizontal line
         line(x0+(width/2),y0-amp,x0+(width/2),y0+amp);
         line(x0+(width/2),y0+amp,x0+width,y0+amp);
      }
      else if (arr[i-1]==1)
      {
         setcolor(WHITE);
         setlinestyle(0, 0, 1);
         line(x0,y0+amp,x0+(width),y0+amp);
      }


      if(arr[i]==0 && arr[i-1]==1)
          line(x0+width,y0+amp,x0+width,y0-amp);
      if (arr[i]==0 && arr[i-1]==0)
          line(x0+width,y0+amp,x0+width,y0-amp);
      x0=x0+width;
   }
   //setlinestyle(3,0,1);
   getch();
    closegraph();


}
//--------------------------------------Unipolar_NRZ---------------------------------
void Unipolar_NRZ(int *a)
{

  int gd=DETECT,gm;
  initgraph(&gd,&gm,NULL);
  //initwindow(800, 800);
  int i;
  draw_axes();
  outtextxy(450,40,"Unipolar-NRZ");
  int x0=100,y0=getmaxy()/2;

  for(i=0;i<8 ;i++)

  {
     settextstyle(0, HORIZ_DIR, 1);
     if(a[i]==1)
        {

           outtextxy(x0+20,140,"1");
           setcolor(YELLOW);
           setlinestyle(0, 0, 1);
           line(x0,y0+10,x0+width,y0+10);
           x0=x0+width;
        }
      if(a[i]==0)
      {
         outtextxy(x0+20,140,"0");
         setcolor(YELLOW);
         setlinestyle(0, 0, 1);
         line(x0,y0+100,x0+width,y0+100);
         x0=x0+width;
      }

      if(i!=0 && a[i]!=a[i-1])
      {
          setcolor(WHITE);       //vertical lines
          setlinestyle(0, 0, 1);
          line(x0-width,y0+100,x0-width,y0+10);

      }
      setcolor(WHITE);
      circle(x0,getmaxy()/2+100,2);       //small circles on x axis
      setlinestyle(4, 0, 1);
      line(x0,y0+300,x0,y0-100);  //vertical dotted lines
  }
    getch();
    closegraph();


}
//-------------------------------NRZ-LEVEL-------------------------------
void NRZ_L(int *a)
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    int i;
    show_input(a);
    draw_axes1();

    //settextstyle(0, VERT_DIR, 1);
    outtextxy(550,250,"NRZ-L");
    int x0=100,y0=getmaxy()+50;

    for(i=0;i<8;i++)
    {
       settextstyle(0, HORIZ_DIR, 1);
       if(a[i]==1)
          {

             setcolor(GREEN);
             setlinestyle(0, 0, 1);
             line(x0,y0/2+160,x0+width,y0/2+160);
             x0=x0+width;
          }
        if(a[i]==0)
        {

           setcolor(GREEN);
           setlinestyle(0, 0, 1);
           line(x0,y0-200,x0+width,y0-200);
           x0=x0+width;
        }

        if(i!=0 && a[i]!=a[i-1])
        {

            setcolor(WHITE);
            setlinestyle(0, 0, 1);
            line(x0-width,y0/2+160,x0-width,y0-200);

        }
    }
    getch();
    closegraph();

}

//-------------------------------------------MLT-3--------------------------------------

MLT_3(int *arr)
{

  int gd=DETECT,gm;
  initgraph(&gd,&gm,NULL);
  show_input(arr);
  draw_axes1();
  outtextxy(550,200,"MLT-3");
  settextstyle(0, HORIZ_DIR, 1);
  int x0=100, y0=getmaxy()-100,height=60;
  int i,amp = 0,prev_amp = 0,prev_prev_amp = -1*height;
    for(i=0; i<=7 && x0<getmaxx(); i++)
    {
        setlinestyle(0, 0, 1);

        if(arr[i] == 0)
        {

             setcolor(GREEN);
            if(amp == height || amp == -1*height)
            {
                if(arr[i+1] == 1)
                    line(x0+width,y0,x0+width,y0-amp);
            }
            line(x0,y0-amp,x0+width,y0-amp);
            x0=x0+width;
            setcolor(WHITE);
            line(x0,y0+3,x0,y0-3);
        }
        if(arr[i] == 1)
        {

            if(prev_amp == 0 && prev_prev_amp == -1*height)
            {
                amp = prev_amp + height;
                prev_prev_amp = prev_amp;
                prev_amp = amp;
            }
            else if(prev_amp == 0 && prev_prev_amp == height)
            {
                amp = prev_amp - height;
                prev_prev_amp = prev_amp;
                prev_amp = amp;
            }
            else if(prev_amp == height || prev_amp == -1*height)
            {
                amp = 0;
                prev_prev_amp = prev_amp;
                prev_amp = amp;
            }
            setcolor(GREEN);
            if(amp == height || amp == -1*height)
            {
                if(arr[i+1] == 1)

                    line(x0+width,y0,x0+width,y0-amp);
            }
           line(x0,y0,x0,y0-amp);

           line(x0,y0-amp,x0+width,y0-amp);

            x0=x0+width;
            setcolor(WHITE);
            line(x0,y0+3,x0,y0-3);
        }
    }

 getch();
    closegraph();


}

//-------------------------------------------AMI------------------------------------------

void AMI(int *a,int value)
{
  int flag=0,i;
  int gd=DETECT,gm;
  initgraph(&gd,&gm,NULL);

  show_input(a);
  draw_axes1();
  int x0=100,y0=getmaxy()/2+34;
  if(value==1)
    outtextxy(550,200,"AMI");
  else
    outtextxy(450,200,"Pseudoternary");
  for(i=0;i<8 && x0<getmaxx();i++)

  {
    setcolor(WHITE);
    setlinestyle(0, 0, 1);
     if(a[i]==value && flag==0)
        {  flag=1;
           setcolor(GREEN);
           line(x0,y0+50,x0+width,y0+50);
           setcolor(WHITE);

           line(x0+width,y0+50,x0+width,y0+100);

           line(x0,y0+50,x0,y0+100);
           x0=x0+width;
        }
      else if (a[i]==value && flag==1)
      {
           setcolor(GREEN);
           line(x0,y0+150,x0+width,y0+150);
           setcolor(WHITE);
           x0=x0+width;
           line(x0-width,y0+100,x0-width,y0+150);
           line(x0,y0+100,x0,y0+150);
           flag=0;
      }
      if (a[i]==!value)
      {
        setcolor(GREEN);
        line(x0+width,y0+100,x0,y0+100);
         x0=x0+width;
      }


  }
  getch();
    closegraph();

}

//--------------------------------------------------------------------------------------
int main()
{
  int choice;
  char ch;
  do{
  system("CLS");          //clear screen
  cout<<setw(80)<<"Line Encoding Scheme implementation using c++"<<endl;
  cout<<setw(80)<<"---------------------------------------------"<<endl<<endl;
  cout<<"** LIST OF LINE ENCODING SCHEME ** "<<endl<<endl;
  cout<<"  1.Unipolar NRZ \n\n  2.Polar NRZ-L \n\n";
  cout<<"  3.Bi-phase : Manchester and Differntial Manchester \n\n  4.MLT-3 \n\n  5.AMI \n\n  6.Pseudoternary"<<endl<<endl;
  cout<<"  Enter Your choice : ";
  cin>>choice;
  if(choice>6)
  {
    cout<<"WRONG CHOICE";
    exit(0);
  }


  int *arr,i;
  arr=getDetails();

//--------------------------------------------------------------------------------------


  switch(choice)
  {

  case 1:
  Unipolar_NRZ(arr);
    break;

  case 2:
    NRZ_L(arr);
    break;

  case 3:
     manchester(arr);
     break;

  case 4:
    MLT_3(arr);
    break;

  case 5:
    AMI(arr,1);
    break;

  case 6:
    AMI(arr,0);
    break;
  default:
    break;

   }
   cout<<endl<<"  ----------------------------"<<endl;
   cout<<"  Do you want to continue?...(Y or N) ";
   cin>>ch;
  } while(ch=='Y'|| ch=='y');

}

