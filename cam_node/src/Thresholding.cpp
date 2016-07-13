/*
*********************************************************
*							*
*	Author :  Aniket : IvLabs                       *
*                 Radha                                 *
*							*
*********************************************************
*/

#include "Thresholding.h"

Thresholding::Thresholding(Mat diff_blue,Mat diff_green,Mat diff_red,Mat gray,int value)
       {
        setName(diff_blue,diff_green,diff_red,gray,value);
       }

void Thresholding::setName(Mat diff_blue,Mat diff_green,Mat diff_red,Mat gray,int value)
     {
        flag = value;
     /*  if(value==1)
          threshold_blue=threshold_blue=diff_blue > 29 & diff_blue < 155 & diff_green > 0 & diff_green < 140 &diff_red> 0 & diff_red< 130;
       else if(value==2)
          threshold_yellow=diff_blue > 0 & diff_blue < 20 & diff_green > 54 & diff_green < 144 & diff_red> 7 & diff_red < 52;
       else
          threshold_red=diff_blue > 0 & diff_blue < 30 & diff_green > 0 & diff_green < 30 & diff_red>75 & diff_red < 210;         
     */
       if(value==1)
        {
        threshold_blue=(diff_blue)- gray ;
	GaussianBlur(threshold_blue,threshold_blue,Size(5,5),0) ;
	threshold(threshold_blue,threshold_blue,0,255,CV_THRESH_BINARY | CV_THRESH_OTSU);
        }
       if(value==3)
        {
        threshold_red=(diff_red)- gray ;
	GaussianBlur(threshold_red,threshold_red,Size(5,5),0) ;
	threshold(threshold_red,threshold_red,0,255,CV_THRESH_BINARY | CV_THRESH_OTSU);
        }
         
     } 
Mat Thresholding::getName()
    {
     	if (flag ==1 )
          return threshold_blue;
        else if (flag ==2)
          return threshold_yellow;
        else if (flag ==3)
          return threshold_red;
    }
